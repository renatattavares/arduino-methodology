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

int Automata (int state){
	switch(state){
		case(0):
			SrvMotorMoveForward();
			state = 1;
			break;
		case(1):
			color = GetColor();
			state = 2;
			break;
		case(2):
			switch(color){
				case(0):
					state = 0;
					break;
				case(6):
					state = 3;
					break;
				case(1):
					state = 4;
					break;
				case(2):
					state = 5;
					break;
				case(3):
					state = 6;
					break;
				case(4):
					state = 7;
					break;
				case(5):
					state = 8;
					break;
				}
		case(3):
			StpMotorMoveCW();
			state = 9;
			break;
		case(4):
			StpMotorMoveCCW();
			state = 10;
			break;
		case(5):
			StpMotorMoveCW();
			state = 11;
			break;
		case(6):
			StpMotorMoveCCW();
			state = 12;
			break;
		case(7):
			StpMotorMoveCW();
			state = 13;
			break;
		case(8):
			SrvMotorMoveForward();
			state = 1;
			break;
		case(9):
			StpMotorMoveCW();
			state = 14;
			break;
		case(10):
			StpMotorMoveCCW();
			state = 15;
			break;
		case(11):
			StpMotorMoveCW();
			state = 16;
			break;
		case(12):
			SrvMotorMoveForward();
			state = 17;
			break;
		case(13):
			SrvMotorMoveForward();
			state = 18;
			break;
		case(14):
			SrvMotorMoveForward();
			state = 19;
			break;
		case(15):
			SrvMotorMoveForward();
			state = 20;
			break;
		case(16):
			StpMotorMoveCW();
			state = 21;
			break;
		case(17):
			color = GetColor();
			state = 22;
			break;
		case(18):
			color = GetColor();
			state = 23;
			break;
		case(19):
			color = GetColor();
			state = 24;
			break;
		case(20):
			color = GetColor();
			state = 25;
			break;
		case(21):
			SrvMotorMoveForward();
			state = 26;
			break;
		case(22):
			switch(color){
				case(1):
					state = 10;
					break;
				case(6):
					state = 27;
					break;
				case(0):
					state = 28;
					break;
				case(2):
					state = 29;
					break;
				case(3):
					state = 30;
					break;
				case(4):
					state = 31;
					break;
				case(5):
					state = 32;
					break;
				}
		case(23):
			switch(color){
				case(6):
					state = 9;
					break;
				case(2):
					state = 11;
					break;
				case(0):
					state = 33;
					break;
				case(1):
					state = 34;
					break;
				case(3):
					state = 35;
					break;
				case(4):
					state = 36;
					break;
				case(5):
					state = 37;
					break;
				}
		case(24):
			switch(color){
				case(2):
					state = 16;
					break;
				case(6):
					state = 38;
					break;
				case(0):
					state = 39;
					break;
				case(1):
					state = 40;
					break;
				case(3):
					state = 41;
					break;
				case(4):
					state = 42;
					break;
				case(5):
					state = 43;
					break;
				}
		case(25):
			switch(color){
				case(6):
					state = 44;
					break;
				case(0):
					state = 45;
					break;
				case(1):
					state = 46;
					break;
				case(2):
					state = 47;
					break;
				case(3):
					state = 48;
					break;
				case(4):
					state = 49;
					break;
				case(5):
					state = 50;
					break;
				}
		case(26):
			color = GetColor();
			state = 51;
			break;
		case(27):
			StpMotorMoveCW();
			state = 3;
			break;
		case(28):
			SrvMotorMoveForward();
			state = 17;
			break;
		case(29):
			StpMotorMoveCCW();
			state = 47;
			break;
		case(30):
			SrvMotorMoveForward();
			state = 17;
			break;
		case(31):
			StpMotorMoveCW();
			state = 7;
			break;
		case(32):
			StpMotorMoveCW();
			state = 52;
			break;
		case(33):
			SrvMotorMoveForward();
			state = 18;
			break;
		case(34):
			StpMotorMoveCW();
			state = 40;
			break;
		case(35):
			StpMotorMoveCCW();
			state = 6;
			break;
		case(36):
			SrvMotorMoveForward();
			state = 18;
			break;
		case(37):
			StpMotorMoveCCW();
			state = 53;
			break;
		case(38):
			SrvMotorMoveForward();
			state = 19;
			break;
		case(39):
			SrvMotorMoveForward();
			state = 19;
			break;
		case(40):
			StpMotorMoveCW();
			state = 54;
			break;
		case(41):
			StpMotorMoveCW();
			state = 55;
			break;
		case(42):
			StpMotorMoveCCW();
			state = 56;
			break;
		case(43):
			StpMotorMoveCCW();
			state = 37;
			break;
		case(44):
			StpMotorMoveCCW();
			state = 57;
			break;
		case(45):
			SrvMotorMoveForward();
			state = 20;
			break;
		case(46):
			SrvMotorMoveForward();
			state = 20;
			break;
		case(47):
			StpMotorMoveCCW();
			state = 58;
			break;
		case(48):
			StpMotorMoveCW();
			state = 59;
			break;
		case(49):
			StpMotorMoveCW();
			state = 31;
			break;
		case(50):
			StpMotorMoveCW();
			state = 32;
			break;
		case(51):
			switch(color){
				case(1):
					state = 54;
					break;
				case(3):
					state = 55;
					break;
				case(6):
					state = 57;
					break;
				case(0):
					state = 60;
					break;
				case(2):
					state = 61;
					break;
				case(4):
					state = 62;
					break;
				case(5):
					state = 63;
					break;
				}
		case(52):
			SrvMotorMoveForward();
			state = 1;
			break;
		case(53):
			SrvMotorMoveForward();
			state = 1;
			break;
		case(54):
			StpMotorMoveCW();
			state = 64;
			break;
		case(55):
			StpMotorMoveCW();
			state = 48;
			break;
		case(56):
			SrvMotorMoveForward();
			state = 18;
			break;
		case(57):
			StpMotorMoveCCW();
			state = 65;
			break;
		case(58):
			SrvMotorMoveForward();
			state = 26;
			break;
		case(59):
			SrvMotorMoveForward();
			state = 17;
			break;
		case(60):
			SrvMotorMoveForward();
			state = 26;
			break;
		case(61):
			SrvMotorMoveForward();
			state = 26;
			break;
		case(62):
			StpMotorMoveCCW();
			state = 42;
			break;
		case(63):
			StpMotorMoveCW();
			state = 50;
			break;
		case(64):
			SrvMotorMoveForward();
			state = 20;
			break;
		case(65):
			SrvMotorMoveForward();
			state = 19;
			break;
	}
	return(state);
}