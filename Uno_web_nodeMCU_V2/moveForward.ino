void moveForward()
{
  RightBack.run(FORWARD);
  RightFront.run(FORWARD);
  LeftFront.run(FORWARD);
  LeftBack.run(FORWARD);
  delay(500);
  RightBack.run(FORWARD);
  RightFront.run(RELEASE);
  LeftFront.run(FORWARD);
  LeftBack.run(FORWARD);
  delay(500);
}
