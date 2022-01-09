void detect_front() {
  servo.write(90);//look forward
  delay(750);
  int distance = getDistance();
  
  if (distance >= stopDist)
  {
    moveForward();
    delay(500);
  }
  while (distance >= stopDist)
  {
    distance = getDistance();
    delay(250);
    moveForward();
  }
  stopMove();
}
