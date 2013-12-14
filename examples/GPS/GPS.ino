/*
 * Xadow GPS example
 * 
 * Sketch is simply a serial passthrough to the GPS module
 * 
 * Here we're just printing the characters to screen, but you might log the data
 * or pass it through to OLED or BLE, or look into Arduiniana's tinyGPS++ to parse
 * out some bit of data you're looking for
 * http://arduiniana.org/2013/09/tinygps-a-new-view-of-global-positioning/
 * 
 * Uses Serial and Serial1 pins.
 *
 * Refer to the Big Table of Xadow modules for more information and to 
 * avoid conflicts http://www.seeedstudio.com/wiki/Xadow_IO_pin_mapping 
 *
 * This code was originally written for the Xadow series of products 
 * http://www.seeedstudio.com/depot/index.php?main_page=advanced_search_result&search_in_description=0&keyword=xadow&x=-1133&y=-60
 * by Seeed Studio. http://www.seeedstudio.com/
 * 
 * Seeed makes all of its devices Open Source Hardware http://www.oshwa.org/
 * which means you can find the design files to alter it or make your own.
 */

#define SerialBaud   9600
#define Serial1Baud  9600
void setup()
{
  Serial.begin(SerialBaud);
  Serial1.begin(Serial1Baud);
}

void loop()
{
  for(;;)
  {
    // copy from virtual serial line to uart and vice versa
   /*
    */
    if (Serial.available())
    {
      Serial1.write(Serial.read());
    }
    if (Serial1.available())
    {
      Serial.write(Serial1.read());
    }
  }
}
