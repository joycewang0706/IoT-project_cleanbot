void pointerCAR() {
  //before and after wifi strength
  int stren[2] = {0, 0};

  //RSSI turn in to percentage
  int strenWiFi = getWIFIsignal();

  //original place wifi strength
  stren[0] = strenWiFi;
  delay(100);

  //wifi strentgh <=85 walk randomly to test
  if (stren[0] <= 85)
  {
    detect_front();
    stopMove();

    int turnDir = checkDirection();

    switch (turnDir)
    {
      case 0:
        turnLeft(400);

        strenWiFi = getWIFIsignal();
        delay(500);
        //after wifi strength
        stren[1] = strenWiFi;
        //if original place wifi signal larger than this place
        if (stren[0] >= stren[1])
        {
          //reverse
          turnLeft(700);
        }
        //靠近 繞圈圈
        break;
      case 1:
        turnLeft(700);
        break;
      case 2:
        turnRight(400);
        strenWiFi = getWIFIsignal();
        delay(500);
        //after wifi strength
        stren[1] = strenWiFi;
        if (stren[0] >= stren[1])
        {
          //reverse
          turnLeft(700);
        }
        break;

    }
  } else {

    //count the forward time inorder to get back to the original decision
    unsigned long start = micros();
    detect_front();
    unsigned long end = micros();
    stopMove();
    stren[1] = strenWiFi;
    if (stren[0] >= stren[1]) {
      float temp = (float)(end - start);
      int duration = (int)temp / 1000;
      moveBackward(duration);
    } else {
      //more closer location store in stren[0]
      stren[0] = stren[1];
    }

    

    int turnDir = checkDirection();
    switch (turnDir)
    {
      case 0:
        turnLeft(400);

        strenWiFi = getWIFIsignal();
        delay(50);
        //after wifi strength
        stren[1] = strenWiFi;
        //if original place wifi signal larger than this place
        if (stren[0] >= stren[1])
        {
          //reverse
          turnLeft(700);
        }
        //靠近 繞圈圈
        break;
      case 1:
        turnLeft(700);
        break;
      case 2:
        turnRight(400);
        if (stren[0] >= stren[1])
        {
          //reverse
          turnLeft(700);
        }
//      case 3:
//        turnLeft(400);
//        strenWiFi = getWIFIsignal();
//        delay(50);
//        //after wifi strength
//        stren[1] = strenWiFi;
//        //if original place wifi signal larger than this place
//        if (stren[0] >= stren[1])
//        {
//          turnRight(300);
//        }
//        break;
    }


  }
}
