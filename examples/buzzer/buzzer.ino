/*
 * Buzzer example
 * 
 * The buzzer is on 2 digital pins and as you'll see its a lot like a blink sketch
 * Sadly its not hooked up to any PWM pins so no Tone library, just bit banged PWM :(
 * 
 * Use Delay to set your frequency. 
 * 
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
