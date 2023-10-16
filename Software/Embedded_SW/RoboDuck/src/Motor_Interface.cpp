#include "Motor_Interface.h"
#include <esp32-hal-ledc.h>
static uint8_t ledc_channels_used = 0;

bool Motor::init(){
    
    if(GPIO_IS_VALID_OUTPUT_GPIO(dir_pin_I1) && GPIO_IS_VALID_OUTPUT_GPIO(dir_pin_I2) && (ledc_channels_used<SOC_LEDC_CHANNEL_NUM)){
        ledcSetup(ledc_channels_used, PWM_MTR_FREQUENCY, PWM_MTR_RESOLUTION);
        ledcAttachPin(pwm_pin, ledc_channels_used);
        pinMode(dir_pin_I1, OUTPUT);
        pinMode(dir_pin_I2, OUTPUT);
        digitalWrite(dir_pin_I1, LOW);
        digitalWrite(dir_pin_I2, HIGH);
        ledcChan = ledc_channels_used;
        ledcWrite(ledcChan, 0);
        ledc_channels_used++;
        return true;
    }
    return false;
}

/* H L is cw, L H is ccw*/
/* Value from -255 to 255  (-) indicates counter clockwise */
bool Motor::setSpeed(int16_t newSpeed) 
{
    if(GPIO_IS_VALID_OUTPUT_GPIO(dir_pin_I1) && GPIO_IS_VALID_OUTPUT_GPIO(dir_pin_I2) && newSpeed < 256 && newSpeed > -256){
        if(newSpeed == 0) ledcWrite(ledcChan, 0);
        if (!(newSpeed > 0 && speed > 0 || newSpeed < 0 && speed < 0)){
            /* change direction of motor */
            Serial.printf("Switched Direction at speed: %d, newSpeed: %d\n", speed, newSpeed);
            if(newSpeed<0){
                digitalWrite(dir_pin_I1, LOW);
                digitalWrite(dir_pin_I2, HIGH);
            }else{
                digitalWrite(dir_pin_I1, HIGH);
                digitalWrite(dir_pin_I2, LOW);
            }
        }
        speed = newSpeed;
        ledcWrite(ledcChan, (speed>0)?speed:-speed);
        Serial.printf("New Speed is %d, AI1: %d, AI2: %d, ledcHan: %d\n", speed, digitalRead(dir_pin_I1), digitalRead(dir_pin_I2), ledcChan);
        return true;
    }
    return false;
}
