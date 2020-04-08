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
			mymachine.StpMotorMoveCCW();
			state = 11;
			break;
		case(6):
			mymachine.SrvMotorMoveForward();
			state = 1 t20/12;
			break;
		case(7):
			mymachine.SrvMotorMoveForward();
			state = 1 t58/13;
			break;
		case(8):
			mymachine.SrvMotorMoveForward();
			state = 1;
			break;
		case(9):
			mymachine.StpMotorMoveCW();
			state = 14 t73/15;
			break;
		case(10):
			mymachine.SrvMotorMoveForward();
			state = 16 t76/17;
			break;
		case(11):
			mymachine.StpMotorMoveCCW();
			state = 18;
			break;
		case(12):
			mymachine.SrvMotorMoveForward();
			state = 16;
			break;
		case(13):
			mymachine.SrvMotorMoveForward();
			state = 15;
			break;
		case(14):
			mymachine.SrvMotorMoveForward();
			state = 19;
			break;
		case(15):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 20;
			break;
		case(16):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 21;
			break;
		case(17):
			mymachine.SrvMotorMoveForward();
			state = 22;
			break;
		case(18):
			mymachine.SrvMotorMoveForward();
			state = 22 t64/23;
			break;
		case(19):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 24;
			break;
		case(20):
			switch(color){
				case(6):
					state = 9;
					break;
				case(4):
					state = 13;
					break;
				case(0):
					state = 25;
					break;
				case(1):
					state = 26;
					break;
				case(2):
					state = 27;
					break;
				case(3):
					state = 28;
					break;
				case(5):
					state = 29;
					break;
				}
			break;
		case(21):
			switch(color){
				case(1):
					state = 10;
					break;
				case(2):
					state = 11;
					break;
				case(3):
					state = 12;
					break;
				case(6):
					state = 30;
					break;
				case(0):
					state = 31;
					break;
				case(4):
					state = 32;
					break;
				case(5):
					state = 33;
					break;
				}
			break;
		case(22):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 34;
			break;
		case(23):
			mymachine.SrvMotorMoveForward();
			state = 35;
			break;
		case(24):
			switch(color){
				case(6):
					state = 14;
					break;
				case(0):
					state = 36;
					break;
				case(1):
					state = 37;
					break;
				case(2):
					state = 38;
					break;
				case(3):
					state = 39;
					break;
				case(4):
					state = 40;
					break;
				case(5):
					state = 41;
					break;
				}
			break;
		case(25):
			mymachine.SrvMotorMoveForward();
			state = 15;
			break;
		case(26):
			mymachine.StpMotorMoveCCW();
			state = 4;
			break;
		case(27):
			mymachine.StpMotorMoveCW();
			state = 38;
			break;
		case(28):
			mymachine.StpMotorMoveCCW();
			state = 6;
			break;
		case(29):
			mymachine.StpMotorMoveCCW();
			state = 8 t72/15;
			break;
		case(30):
			mymachine.StpMotorMoveCCW();
			state = 42;
			break;
		case(31):
			mymachine.SrvMotorMoveForward();
			state = 16;
			break;
		case(32):
			mymachine.StpMotorMoveCW();
			state = 7;
			break;
		case(33):
			mymachine.StpMotorMoveCW();
			state = 8 t72/16;
			break;
		case(34):
			switch(color){
				case(1):
					state = 17;
					break;
				case(2):
					state = 18;
					break;
				case(6):
					state = 42;
					break;
				case(0):
					state = 43;
					break;
				case(3):
					state = 44;
					break;
				case(4):
					state = 45;
					break;
				case(5):
					state = 46;
					break;
				}
			break;
		case(35):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 47;
			break;
		case(36):
			mymachine.SrvMotorMoveForward();
			state = 19;
			break;
		case(37):
			mymachine.StpMotorMoveCW();
			state = 48;
			break;
		case(38):
			mymachine.SrvMotorMoveForward();
			state = 19 t62/23;
			break;
		case(39):
			mymachine.StpMotorMoveCCW();
			state = 28;
			break;
		case(40):
			mymachine.StpMotorMoveCCW();
			state = 13 t71/19;
			break;
		case(41):
			mymachine.StpMotorMoveCCW();
			state = 29;
			break;
		case(42):
			mymachine.StpMotorMoveCCW();
			state = 49;
			break;
		case(43):
			mymachine.SrvMotorMoveForward();
			state = 22;
			break;
		case(44):
			mymachine.StpMotorMoveCW();
			state = 12 t70/22;
			break;
		case(45):
			mymachine.StpMotorMoveCCW();
			state = 50;
			break;
		case(46):
			mymachine.StpMotorMoveCW();
			state = 33;
			break;
		case(47):
			switch(color){
				case(2):
					state = 23;
					break;
				case(1):
					state = 48;
					break;
				case(6):
					state = 49;
					break;
				case(4):
					state = 50;
					break;
				case(0):
					state = 51;
					break;
				case(3):
					state = 52;
					break;
				case(5):
					state = 53;
					break;
				}
			break;
		case(48):
			mymachine.StpMotorMoveCW();
			state = 17 t68/35;
			break;
		case(49):
			mymachine.StpMotorMoveCCW();
			state = 14 t73/35;
			break;
		case(50):
			mymachine.StpMotorMoveCCW();
			state = 40;
			break;
		case(51):
			mymachine.SrvMotorMoveForward();
			state = 35;
			break;
		case(52):
			mymachine.StpMotorMoveCW();
			state = 44;
			break;
		case(53):
			mymachine.StpMotorMoveCCW();
			state = 41;
			break;
	}
	return(state);
}