int getWIFIsignal()
{
  strength = wifiStrength.toInt();
  for (int x = 0; x < 100; x++)
  {
    if (signal_dBM[x] == strength)
    {
      //print the received signal strength in percentage
      percentage = signal_percent[x];

      //Serial.print(percentage);
      //Serial.println("%");
      delay(1000);
      break;
    }
  }
  return percentage;
}
