/*-----------------------------------------------------------------------------------
** demo of Vibrator
** loovee 2013-6-18
** https://github.com/reeedstudio/xadow
**
** Example is more complicated than it has to be.  Motor is on
** digital pins (two of them) and can be treated just like a blink sketch
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

void vibrate(unsigned char OnOff)
{
    if(OnOff)
    {
      digitalWrite(16,HIGH);
      digitalWrite(A5,HIGH);
    }
    else
    {
      digitalWrite(16,LOW);
      digitalWrite(A5,LOW);
    }
}

void setup()
{
    Xadow.init();
    pinMode(A5,OUTPUT);                   // init IO
    pinMode(16,OUTPUT);
}

void loop()
{
    vibrate(1);                     // ON
    delay(500);
    vibrate(0);                     // OFF
    delay(500);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
