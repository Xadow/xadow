/*
 * Bluetooth Low Energy Chat Example. 
 * 
 * Sketch is simply a serial passthrough. You can type characters in the Serial Monitor
 * and they pop out on the other end of the bluetooth. Uses Serial and Serial1 pins.
 *
 * Refer to the Big Table of Xadow modules for more information and to 
 * avoid conflicts http://www.seeedstudio.com/wiki/Xadow_IO_pin_mapping 
 *
 * Utilize a BLE app on mobile like lightblue on ios
 * https://itunes.apple.com/us/app/lightblue-bluetooth-low-energy/id557428110?mt=8
 * Find the FFF0 service and then use the FFF1 characteristic to read data and the 
 * FFF2 to write characters to the arduino
 *
 * This code was originally written for the Xadow series of products 
 * http://www.seeedstudio.com/depot/index.php?main_page=advanced_search_result&search_in_description=0&keyword=xadow&x=-1133&y=-60
 * by Seeed Studio. http://www.seeedstudio.com/
 * 
 * Seeed makes all of its devices Open Source Hardware http://www.oshwa.org/
 * which means you can find the design files to alter it or make your own!
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
