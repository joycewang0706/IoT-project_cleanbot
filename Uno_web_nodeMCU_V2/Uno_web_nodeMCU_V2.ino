//UNo side
#include <Wire.h>
/*
  Master Device: NodeMCU
  Slave Device: Arduino Uno
  Slave Device Address: 8
*/
#include <NewPing.h>
#include <Servo.h>
#include <AFMotor.h>

//variable for the data from NODEMCU
char c;
String dataIn;
int8_t indexOfA, indexOfB, indexOfC;
String obstacle_car, wifiStrength, pointer_car;

/*wifi signal side*/
int signal_dBM[] = { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int signal_percent[] = {0, 0, 0, 0, 0, 0, 4, 6, 8, 11, 13, 15, 17, 19, 21, 23, 26, 28, 30, 32, 34, 35, 37, 39, 41, 43, 45, 46, 48, 50, 52, 53, 55, 56, 58, 59, 61, 62, 64, 65, 67, 68, 69, 71, 72, 73, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 90, 91, 92, 93, 93, 94, 95, 95, 96, 96, 97, 97, 98, 98, 99, 99, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
int strength = 0;
int percentage = 0;

/*ultrasonic*/
#define trig A2
#define echo A0
int maxDist = 200;
int stopDist = 50;
float timeOut = 2 * (maxDist + 10) / 100 / 340 * 1000000;
/*
  0 degree = right
  90 degree = lookforward
  115 degree = left front
  180 degree = left
*/
NewPing sonar(trig, echo, maxDist);

/*servo motor*/
Servo servo;

/*car control*/
AF_DCMotor RightBack(1); //M1
AF_DCMotor RightFront(2); //M2
AF_DCMotor LeftFront(3); //M3
AF_DCMotor LeftBack(4); //M4

int motorSpeed = 65;
int motorOffset = 10;
int turnSpeed = 50;
int Rfspeed = 10;
int leftplus = 40;
int leftBackplus = 80;
//調線路circuit
//調成負的

void setup() {
  /* join i2c bus with address 8 */
  Wire.begin(8);
  /* register receive event */
  Wire.onReceive(receiveEvent);
  delay(500);


  //motor speed
  RightBack.setSpeed(motorSpeed + leftplus);//55+40=95
  RightFront.setSpeed(Rfspeed);//10;
  LeftFront.setSpeed(motorSpeed + leftplus);//55+40=95
  LeftBack.setSpeed(motorSpeed + leftBackplus);//55+80=135

  //init stop
  RightBack.run(RELEASE);
  RightFront.run(RELEASE);
  LeftFront.run(RELEASE);
  LeftBack.run(RELEASE);

  //ultrasonic
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  //servo
  servo.attach(9);
  servo.write(115);
  delay(2000);

  Serial.begin(115200);
}

void loop() {
  Serial.println(obstacle_car);
  if (obstacle_car == "on" ) {
    do {
      obstacle_avoide_car();
    } while (obstacle_car == "off");

    Blank();

  } else if (pointer_car == "on" ) {
    do {
      pointerCAR();
    } while (pointer_car == "off" );

    Blank();
  } else {
    Blank();
    delay(1000);
  }

}
