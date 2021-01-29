void setup()
{
  pinMode(3, OUTPUT);  // sets the pin as output
  Serial.begin(115200);
  setup_radio();
  setup_mpu6050();
  setup_hc_sr04();
}

