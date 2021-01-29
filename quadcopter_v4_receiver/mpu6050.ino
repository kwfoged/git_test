#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Task.h>

MPU6050 mpu6050(Wire);

void setup_mpu6050() {
  Wire.begin();
  mpu6050.begin();
  mpu6050.setup_kalman();
  mpu6050.calcGyroOffsets(true);
}

void loop_mpu6050()
{
  mpu6050.update();
}

void print_mpu6050()
{
    Serial.print(mpu6050.getKalmanX());
}

