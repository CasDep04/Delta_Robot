#include <Arduino.h>

#define Motor1_LPWM 17
#define Motor1_RPWM 18

#define Motor2_LPWM 19
#define Motor2_RPWM 21

#define Motor3_LPWM 25
#define Motor3_RPWM 26

//============================================================
void Init_Motor()
{
    //motor1
    pinMode(Motor1_LPWM, OUTPUT);
    pinMode(Motor1_LPWM, OUTPUT);

    //motor2
    pinMode(Motor2_LPWM, OUTPUT);
    pinMode(Motor2_LPWM, OUTPUT);

    
    //motor3
    pinMode(Motor3_LPWM, OUTPUT);
    pinMode(Motor3_LPWM, OUTPUT);
}
//============================================================
//============================================================
void Run_Motor(int LPWM,int RPWM,float u)
{
    float speed = fabs(u);

    if(speed > 255){
        speed = 255;
    };

    if (u < 0)
    {
        digitalWrite(RPWM, LOW);
        analogWrite(LPWM, speed);
    }
    // Forward direction, if the mot_cmd is from [0; 255]; 
    else 
    {
        digitalWrite(LPWM, LOW);
        analogWrite(RPWM, speed);
    }
}
