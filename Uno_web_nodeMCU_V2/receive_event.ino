void receiveEvent(int howMany)
{
  while (0 < Wire.available())
  {
    c = Wire.read(); /* receive byte as a character */

    if (c == '\n')
    {
      break;
    }
    else
    {
      dataIn += c;
    }
  }
  if (c == '\n')
  {
    Parse_the_Data();
    //Reset the variable
    c = 0;
    dataIn = "";
  }

  Serial.println(); /* to newline */
}
void Parse_the_Data()
{
  Serial.println(dataIn);
  indexOfA = dataIn.indexOf("A");
  indexOfB = dataIn.indexOf("B");
  indexOfC = dataIn.indexOf("C");

  obstacle_car = dataIn.substring(0, indexOfA);
  wifiStrength = dataIn.substring(indexOfA + 1, indexOfB);
  pointer_car = dataIn.substring(indexOfB + 1, indexOfC);
}
