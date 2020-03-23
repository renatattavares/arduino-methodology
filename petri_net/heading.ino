// Include libraries
#include "SortingMachineLib.h"

SortingMachine mymachine;

int color, state;

void PrintColorTxt(int color){
  switch(color){
    case(0):
      Serial.println("Empty");
      break;
    case(1):
      Serial.println("Orange");
      break;
    case(2):
      Serial.println("Brown");
      break;
    case(3):
      Serial.println("Red");
      break;
    case(4):
      Serial.println("Blue");
      break;
    case(5):
      Serial.println("Yellow");
      break;
    case(6):
      Serial.println("Green");
      break;
  }
}

void setup() {
  Serial.begin(115200);
  mymachine.Initialize();
  mymachine.StpMotorMoveToInitPos();
  state = 0;
}

void loop(){
  state = Automata(state);
}
