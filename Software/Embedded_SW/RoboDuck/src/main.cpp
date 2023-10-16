#include <Arduino.h>
#include <WiFi.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <Motor_Interface.h>

#define MOTOR_AI1 1
#define MOTOR_AI2 2
#define MOTOR_BI1 3
#define MOTOR_BI2 4
#define MOTOR_APWM 16
#define MOTOR_BPWM 17

Motor left(MOTOR_AI1, MOTOR_AI2, MOTOR_APWM);
Motor right(MOTOR_BI1, MOTOR_BI2, MOTOR_BPWM);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Setting up Motors");
  if(left.init() && right.init())Serial.println("Succesful");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String cmd = Serial.readString();
    if(cmd[0] == 'l'){
      int speedUpdate = atoi(cmd.c_str()+2);
      if(left.setSpeed(speedUpdate)){
        Serial.printf("Speed is now %d\n", speedUpdate);
      }else{
        Serial.println("Invalid Value");
      }
    }else{
      int speedUpdate = atoi(cmd.c_str()+2);
      if(right.setSpeed(speedUpdate)){
        Serial.printf("Speed is now %d\n", speedUpdate);
      }else{
        Serial.println("Invalid Value");
      }
    }
  }
}
