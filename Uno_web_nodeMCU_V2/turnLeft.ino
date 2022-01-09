void turnLeft(int duration) //Set motors to turn left for the specified duration then stop
{

  RightBack.setSpeed(motorSpeed + turnSpeed); //55+50=105
  RightFront.setSpeed(Rfspeed);//10
  LeftFront.setSpeed(motorSpeed + motorOffset + turnSpeed);//55+10+50=115
  LeftBack.setSpeed(motorSpeed + motorOffset + turnSpeed);//55+10+50=115

  //right go forward
  //left go backward
  RightBack.run(FORWARD);
  RightFront.run(FORWARD);
  LeftFront.run(BACKWARD);
  LeftBack.run(BACKWARD);
  delay(duration);
  //  RightBack.setSpeed(motorSpeed); //55
  //  RightFront.setSpeed(Rfspeed);//10
  //  LeftFront.setSpeed(motorSpeed + motorOffset);//55+10=65
  //  LeftBack.setSpeed(motorSpeed + motorOffset);//55+10=65
  RightBack.setSpeed(motorSpeed + leftplus);//55+40=95
  RightFront.setSpeed(Rfspeed);//10;
  LeftFront.setSpeed(motorSpeed + leftplus);//55+40=95
  LeftBack.setSpeed(motorSpeed + leftBackplus);//55+80=135
  RightBack.run(RELEASE);
  RightFront.run(RELEASE);
  LeftFront.run(RELEASE);
  LeftBack.run(RELEASE);
}
