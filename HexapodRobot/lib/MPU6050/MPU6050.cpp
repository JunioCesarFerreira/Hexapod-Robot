#include "MPU6050.h"

void MPU6050Class::write(uint8_t regAddress, uint8_t value)
{
	Wire.beginTransmission(MPU6050_ADDRESS);  // Initialize communication
	Wire.write(regAddress);       // Record address to be written
	Wire.write(value);            // Insert data value
	Wire.endTransmission(true);   // Signals end of transmission
}


void MPU6050Class::begin(int sda, int scl)
{
    // MPU6050 I2C protocol
    Wire.begin(sda, scl);
    write(MPU6050_PWR_MGMT_1, 0x00);
    //write(MPU6050_SMPLRT_DIV, 0x07);
    write(MPU6050_CONFIG, 0x00);
    //write(GYRO_CONFIG, 0x18);
    write(MPU6050_ACCEL_CONFIG, 0x19);
}

mpuVector MPU6050Class::getAccel()
{
    mpuVector reading;
	Wire.beginTransmission(MPU6050_ADDRESS);
	Wire.write(MPU6050_ACCEL_XOUT_H);
    Wire.endTransmission(false);         
    Wire.requestFrom(MPU6050_ADDRESS, 6, 1); // request 6 registers
    reading.x.high = Wire.read(); // MPU6050_ACCEL_XOUT_H
    reading.x.low = Wire.read(); // MPU6050_ACCEL_XOUT_L
    reading.y.high = Wire.read(); // MPU6050_ACCEL_YOUT_H
    reading.y.low = Wire.read(); // MPU6050_ACCEL_YOUT_L
    reading.z.high = Wire.read(); // MPU6050_ACCEL_ZOUT_H
    reading.z.low = Wire.read(); // MPU6050_ACCEL_ZOUT_L
    return reading;
}

mpuVector MPU6050Class::getGyro()
{
    mpuVector reading;
	Wire.beginTransmission(MPU6050_ADDRESS);
	Wire.write(MPU6050_GYRO_XOUT_H);
    Wire.endTransmission(false);         
    Wire.requestFrom(MPU6050_ADDRESS, 6, 1); // request 6 registers
    reading.x.high = Wire.read(); // MPU6050_GYRO_XOUT_H
    reading.x.low = Wire.read(); // MPU6050_GYRO_XOUT_L
    reading.y.high = Wire.read(); // MPU6050_GYRO_YOUT_H
    reading.y.low = Wire.read(); // MPU6050_GYRO_YOUT_L
    reading.z.high = Wire.read(); // MPU6050_GYRO_ZOUT_H
    reading.z.low = Wire.read(); // MPU6050_GYRO_ZOUT_L
    return reading;
}