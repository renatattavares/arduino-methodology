#ifndef SortingMachineLib_h
#define SortingMachineLib_h

#include <Arduino.h>
/*#include "Servo.h"
#include "Wire.h"
#include "Adafruit_TCS34725.h"
#include "CheapStepper.h"*/

class SortingMachine{
  public:
    SortingMachine();
    ~SortingMachine();
    void Initialize();
    void SrvMotorMoveForward();
    void SrvMotorMoveBackward();
    int GetColor();
    void ShowColor(int color);
    void StpMotorMoveToInitPos();
    void StpMotorMoveCW();
    void StpMotorMoveCCW();
    int StpMotorGetPosition();   
    bool Check_Sensors(int arrival);
  private:
};

#endif
