#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include <Arduino.h>
#include "EncoderController.h"

long previousTime = 0;
long ePrevious =0;
long eIntegral =0;

float pidController(int target,int kp,int ki,int kd){
    long currentTime = micros();

    float deltaT = ((float)(currentTime - previousTime)) / 1.0e6;

    int error = Motor1_Pos - target;
    float eDerivative = (error - ePrevious) / deltaT;

    eIntegral = eIntegral + error * deltaT;

    float u = (kp * error) + (kd * eDerivative) + (ki + eIntegral);

    previousTime = currentTime;
    ePrevious = error;
    return u;
};
#endif