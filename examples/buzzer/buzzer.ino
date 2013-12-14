/*
 * Buzzer example
 * 
 * The buzzer is on 2 digital pins but as you'll see its a lot like a blink sketch
 * Sadly its not hooked up to any PWM pins so no Tone library, just bit banged PWM :(
 * 
 * Use Delay to set your frequency. Frequency in hz is 1 divided by Period. So the
 * period of this example is 2ms total (1 + 1) then the frequency of the tone is 1khz.
 *
 * Uses pin 15 and 16.
 *
 * Refer to the Big Table of Xadow modules for more information and to 
 * avoid conflicts http://www.seeedstudio.com/wiki/Xadow_IO_pin_mapping 
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
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
}

void loop(){
  //turn on the buzzer
  digitalWrite(15,HIGH);
  digitalWrite(16,HIGH);
  delay(1);
  
  //turn off the buzzer		
  digitalWrite(15,LOW);
  digitalWrite(16,LOW);
  delay(1);	
}
