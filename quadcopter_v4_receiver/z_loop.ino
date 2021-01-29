Task IMU_Task(10);
Task HC_SR04_Task(1000);

Logging MyLog;

const int pwmPin = 9;  

void loop()
{
  
  loop_radio();

  if (IMU_Task.StartTask())
  {
    //MyLog.log_start_task(1);
    loop_mpu6050();
    //MyLog.log_end_task(1);
  }

  //MyLog.print_data();
  if (HC_SR04_Task.StartTask())
  {
    loop_hc_sr04();
  }
}


void loop_radio()
{

  byte pipeNum = 0;
  if ( radio.available(&pipeNum)) 
  {
    //MyLog.log_start_task(2);
    if (pipeNum == 1 || pipeNum == 2 || pipeNum == 3) 
      loadAckData(pipeNum);

    //delay(1); // For some readon need small delay to not read garbage every second time
    //Serial.print(" Small wait: ");
    byte len = radio.getDynamicPayloadSize();
    radio.read(&my_telegram, len);
    if(false)
    {
    Serial.print(" Pipe No: ");
    Serial.print(pipeNum);
    Serial.print(" Unit No: ");
    Serial.print(my_telegram.nodeID);
    Serial.print(" Msg No: ");
    Serial.print(my_telegram.msgNo);
    Serial.print(" Potmeter Val: ");
    Serial.print(my_telegram.temp1);
    Serial.print("  Angle : ");
    print_mpu6050();
    Serial.print("  Time : ");
    Serial.println(millis());
    }
    //analogWrite(pwmPin, my_telegram.temp1);
    analogWrite(pwmPin, 110);
    //MyLog.log_end_task(2);
  }
}
