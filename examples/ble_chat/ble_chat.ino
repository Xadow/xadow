/*
 * Bluetooth Low Energy Chat Example. 
 * 
 * Sketch is simply a serial passthrough. You can type characters in the Serial Monitor
 * and they pop out on the other end of the bluetooth.
 * 
 * Utilize a BLE app on mobile like lightblue on ios
 * https://itunes.apple.com/us/app/lightblue-bluetooth-low-energy/id557428110?mt=8
 * Find the FFF0 service and then use the FFF1 characteristic to read data and the 
 * FFF2 to write characters to the arduino
 * 
 */

void setup()
{
  Serial.begin(9600);
  while (!Serial) ;
  
  Serial1.begin(38400);
}
void loop()
{
    if(Serial.available())
    {
      Serial1.write(Serial.read());
    }
    if(Serial1.available())
    {
      Serial.write(Serial1.read());
    }
}
