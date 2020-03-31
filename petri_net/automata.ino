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
			mymachine.SrvMotorMoveForward();
			state = 1;
			break;
		case(1):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
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
			break;
		case(3):
			mymachine.StpMotorMoveCW();
			state = 9;
			break;
		case(4):
			mymachine.StpMotorMoveCCW();
			state = 10;
			break;
		case(5):
			mymachine.StpMotorMoveCW();
			state = 11;
			break;
		case(6):
			mymachine.StpMotorMoveCCW();
			state = 12;
			break;
		case(7):
			mymachine.StpMotorMoveCW();
			state = 13;
			break;
		case(8):
			mymachine.SrvMotorMoveForward();
			state = 1;
			break;
		case(9):
			mymachine.StpMotorMoveCW();
			state = 14;
			break;
		case(10):
			mymachine.StpMotorMoveCCW();
			state = 15;
			break;
		case(11):
			mymachine.StpMotorMoveCW();
			state = 16;
			break;
		case(12):
			mymachine.SrvMotorMoveForward();
			state = 17;
			break;
		case(13):
			mymachine.SrvMotorMoveForward();
			state = 18;
			break;
		case(14):
			mymachine.SrvMotorMoveForward();
			state = 19;
			break;
		case(15):
			mymachine.SrvMotorMoveForward();
			state = 20;
			break;
		case(16):
			mymachine.StpMotorMoveCW();
			state = 21;
			break;
		case(17):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 22;
			break;
		case(18):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 23;
			break;
		case(19):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 24;
			break;
		case(20):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 25;
			break;
		case(21):
			mymachine.SrvMotorMoveForward();
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
			break;
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
			break;
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
			break;
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
			break;
		case(26):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 51;
			break;
		case(27):
			mymachine.StpMotorMoveCW();
			state = 3;
			break;
		case(28):
			mymachine.SrvMotorMoveForward();
			state = 17;
			break;
		case(29):
			mymachine.StpMotorMoveCCW();
			state = 47;
			break;
		case(30):
			mymachine.SrvMotorMoveForward();
			state = 17;
			break;
		case(31):
			mymachine.StpMotorMoveCW();
			state = 7;
			break;
		case(32):
			mymachine.StpMotorMoveCW();
			state = 52;
			break;
		case(33):
			mymachine.SrvMotorMoveForward();
			state = 18;
			break;
		case(34):
			mymachine.StpMotorMoveCW();
			state = 40;
			break;
		case(35):
			mymachine.StpMotorMoveCCW();
			state = 6;
			break;
		case(36):
			mymachine.SrvMotorMoveForward();
			state = 18;
			break;
		case(37):
			mymachine.StpMotorMoveCCW();
			state = 53;
			break;
		case(38):
			mymachine.SrvMotorMoveForward();
			state = 19;
			break;
		case(39):
			mymachine.SrvMotorMoveForward();
			state = 19;
			break;
		case(40):
			mymachine.StpMotorMoveCW();
			state = 54;
			break;
		case(41):
			mymachine.StpMotorMoveCW();
			state = 55;
			break;
		case(42):
			mymachine.StpMotorMoveCCW();
			state = 56;
			break;
		case(43):
			mymachine.StpMotorMoveCCW();
			state = 37;
			break;
		case(44):
			mymachine.StpMotorMoveCCW();
			state = 57;
			break;
		case(45):
			mymachine.SrvMotorMoveForward();
			state = 20;
			break;
		case(46):
			mymachine.SrvMotorMoveForward();
			state = 20;
			break;
		case(47):
			mymachine.StpMotorMoveCCW();
			state = 58;
			break;
		case(48):
			mymachine.StpMotorMoveCW();
			state = 59;
			break;
		case(49):
			mymachine.StpMotorMoveCW();
			state = 31;
			break;
		case(50):
			mymachine.StpMotorMoveCW();
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
			break;
		case(52):
			mymachine.SrvMotorMoveForward();
			state = 1;
			break;
		case(53):
			mymachine.SrvMotorMoveForward();
			state = 1;
			break;
		case(54):
			mymachine.StpMotorMoveCW();
			state = 64;
			break;
		case(55):
			mymachine.StpMotorMoveCW();
			state = 48;
			break;
		case(56):
			mymachine.SrvMotorMoveForward();
			state = 18;
			break;
		case(57):
			mymachine.StpMotorMoveCCW();
			state = 65;
			break;
		case(58):
			mymachine.SrvMotorMoveForward();
			state = 26;
			break;
		case(59):
			mymachine.SrvMotorMoveForward();
			state = 17;
			break;
		case(60):
			mymachine.SrvMotorMoveForward();
			state = 26;
			break;
		case(61):
			mymachine.SrvMotorMoveForward();
			state = 26;
			break;
		case(62):
			mymachine.StpMotorMoveCCW();
			state = 42;
			break;
		case(63):
			mymachine.StpMotorMoveCW();
			state = 50;
			break;
		case(64):
			mymachine.SrvMotorMoveForward();
			state = 20;
			break;
		case(65):
			mymachine.SrvMotorMoveForward();
			state = 19;
			break;
	}
	return(state);
}