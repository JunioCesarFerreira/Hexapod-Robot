#ifndef MPU_6050_H
#define MPU_6050_H

#include <Wire.h>

#define 	   MPU   		      0x68
// MPU6050 Registers
#define        SMPLRT_DIV         0x19
#define        CONFIG             0x1A
#define        GYRO_CONFIG        0x1B
#define        ACCEL_CONFIG       0x1C
#define        ACCEL_XOUT_H       0x3B
#define        ACCEL_XOUT_L       0x3C
#define        ACCEL_YOUT_H       0x3D
#define        ACCEL_YOUT_L       0x3E
#define        ACCEL_ZOUT_H       0x3F
#define        ACCEL_ZOUT_L       0x40
#define        TEMP_OUT_H         0x41
#define        TEMP_OUT_L         0x42
#define        GYRO_XOUT_H        0x43
#define        GYRO_XOUT_L        0x44
#define        GYRO_YOUT_H        0x45
#define        GYRO_YOUT_L        0x46
#define        GYRO_ZOUT_H        0x47
#define        GYRO_ZOUT_L        0x48
#define        PWR_MGMT_1         0x6B
#define        WHO_AM_I           0x75
#define        CLIENT_ADDRESS     0xD0

union mpuValue
{
    int16_t value;
    struct
    {
        uint8_t low;
        uint8_t high;
    };
};

struct mpuVector
{
    mpuValue x;
    mpuValue y;
    mpuValue z;
};


class MPU6050Class
{
    private:
        void write(uint8_t regAddress, uint8_t value);

    public:
        void begin(int sda, int scl);
        mpuVector getAccel();
        mpuVector getGyro();
};

#endif