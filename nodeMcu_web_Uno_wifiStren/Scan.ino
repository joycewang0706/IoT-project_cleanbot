int Scan()
{
  //Serial.println("scan start");
  //delay(50);

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  //Serial.println("scan done");
  if (n == 0)
  {
    Serial.println("no networks found");
  }
  else
  {
    //Serial.print(n);
    //Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      if (WiFi.SSID(i) == hotspot)
      {
        int adjust = -1;
        strength = WiFi.RSSI(i) * adjust;

        Serial.println();
        Serial.print("RSSI:");
        Serial.println(strength);
      }
    }
  }
  Serial.println("");
  return strength;
}
