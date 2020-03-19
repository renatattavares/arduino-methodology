// Include libraries
#include "SortingMachineLib.h"

SortingMachine mymachine;

int color, position, state;

void PrintColorTxt(int color){
  switch(color){
  case(1):
    Serial.println("Vermelho");
    break;
  case(2):
    Serial.println("Verde");
    break;
   case(3):
    Serial.println("Azul");
    break;
   case(4):
    Serial.println("Amarelo");
    break;
   case(5):
    Serial.println("Laranja");
    break;
   case(6):
    Serial.println("Marrom");
    break;
  case(7):
    Serial.println("Vazio");
    break;
  }
}

void setup() {
  Serial.begin(115200);
  mymachine.Initialize();
  mymachine.StpMotorMoveToInitPos();
  state = 1;
  pos = 4;
}

void loop(){
  state = Automata(state);
}
