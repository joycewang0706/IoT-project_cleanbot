void turnRight(int duration) //Set motors to turn left for the specified duration then stop
{

  RightBack.setSpeed(motorSpeed + turnSpeed); //55+50=105
  RightFront.setSpeed(Rfspeed);//10
  LeftFront.setSpeed(motorSpeed +turnSpeed+leftplus);//55+50+40=145
  LeftBack.setSpeed(motorSpeed + motorOffset + turnSpeed+leftplus);//55+10+50+40=155
  RightBack.run(BACKWARD);
  RightFront.run(BACKWARD);
  LeftFront.run(FORWARD);
  LeftBack.run(FORWARD);
  delay(duration);
  RightBack.setSpeed(motorSpeed + leftplus);//55+40=95
  RightFront.setSpeed(Rfspeed);//10;
  LeftFront.setSpeed(motorSpeed + leftplus);//55+40=95
  LeftBack.setSpeed(motorSpeed + leftBackplus);//55+80=135
  RightBack.run(RELEASE);
  RightFront.run(RELEASE);
  LeftFront.run(RELEASE);
  LeftBack.run(RELEASE);
}
