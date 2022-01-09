void obstacle_avoide_car() {

  detect_front();

  stopMove();

  int turnDir = checkDirection();
  //Serial.print("turnDir:");
  //Serial.println(turnDir);
  switch (turnDir)
  {
    case 0:
      turnLeft(400);
      break;
    case 1:
      turnLeft(900);
      break;
    case 2:
      turnRight(400);
      break;
  }

}


int getDistance() //Measure the distance to an object
{
  unsigned long pulseTime;  //Create a variable to store the pulse travel time
  int distance;             //Create a variable to store the calculated distance
  digitalWrite(trig, HIGH); //Generate a 10 microsecond pulse
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pulseTime = pulseIn(echo, HIGH, timeOut);      //Measure the time for the pulse to return
  distance = (float)pulseTime * 340 / 2 / 10000; //Calculate the object distance based on the pulse time
  return distance;
}

int checkDirection() //Check the left and right directions and decide which way to turn
{
  int distances[2] = {0, 0}; //Left and right distances
  int turnDir = 1;           //Direction to turn, 0 left, 1 reverse, 2 right
  servo.write(180);          //Turn servo to look left
  delay(800);
  distances[0] = getDistance(); //Get the left object distance
  servo.write(0);               //Turn servo to look right
  delay(1000);
  distances[1] = getDistance();                   //Get the right object distance
  if (distances[0] >= 200 && distances[1] >= 200) //If both directions are clear, turn left
    turnDir = 0;
  else if (distances[0] <= stopDist && distances[1] <= stopDist) //If both directions are blocked, turn around
    turnDir = 1;
  else if (distances[0] >= distances[1]) //If left has more space, turn left
    turnDir = 0;
  else if (distances[0] < distances[1]) //If right has more space, turn right
    turnDir = 2;
  return turnDir;
}
