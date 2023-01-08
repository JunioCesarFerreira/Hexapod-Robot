#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H

#include <Arduino.h>

// Timer parameters
//#define TIMER_DIVIDER      20 
//#define TIMER_ALARM_VALUE 100
//#define SERVO_TOTAL_TICKS 800 // 
//#define SERVO_CONTROL_INF  20 // 500 us 
//#define SERVO_CONTROL_SUP 104 // 2600 us
/*
    Note:
    Micro servos has 180° free movement. So,
    104-20=74 => steps = 180/74 = 2.43°
*/
// Timer parameters
#define TIMER_DIVIDER       10 
#define TIMER_ALARM_VALUE  100
#define SERVO_TOTAL_TICKS 1600 // 20 ms
#define SERVO_CONTROL_INF   40 // 500 us 
#define SERVO_CONTROL_SUP  208 // 2600 us
/*
    Note:
    Micro servos has 180° free movement. So,
    208-40=168 => steps = 180/168 = 1,07°
*/

// Number of micro-servos
#define NUMBER_OF_SERVOS    18

class ServoController
{
    public:
        /// @brief begin engine control
        /// @param servo_pinout pins attached to each motor
        void begin(const int8_t servo_pinout[NUMBER_OF_SERVOS]);

        /// @brief set pwm value for servo
        /// @param servo index servo
        /// @param value pwm value in ticks of timer 0
        void set(uint8_t servo, uint16_t value);
};

#endif