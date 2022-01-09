void SenddataUno(int wifiStrength)
{
  /* begin with device address 8 */
  Wire.beginTransmission(8);
  /* sends on& off */
  Wire.write(outputState.c_str());
  Wire.write("A");
  Wire.write(wifiStrength);
  Wire.write("B");
  Wire.write(outputState_pointer.c_str());
  Wire.write("C");
  Wire.write("\n");
  /* stop transmitting */
  Wire.endTransmission();
  delay(50);
}
