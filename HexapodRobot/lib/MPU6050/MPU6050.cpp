#include "MPU6050.h"

void MPU6050Class::write(uint8_t regAddress, uint8_t value)
{
	Wire.beginTransmission(MPU);  // Initialize communication
	Wire.write(regAddress);       // Record address to be written
	Wire.write(value);            // Insert data value
	Wire.endTransmission(true);   // Signals end of transmission
}


void MPU6050Class::begin(int sda, int scl)
{
    // MPU6050 I2C protocol
    Wire.begin(sda, scl);
    write(PWR_MGMT_1, 0x00);
    //write(SMPLRT_DIV, 0x07);
    write(CONFIG, 0x00);
    //write(GYRO_CONFIG, 0x18);
    write(ACCEL_CONFIG, 0x19);
}

mpuVector MPU6050Class::getAccel()
{
    mpuVector reading;
	Wire.beginTransmission(MPU);
	Wire.write(ACCEL_XOUT_H);
    Wire.endTransmission(false);         
    Wire.requestFrom(MPU, 6, 1); // request 6 registers
    reading.x.high = Wire.read(); // ACCEL_XOUT_H
    reading.x.low = Wire.read(); // ACCEL_XOUT_L
    reading.y.high = Wire.read(); // ACCEL_YOUT_H
    reading.y.low = Wire.read(); // ACCEL_YOUT_L
    reading.z.high = Wire.read(); // ACCEL_ZOUT_H
    reading.z.low = Wire.read(); // ACCEL_ZOUT_L
    return reading;
}

mpuVector MPU6050Class::getGyro()
{
    mpuVector reading;
	Wire.beginTransmission(MPU);
	Wire.write(GYRO_XOUT_H);
    Wire.endTransmission(false);         
    Wire.requestFrom(MPU, 6, 1); // request 6 registers
    reading.x.high = Wire.read(); // ACCEL_XOUT_H
    reading.x.low = Wire.read(); // ACCEL_XOUT_L
    reading.y.high = Wire.read(); // ACCEL_YOUT_H
    reading.y.low = Wire.read(); // ACCEL_YOUT_L
    reading.z.high = Wire.read(); // ACCEL_ZOUT_H
    reading.z.low = Wire.read(); // ACCEL_ZOUT_L
    return reading;
}