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

// const char* ssid = "HowWasYourDayToday";
// const char* password = "9563987865";
// const char* serverIp = "192.168.50.156";
// const int serverPort = 8080;
String cmd;

Motor left(MOTOR_AI1, MOTOR_AI2, MOTOR_APWM);
Motor right(MOTOR_BI1, MOTOR_BI2, MOTOR_BPWM);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // WiFi.begin(ssid, password);
  
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(1000);
  //   Serial.println("Connecting to WiFi...");
  // }
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.println("Connected to WiFi");
  Serial.println("Setting up Motors");
  if(left.init() && right.init())Serial.println("Successful");
  left.setSpeed(250);
  right.setSpeed(-250);
}
int seconds = 0;
void loop() {
  delay(1000);
  seconds++;
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  seconds++;
  digitalWrite(LED_BUILTIN, HIGH);
  if(seconds % 60 == 0){
    left.setSpeed(250);
    right.setSpeed(-250);
  }
  // put your main code here, to run repeatedly:
  // if(Serial.available()){
  //   cmd = Serial.readString();
  //   if(cmd[0] == 'l'){
  //     int speedUpdate = atoi(cmd.c_str()+2);
  //     if(left.setSpeed(speedUpdate)){
  //       Serial.printf("Speed is now %d\n", speedUpdate);
  //     }else{
  //       Serial.println("Invalid Value");
  //     }
  //   }else{
  //     int speedUpdate = atoi(cmd.c_str()+2);
  //     if(right.setSpeed(speedUpdate)){
  //       Serial.printf("Speed is now %d\n", speedUpdate);
  //     }else{
  //       Serial.println("Invalid Value");
  //     }
  //   }
  // }
  // if (WiFi.status() == WL_CONNECTED) {
  //   WiFiClient client;
    
  //   if (client.connect(serverIp, serverPort)) {
  //     // Send data to the server
  //     client.print("Hello from ESP32!");
  //     delay(10);

  //     // Receive a response from the server
  //     while(client.available()){
  //       cmd = (client.readString());
  //       Serial.println(cmd);
  //       Serial.printf("Recieve Length: %d\n", cmd.length());
  //       if(cmd[0] == 'l' && cmd.length()>0){
  //         int speedUpdate = atoi(cmd.c_str()+2);
  //         if(left.setSpeed(speedUpdate)){
  //           client.printf("Speed is now %d\n", speedUpdate);
  //         }else{
  //           client.println("Invalid Value");
  //         }
  //       }else if(cmd.length()>0){
  //         int speedUpdate = atoi(cmd.c_str()+2);
  //         if(right.setSpeed(speedUpdate)){
  //           client.printf("Speed is now %d\n", speedUpdate);
  //         }else{
  //           client.println("Invalid Value");
  //         }
  //   }
  //     }
     
  //     client.stop();
  //   } else {
  //     Serial.println("Connection failed");
  //   }
    
  //   delay(3000);  // Delay before making the next connection
  // }


}
