#include <Task.h>

Task HC_SR04_Task(50); // Every 50 ms / 20 Hz

volatile unsigned int pwm_value = 0;
volatile unsigned int prev_time = 0;
const byte interruptPin = 3;
const int trigPin = 4;

float sound_speed = 0.017; // half of cm/mu s

void setup()
{
  Serial.begin(115200);
  pinMode(interruptPin, INPUT_PULLUP);
  //pinMode(interruptPin, INPUT);
  pinMode(trigPin, OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), rising, RISING);
}
 
void loop() 
{
 if (HC_SR04_Task.StartTask())
 {
  Serial.print("cm:      ");
  Serial.println(pwm_value * sound_speed);

  // Reset trig pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 }
 
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
