#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H

#include <Arduino.h>

// Timer parameters
#define TIMER_DIVIDER      20 
#define TIMER_ALARM_VALUE 100
#define SERVO_TOTAL_TICKS 800 // 1 Tick = 50 us
#define SERVO_CONTROL_INF  20 // 500 us 
#define SERVO_CONTROL_SUP 104 // 2600 us

// Array parameters
#define SERVOS_AMOUNT   18

class ServoController
{
    public:
        void begin();
        void set(uint8_t servo, uint16_t value);
};

#endif