void moveBackward(int duration) {
  RightBack.run(BACKWARD);
  RightFront.run(BACKWARD);
  LeftFront.run(BACKWARD);
  LeftBack.run(BACKWARD);
  delay(duration/2);
  RightBack.run(BACKWARD);
  RightFront.run(RELEASE);
  LeftFront.run(BACKWARD);
  LeftBack.run(BACKWARD);
  delay(duration/2);
}
