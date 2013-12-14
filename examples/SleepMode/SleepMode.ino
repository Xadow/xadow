/*-----------------------------------------------------------------------------------
** demo of sleep mdoe
** loovee 2013-6-18
** https://github.com/reeedstudio/xadow
**
** Prints to Serial console that it is going to sleep, then puts Xadow to sleep 
** for 1 second and wakes up for half a second and repeats. Uses Serial pins. 
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

#include "xadow.h"


void setup()
{
    Serial.begin(115200);
    while(!Serial);
    Xadow.init();
    
    delay(2000); //Leave this or it will be asleep and you can't reprogram it!
    cout << "init over" << endl;
}

void loop()
{
    cout << "begin to sleep for 1s" << endl;
    Xadow.pwrDown(1000);                        // sleep for 1000ms
    Xadow.wakeUp();                             // wake up
    cout << "wake up" << endl;
    delay(500);                                 // delay 500 ms
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
