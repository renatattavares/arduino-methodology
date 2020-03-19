// Include libraries
#include "SortingMachineLib.h"

SortingMachine mymachine;

int color, state;

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
  state = 0;
}

void loop(){
  state = Automata(state);
}

int Automata (int state){
	switch(state){
		case(0):
			state = 1;
			break;
		case(1):
			state = 2;
			break;
		case(2):
			color = get_color();
			switch(color){
				case(1):
					state = 0;
				case(2):
					state = 3;
				case(3):
					state = 4;
				case(4):
					state = 5;
				case(5):
					state = 6;
				case(6):
					state = 7;
				case(7):
					state = 8;
				}
			break;
		case(3):
			state = 9;
			break;
		case(4):
			state = 10;
			break;
		case(5):
			state = 11;
			break;
		case(6):
			state = 12;
			break;
		case(7):
			state = 13;
			break;
		case(8):
			state = 1;
			break;
		case(9):
			state = 14;
			break;
		case(10):
			state = 15;
			break;
		case(11):
			state = 16;
			break;
		case(12):
			state = 17;
			break;
		case(13):
			state = 18;
			break;
		case(14):
			state = 19;
			break;
		case(15):
			state = 20;
			break;
		case(16):
			state = 21;
			break;
		case(17):
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
			color = get_color();
			switch(color){
				case(1):
					state = 10;
				case(2):
					state = 27;
				case(3):
					state = 28;
				case(4):
					state = 29;
				case(5):
					state = 30;
				case(6):
					state = 31;
				case(7):
					state = 32;
				}
			break;
		case(23):
			color = get_color();
			switch(color){
				case(1):
					state = 9;
				case(2):
					state = 11;
				case(3):
					state = 33;
				case(4):
					state = 34;
				case(5):
					state = 35;
				case(6):
					state = 36;
				case(7):
					state = 37;
				}
			break;
		case(24):
			color = get_color();
			switch(color){
				case(1):
					state = 16;
				case(2):
					state = 38;
				case(3):
					state = 39;
				case(4):
					state = 40;
				case(5):
					state = 41;
				case(6):
					state = 42;
				case(7):
					state = 43;
				}
			break;
		case(25):
			color = get_color();
			switch(color){
				case(1):
					state = 44;
				case(2):
					state = 45;
				case(3):
					state = 46;
				case(4):
					state = 47;
				case(5):
					state = 48;
				case(6):
					state = 49;
				case(7):
					state = 50;
				}
			break;
		case(26):
			state = 51;
			break;
		case(27):
			state = 3;
			break;
		case(28):
			state = 17;
			break;
		case(29):
			state = 47;
			break;
		case(30):
			state = 17;
			break;
		case(31):
			state = 7;
			break;
		case(32):
			state = 52;
			break;
		case(33):
			state = 18;
			break;
		case(34):
			state = 40;
			break;
		case(35):
			state = 6;
			break;
		case(36):
			state = 18;
			break;
		case(37):
			state = 53;
			break;
		case(38):
			state = 19;
			break;
		case(39):
			state = 19;
			break;
		case(40):
			state = 54;
			break;
		case(41):
			state = 55;
			break;
		case(42):
			state = 56;
			break;
		case(43):
			state = 37;
			break;
		case(44):
			state = 57;
			break;
		case(45):
			state = 20;
			break;
		case(46):
			state = 20;
			break;
		case(47):
			state = 58;
			break;
		case(48):
			state = 59;
			break;
		case(49):
			state = 31;
			break;
		case(50):
			state = 32;
			break;
		case(51):
			color = get_color();
			switch(color){
				case(1):
					state = 54;
				case(2):
					state = 55;
				case(3):
					state = 57;
				case(4):
					state = 60;
				case(5):
					state = 61;
				case(6):
					state = 62;
				case(7):
					state = 63;
				}
			break;
		case(52):
			state = 1;
			break;
		case(53):
			state = 1;
			break;
		case(54):
			state = 64;
			break;
		case(55):
			state = 48;
			break;
		case(56):
			state = 18;
			break;
		case(57):
			state = 65;
			break;
		case(58):
			state = 26;
			break;
		case(59):
			state = 17;
			break;
		case(60):
			state = 26;
			break;
		case(61):
			state = 26;
			break;
		case(62):
			state = 42;
			break;
		case(63):
			state = 50;
			break;
		case(64):
			state = 20;
			break;
		case(65):
			state = 19;
			break;
	}
	return(state);
}