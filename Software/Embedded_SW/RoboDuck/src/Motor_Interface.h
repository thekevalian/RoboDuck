#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H
#include <Arduino.h>
#define PWM_MTR_FREQUENCY 5000 // 5kHz
#define PWM_MTR_RESOLUTION 8 // 8 bit timer
struct Motor{
    int16_t speed : 12;
    int16_t ledcChan : 4;
    uint8_t dir_pin_I1;
    uint8_t dir_pin_I2;
    uint8_t pwm_pin;
    Motor() : speed(0), dir_pin_I1(0), dir_pin_I2(0), pwm_pin(0) {};
    Motor(uint8_t I1, uint8_t I2, u_int8_t pwm) : speed(0), dir_pin_I1(I1), dir_pin_I2(I2), pwm_pin(pwm) {};
    bool init();
    bool setSpeed(int16_t newSpeed); /* Value from 0 to 255 */
};


#endif