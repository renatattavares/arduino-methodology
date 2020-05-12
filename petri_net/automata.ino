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

int Automaton (int state){
	switch(state){
		case(0):
			mymachine.SrvMotorMoveForward();
			state = 1;
			break;
		case(1):
			state = 2;
			break;
		case(2):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 3;
			break;
		case(3):
			switch(color){
				case(0):
					state = 0;
					break;
				case(6):
					state = 4;
					break;
				case(1):
					state = 5;
					break;
				case(2):
					state = 6;
					break;
				case(3):
					state = 7;
					break;
				case(4):
					state = 8;
					break;
				case(5):
					state = 9;
					break;
				}
			break;
		case(4):
			mymachine.StpMotorMoveCW();
			state = 10;
			break;
		case(5):
			mymachine.StpMotorMoveCCW();
			state = 11;
			break;
		case(6):
			mymachine.StpMotorMoveCCW();
			state = 12;
			break;
		case(7):
			mymachine.SrvMotorMoveForward();
			state = 13;
			break;
		case(8):
			mymachine.SrvMotorMoveForward();
			state = 14;
			break;
		case(9):
			mymachine.SrvMotorMoveForward();
			state = 1;
			break;
		case(10):
			mymachine.SrvMotorMoveForward();
			state = 15;
			break;
		case(11):
			mymachine.SrvMotorMoveForward();
			state = 16;
			break;
		case(12):
			mymachine.StpMotorMoveCCW();
			state = 17;
			break;
		case(13):
			mymachine.StpMotorMoveCCW();
			state = 18;
			break;
		case(14):
			mymachine.StpMotorMoveCW();
			state = 19;
			break;
		case(15):
			mymachine.StpMotorMoveCW();
			state = 20;
			break;
		case(16):
			mymachine.StpMotorMoveCCW();
			state = 21;
			break;
		case(17):
			mymachine.SrvMotorMoveForward();
			state = 22;
			break;
		case(18):
			state = 23;
			break;
		case(19):
			state = 24;
			break;
		case(20):
			state = 25;
			break;
		case(21):
			state = 26;
			break;
		case(22):
			mymachine.StpMotorMoveCCW();
			state = 27;
			break;
		case(23):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 28;
			break;
		case(24):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 29;
			break;
		case(25):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 30;
			break;
		case(26):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 31;
			break;
		case(27):
			state = 32;
			break;
		case(28):
			switch(color){
				case(1):
					state = 11;
					break;
				case(2):
					state = 12;
					break;
				case(6):
					state = 33;
					break;
				case(0):
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
		case(29):
			switch(color){
				case(6):
					state = 10;
					break;
				case(0):
					state = 38;
					break;
				case(1):
					state = 39;
					break;
				case(2):
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
		case(30):
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
		case(31):
			switch(color){
				case(2):
					state = 17;
					break;
				case(6):
					state = 51;
					break;
				case(0):
					state = 52;
					break;
				case(1):
					state = 53;
					break;
				case(3):
					state = 54;
					break;
				case(4):
					state = 55;
					break;
				case(5):
					state = 56;
					break;
				}
			break;
		case(32):
			color = mymachine.GetColor();
			mymachine.ShowColor(color);
			Serial.print("\t Cor detectada:");
			PrintColorTxt(color);
			state = 57;
			break;
		case(33):
			mymachine.StpMotorMoveCCW();
			state = 51;
			break;
		case(34):
			mymachine.SrvMotorMoveForward();
			state = 58;
			break;
		case(35):
			mymachine.SrvMotorMoveForward();
			state = 58;
			break;
		case(36):
			mymachine.StpMotorMoveCW();
			state = 8;
			break;
		case(37):
			mymachine.SrvMotorMoveForward();
			state = 59;
			break;
		case(38):
			mymachine.SrvMotorMoveForward();
			state = 60;
			break;
		case(39):
			mymachine.StpMotorMoveCCW();
			state = 5;
			break;
		case(40):
			mymachine.StpMotorMoveCW();
			state = 47;
			break;
		case(41):
			mymachine.StpMotorMoveCCW();
			state = 7;
			break;
		case(42):
			mymachine.SrvMotorMoveForward();
			state = 60;
			break;
		case(43):
			mymachine.SrvMotorMoveForward();
			state = 61;
			break;
		case(44):
			mymachine.SrvMotorMoveForward();
			state = 62;
			break;
		case(45):
			mymachine.SrvMotorMoveForward();
			state = 62;
			break;
		case(46):
			mymachine.StpMotorMoveCW();
			state = 63;
			break;
		case(47):
			mymachine.SrvMotorMoveForward();
			state = 64;
			break;
		case(48):
			mymachine.StpMotorMoveCCW();
			state = 41;
			break;
		case(49):
			mymachine.SrvMotorMoveForward();
			state = 65;
			break;
		case(50):
			mymachine.StpMotorMoveCCW();
			state = 43;
			break;
		case(51):
			mymachine.StpMotorMoveCCW();
			state = 66;
			break;
		case(52):
			mymachine.SrvMotorMoveForward();
			state = 67;
			break;
		case(53):
			mymachine.SrvMotorMoveForward();
			state = 67;
			break;
		case(54):
			mymachine.SrvMotorMoveForward();
			state = 68;
			break;
		case(55):
			mymachine.StpMotorMoveCCW();
			state = 69;
			break;
		case(56):
			mymachine.StpMotorMoveCW();
			state = 37;
			break;
		case(57):
			switch(color){
				case(1):
					state = 63;
					break;
				case(6):
					state = 66;
					break;
				case(4):
					state = 69;
					break;
				case(0):
					state = 70;
					break;
				case(2):
					state = 71;
					break;
				case(3):
					state = 72;
					break;
				case(5):
					state = 73;
					break;
				}
			break;
		case(58):
			state = 23;
			break;
		case(59):
			mymachine.StpMotorMoveCW();
			state = 74;
			break;
		case(60):
			state = 24;
			break;
		case(61):
			mymachine.StpMotorMoveCCW();
			state = 74;
			break;
		case(62):
			state = 25;
			break;
		case(63):
			mymachine.SrvMotorMoveForward();
			state = 75;
			break;
		case(64):
			mymachine.StpMotorMoveCW();
			state = 27;
			break;
		case(65):
			mymachine.StpMotorMoveCCW();
			state = 19;
			break;
		case(66):
			mymachine.SrvMotorMoveForward();
			state = 76;
			break;
		case(67):
			state = 26;
			break;
		case(68):
			mymachine.StpMotorMoveCW();
			state = 18;
			break;
		case(69):
			mymachine.StpMotorMoveCCW();
			state = 49;
			break;
		case(70):
			mymachine.SrvMotorMoveForward();
			state = 77;
			break;
		case(71):
			mymachine.SrvMotorMoveForward();
			state = 77;
			break;
		case(72):
			mymachine.StpMotorMoveCW();
			state = 54;
			break;
		case(73):
			mymachine.StpMotorMoveCCW();
			state = 50;
			break;
		case(74):
			state = 2;
			break;
		case(75):
			mymachine.StpMotorMoveCW();
			state = 21;
			break;
		case(76):
			mymachine.StpMotorMoveCCW();
			state = 20;
			break;
		case(77):
			state = 32;
			break;
	}
	return(state);
}
