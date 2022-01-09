
//nodeMcu side code

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <Wire.h>
/*
  NodeMcu as web server
  as Master device
  detect hotspot signal pass it to Uno slave
*/

/*web side*/
const char *ssid = "red-210";
const char *password = "9il0zquz";
//set web server port number to 80
WiFiServer server(80);



//Variable to store the HTTP request
String header;
//Auxiliar variables to store the current output state
String outputState = "off";
String outputState_pointer = "off";

//Current time
unsigned long currentTime = millis();
//Previous time
unsigned long previousTime = 0;
//Define timeout time in milliseconds(ex:2000ms =2s)
const long timeoutTime = 2000;

/*wifi signal side*/
int strength = 0;
String hotspot = "Bowling";

void setup()
{
  Serial.begin(115200);
  
  //NodeMcu send data to Uno
  // join i2c bus with SDA=D1 and SCL=D2 of NodeMCU
  Wire.begin(D1, D2);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  //Connect to Wifi with SSID and password
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  delay(500);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  //Print local IP address and start web server
  Serial.println("");
  Serial.println("wifi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  delay(200);
  Serial.println("Server started");
}

void loop()
{

  int wifiStrength = Scan();
  // Wait a bit before scanning again
  //delay(1000); //original 5s

  SenddataUno(wifiStrength);

  //server傳回值由avilable 取得
  WiFiClient client = server.available();

  // If a new client connects,
  // print a message out in the serial port
  // make a String to hold incoming data from the client
  if (client)
  {
    Serial.println("New Client.");
    //清空這行的內容
    String currentLine = "";
    currentTime = millis();
    previousTime = currentTime;
    // loop while the client's connected
    while (client.connected() && currentTime - previousTime <= timeoutTime)
    {
      currentTime = millis();
      //假使從client有讀到字元
      if (client.available())
      {
        //讀取這個字元
        char c = client.read();
        Serial.write(c);
        header += c;
        //如果是換行符號
        if (c == '\n')
        {
          //假使目前的一行是空白且有新的一行，結束http 的requests
          if (currentLine.length() == 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("connection: close");
            client.println();

            //turns the GPIOs on and off
            
            if (header.indexOf("GET /2/on") >= 0)
            {
              outputState = "on";
            }
            else if (header.indexOf("GET /2/off") >= 0)
            {
              outputState = "off";
            }
            if (header.indexOf("GET /3/on") >= 0)
            {
              outputState_pointer = "on";
            }
            else if (header.indexOf("GET /3/off") >= 0)
            {
              outputState_pointer = "off";
            }


            //Display HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            //CSS style
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}");
            client.println(".pointer2 {background-color: #77878A;}</style></head>");

            //html header
            client.println("<body><h1>Car</h1>");
            //display current state
            client.println("<p>obstacle Car - State " + outputState + "</p>");

            if (outputState == "off")
            {
              client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            }
            else
            {
              client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>pointer Car - State " + outputState_pointer + "</p>");
            if (outputState_pointer == "off")
            {
              client.println("<p><a href=\"/3/on\"><button class=\"button pointer\">ON</button></a></p>");
            }
            else
            {
              client.println("<p><a href=\"/3/off\"><button class=\"button pointer2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
            //使用空白行結束http回應
            client.println();

            break;
          }
          else
          {
            //假使有新的一行清除該行
            currentLine = "";
          }
        }
        else if (c != '\r')
        {
          //讀取到不是換行符號，增加新字元

          currentLine += c;
        }
      }
    }
    //清除標頭
    header = "";
    //close connection
    client.stop();
    Serial.println("Client disconnect.");
    Serial.println("");
  }
}
