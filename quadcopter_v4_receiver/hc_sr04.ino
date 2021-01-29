volatile unsigned int pwm_value = 0;
volatile unsigned int prev_time = 0;
const byte interruptPin = 3;


float sound_speed = 0.017; // half of cm/mu s

void setup_hc_sr04()
{
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), rising, RISING);
}
 
void loop_hc_sr04() 
{
  
 Serial.print(prev_time);
 Serial.print("  pwm:     ");
 Serial.print(pwm_value);
 Serial.print("cm:      ");
 Serial.println(pwm_value * sound_speed);

}
 
void rising() {
  attachInterrupt(digitalPinToInterrupt(interruptPin), falling, FALLING);
  prev_time = micros();
}
 
void falling() {
  attachInterrupt(digitalPinToInterrupt(interruptPin), rising, RISING);
  pwm_value = micros()-prev_time;
  //Serial.println(pwm_value);

}
