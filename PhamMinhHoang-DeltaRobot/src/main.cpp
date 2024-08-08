#include <Arduino.h>
#include "./controller/MotorController.h"
#include "./controller/EncoderController.h"
#include "./controller/PIDController.h"
#include "./controller/SerialController.h"





void setup()
{
  Init_Motor();
  Init_Encoder();
  Init_Serial();
}

void loop()
{
  int target = 1000;

  float kp =10.0;
  float kd =0.0;
  float ki =0.0;

  float u = pidController(target, kp, ki, kd);

  
  Get_Angle();
  Run_Motor(Motor1_LPWM,Motor1_RPWM,u);
  SerialDataPrint();
  SerialDataWrite();
}
