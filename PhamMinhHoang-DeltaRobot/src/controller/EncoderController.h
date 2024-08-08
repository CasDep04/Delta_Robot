#include <Arduino.h>

#define ENC_RES 330 // Encoder resolution*Gearbox ratio: 11*30

#define Motor1_EncoderA 16
#define Motor1_EncoderB 4

#define Motor2_EncoderA 22
#define Motor2_EncoderB 23

#define Motor3_EncoderA 27
#define Motor3_EncoderB 32


volatile long int Motor1_Pos = 0;
volatile long int Motor2_Pos = 0;
volatile long int Motor3_Pos = 0;  // Volatile as it changed during interrupt

double Motor1_Angle = 0;
double Motor2_Angle = 0;
double Motor3_Angle = 0;             // Position angle in degrees

//================================================================================
void readEncoder1()
{
    int b = digitalRead(Motor1_EncoderB);
    if(Motor1_Pos > 254 || Motor1_Pos < -254){
        return;
    }
    Motor1_Pos = (b > 0) ? (Motor1_Pos + 1) : (Motor1_Pos - 1);
}

void readEncoder2()
{
    int b = digitalRead(Motor2_EncoderB);
    if(Motor2_Pos > 254 || Motor2_Pos < -254){
        return;
    }
    Motor2_Pos = (b > 0) ? (Motor2_Pos + 1) : (Motor2_Pos - 1);
}

void readEncoder3()
{
    int b = digitalRead(Motor3_EncoderB);
    if(Motor3_Pos > 254 || Motor3_Pos < -254){
        return;
    }
    Motor3_Pos = (b > 0) ? (Motor3_Pos + 1) : (Motor3_Pos - 1);
}

void Init_Encoder()
{
    //motor 1
    pinMode(Motor1_EncoderA, INPUT_PULLUP);
    pinMode(Motor1_EncoderB, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(Motor1_EncoderA), readEncoder1, RISING);

    //motor 2
    pinMode(Motor2_EncoderA, INPUT_PULLUP);
    pinMode(Motor2_EncoderB, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(Motor2_EncoderA), readEncoder2, RISING);

    //motor 3
    pinMode(Motor3_EncoderA, INPUT_PULLUP);
    pinMode(Motor3_EncoderB, INPUT_PULLUP);
    
    attachInterrupt(digitalPinToInterrupt(Motor3_EncoderA), readEncoder3, RISING);
}

void Get_Angle()
{
    Motor1_Angle = Motor1_Pos * 360 / ENC_RES;
    Motor2_Angle = Motor2_Pos * 360 / ENC_RES;
    Motor3_Angle = Motor3_Pos * 360 / ENC_RES; // Conversion between encoder count and degree
}