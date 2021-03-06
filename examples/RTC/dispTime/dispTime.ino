/*-----------------------------------------------------------------------------------
** demo of RTC, display time
** loovee 2013-6-18
** https://github.com/reeedstudio/xadow
**
** Retrieves date and time from the RTC and formats it for the Console output. Uses Serial
** and I2C pins. 
**
** Refer to the Big Table of Xadow modules for more information and to 
** avoid conflicts http://www.seeedstudio.com/wiki/Xadow_IO_pin_mapping 
**
** This sketch is self contained and needs no external libraries beyond
** xadow.
**
** This code was originally written for the Xadow series of products 
** http://www.seeedstudio.com/depot/index.php?main_page=advanced_search_result&search_in_description=0&keyword=xadow&x=-1133&y=-60
** by Seeed Studio. http://www.seeedstudio.com/
** 
** Seeed makes all of its devices Open Source Hardware http://www.oshwa.org/
** which means you can find the design files to alter it or make your own!
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
**--------------------------------------------------------------------------------*/
#include <Wire.h>

#include "debug_x.h"
#include "xadow.h"
#include "xadowDfs.h"

#define ADDRRTC         0x68

unsigned char bcdToDec(unsigned char val)
{
    return ( (val/16*10) + (val%16) );
}

unsigned char getTime(unsigned char *dta)
{
    // Reset the register pointer
    Wire.beginTransmission(ADDRRTC);
    Wire.write((unsigned char)0x00);
    Wire.endTransmission();
    Wire.requestFrom(ADDRRTC, 7);
    // A few of these need masks because certain bits are control bits
    dta[6]  = bcdToDec(Wire.read());
    dta[5]  = bcdToDec(Wire.read());
    dta[4]  = bcdToDec(Wire.read());        // Need to change this if 12 hour am/pm
    dta[3]  = bcdToDec(Wire.read());
    dta[2]  = bcdToDec(Wire.read());
    dta[1]  = bcdToDec(Wire.read());
    dta[0]  = bcdToDec(Wire.read());

    return 1;
}


void setup()
{
    Serial.begin(115200);
    
    while(!Serial);
    Xadow.init();
    Wire.begin();
    
    delay(1000);
    cout << "hello world" << endl;
}

void loop()
{
    unsigned char td[7] = {0, 0, 0, 0, 0, 0, 0};            // td[] = {year, month, day, week, hour, min, sec};
    getTime(td);
    delay(1000);

    //add leading zero
    if(td[0]==0){
      cout << "200" << td[0] << '/' << td[1] << '/' << td[2] << tabl;
    }else{
      cout << "20" << td[0] << '/' << td[1] << '/' << td[2] << tabl;
    }
    cout << td[4] << ":" << td[5] << ":" << td[6] << endl;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
