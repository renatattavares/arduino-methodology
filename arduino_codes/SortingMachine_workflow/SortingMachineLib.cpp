#include "SortingMachineLib.h"
#include <Wire.h>
#include <Servo.h>
#include <Adafruit_TCS34725.h>
#include <CheapStepper.h>

//================= Defining pin numbers =================//
//------- Servo motor----------- //
#define SERVO_PIN 3 
//---------- LED RGB------------ //
#define LED_R 9
#define LED_G 10
#define LED_B 11
//-------- Step motor----------- //
#define STPM_IN1 5
#define STPM_IN2 6
#define STPM_IN3 7
#define STPM_IN4 8
//-------- IR Sensors ---------- //
#define IRS1 A0
#define IRS2 A1
#define IRS3 A2
#define IRS4 A3
//===========================================================//

//=== Defining parameters for color classification ===========//
//=== Specifies the type of candy used in the system ===//
// 0 = Skitles (red,green,blue,yellow,orange and purple)
// 1 = M&Ms (red,green,blue,yellow,orange and brown)
int candy_type = 1;
//===================== Skitles ==============================//
#define Rmean_Red     2325.68
#define Gmean_Red     1925.09
#define Bmean_Red     1581.23

#define Rmean_Green   2087.95
#define Gmean_Green   3113.86
#define Bmean_Green   1765.26

#define Rmean_Blue    1955.46
#define Gmean_Blue    2679.10
#define Bmean_Blue    2502.58

#define Rmean_Yellow  4595.68
#define Gmean_Yellow  4426.56
#define Bmean_Yellow  2176.92

#define Rmean_Orange  4264.13
#define Gmean_Orange  2768.62
#define Bmean_Orange  1856.92

#define Rmean_Purple   1526.64
#define Gmean_Purple   1701.61
#define Bmean_Purple   1436.49

#define Rmean_Empty    2928.18
#define Gmean_Empty    3453.41
#define Bmean_Empty    2734.57

//===================== M&Ms ==============================//
#define Rmean_Red_MM    1856.82     
#define Gmean_Red_MM    1661.25 
#define Bmean_Red_MM    1418.12    

#define Rmean_Green_MM   1620.12
#define Gmean_Green_MM   2347.42
#define Bmean_Green_MM   1535.25

#define Rmean_Blue_MM    1367.42
#define Gmean_Blue_MM    2059.50
#define Bmean_Blue_MM    2315.87

#define Rmean_Yellow_MM  3562.62
#define Gmean_Yellow_MM  3442.70
#define Bmean_Yellow_MM  1862.40

#define Rmean_Orange_MM  3076.77
#define Gmean_Orange_MM  1927.45
#define Bmean_Orange_MM  1518.47

#define Rmean_Brown_MM   1406.75
#define Gmean_Brown_MM   1587.02
#define Bmean_Brown_MM   1319.87

#define Rmean_Empty    2928.18
#define Gmean_Empty    3453.41
#define Bmean_Empty    2734.57

//===========================================================//

//=================== RGB LED defines =======================//
#define RED 1
#define GREEN 2
#define BLUE  3
#define YELLOW 4
#define ORANGE 5
#define PURPLE 6
#define EMPTY 7
#define BROWN 6
//===========================================================//

//=================== RGB LED defines =======================//
bool  S1,S2,S3;
//===========================================================//

//======= Declaring classes from other libraries =============//
Servo myservo;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
CheapStepper stepper (STPM_IN1,STPM_IN2,STPM_IN3,STPM_IN4); 
//===========================================================//

//====================== Construct ==========================//
SortingMachine::SortingMachine(){
//------ Defining IO pins ---------//
  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_B,OUTPUT);
  pinMode(IRS1,INPUT);
  pinMode(IRS2,INPUT);
  pinMode(IRS3,INPUT);
  pinMode(IRS4,INPUT);
  pinMode(13,OUTPUT);
}
//===========================================================//

//====================== Destruct ===========================//
SortingMachine::~SortingMachine(){
  }
//===========================================================//

void SortingMachine::Initialize(){
  
//--------- Defining Sevo object -----------//
  myservo.attach(SERVO_PIN);
  myservo.write(95);
//------ Inicializing Color Sensor ---------//
  if (tcs.begin()) {
    digitalWrite(13,HIGH);
  }else{
   digitalWrite(13,LOW);
  }
//------ Inicializing Step Motor ---------//
  stepper.setRpm(22); 
 // SortingMachine::StpMotorMoveToInitPos();
}

//================ Servo Motor functions ====================//
// MoveForward: Moves servo motor shaft clockwise until it reaches a 90º multiple position.
void SortingMachine::SrvMotorMoveForward(){
  int servospeed = 13;
  servospeed = map(servospeed,0,100,100,180);
  myservo.write(servospeed);
  delay(500);
  while (!digitalRead(IRS1)){}
  myservo.write(95);  
}

// MoveBackward: Moves servo motor shaft counterclockwise until it reaches a 90º multiple position.
void SortingMachine::SrvMotorMoveBackward(){
  int servospeed = 6;
  servospeed = map(servospeed,0,100,90,0);
  myservo.write(servospeed);
  delay(500);
  while (!digitalRead(IRS1)){}
  myservo.write(95);  
}
//============================================================//

//================ Color Sensor functions ====================//
// GetColor: Return the color code obtained by the color sensor.
int SortingMachine::GetColor(){
  int color = 0;
  float erro_R,erro_G,erro_B,erro_Y,erro_O,erro_P,erro_E;
  uint16_t red, green, blue, c, colorTemp, lux;

  delay(400);
  tcs.getRawData(&red, &green, &blue, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(red, green, blue, c);
  
  lux = tcs.calculateLux(red, green, blue);

  if (candy_type == 0){
    erro_R = sqrt(pow(Rmean_Red-red,2)+pow(Gmean_Red-green,2)+pow(Bmean_Red-blue,2));
    erro_G = sqrt(pow(Rmean_Green-red,2)+pow(Gmean_Green-green,2)+pow(Bmean_Green-blue,2));
    erro_B = sqrt(pow(Rmean_Blue-red,2)+pow(Gmean_Blue-green,2)+pow(Bmean_Blue-blue,2));
    erro_Y = sqrt(pow(Rmean_Yellow-red,2)+pow(Gmean_Yellow-green,2)+pow(Bmean_Yellow-blue,2));
    erro_O = sqrt(pow(Rmean_Orange-red,2)+pow(Gmean_Orange-green,2)+pow(Bmean_Orange-blue,2));
    erro_P = sqrt(pow(Rmean_Purple-red,2)+pow(Gmean_Purple-green,2)+pow(Bmean_Purple-blue,2));
    erro_E = sqrt(pow(Rmean_Empty-red,2)+pow(Gmean_Empty-green,2)+pow(Bmean_Empty-blue,2));

    if((erro_R<erro_G)&&(erro_R<erro_B)&&(erro_R<erro_Y)&&(erro_R<erro_O)&&(erro_R<erro_P)&&(erro_R<erro_E))
      color = RED;
    else if((erro_G<erro_R)&&(erro_G<erro_B)&&(erro_G<erro_Y)&&(erro_G<erro_O)&&(erro_G<erro_P)&&(erro_G<erro_E))
      color = GREEN;
    else if((erro_B<erro_R)&&(erro_B<erro_G)&&(erro_B<erro_Y)&&(erro_B<erro_O)&&(erro_B<erro_P)&&(erro_B<erro_E))
      color = BLUE;
    else if((erro_Y<erro_R)&&(erro_Y<erro_G)&&(erro_Y<erro_B)&&(erro_Y<erro_O)&&(erro_Y<erro_P)&&(erro_Y<erro_E))
      color = YELLOW;
    else if((erro_O<erro_R)&&(erro_O<erro_G)&&(erro_O<erro_B)&&(erro_O<erro_Y)&&(erro_O<erro_P)&&(erro_O<erro_E))
      color = ORANGE;
    else if((erro_P<erro_R)&&(erro_P<erro_G)&&(erro_P<erro_B)&&(erro_P<erro_Y)&&(erro_P<erro_O)&&(erro_P<erro_E))
      color = PURPLE;
    else if((erro_E<erro_R)&&(erro_E<erro_G)&&(erro_E<erro_B)&&(erro_E<erro_Y)&&(erro_E<erro_O)&&(erro_E<erro_P))
      color = EMPTY;    
  }
  else{
    erro_R = sqrt(pow(Rmean_Red_MM-red,2)+pow(Gmean_Red_MM-green,2)+pow(Bmean_Red_MM-blue,2));
    erro_G = sqrt(pow(Rmean_Green_MM-red,2)+pow(Gmean_Green_MM-green,2)+pow(Bmean_Green_MM-blue,2));
    erro_B = sqrt(pow(Rmean_Blue_MM-red,2)+pow(Gmean_Blue_MM-green,2)+pow(Bmean_Blue_MM-blue,2));
    erro_Y = sqrt(pow(Rmean_Yellow_MM-red,2)+pow(Gmean_Yellow_MM-green,2)+pow(Bmean_Yellow_MM-blue,2));
    erro_O = sqrt(pow(Rmean_Orange_MM-red,2)+pow(Gmean_Orange_MM-green,2)+pow(Bmean_Orange_MM-blue,2));
    erro_P = sqrt(pow(Rmean_Brown_MM-red,2)+pow(Gmean_Brown_MM-green,2)+pow(Bmean_Brown_MM-blue,2));
    erro_E = sqrt(pow(Rmean_Empty-red,2)+pow(Gmean_Empty-green,2)+pow(Bmean_Empty-blue,2));

    if((erro_R<erro_G)&&(erro_R<erro_B)&&(erro_R<erro_Y)&&(erro_R<erro_O)&&(erro_R<erro_P)&&(erro_R<erro_E))
      color = RED;
    else if((erro_G<erro_R)&&(erro_G<erro_B)&&(erro_G<erro_Y)&&(erro_G<erro_O)&&(erro_G<erro_P)&&(erro_G<erro_E))
      color = GREEN;
    else if((erro_B<erro_R)&&(erro_B<erro_G)&&(erro_B<erro_Y)&&(erro_B<erro_O)&&(erro_B<erro_P)&&(erro_B<erro_E))
      color = BLUE;
    else if((erro_Y<erro_R)&&(erro_Y<erro_G)&&(erro_Y<erro_B)&&(erro_Y<erro_O)&&(erro_Y<erro_P)&&(erro_Y<erro_E))
      color = YELLOW;
    else if((erro_O<erro_R)&&(erro_O<erro_G)&&(erro_O<erro_B)&&(erro_O<erro_Y)&&(erro_O<erro_P)&&(erro_O<erro_E))
      color = ORANGE;
    else if((erro_P<erro_R)&&(erro_P<erro_G)&&(erro_P<erro_B)&&(erro_P<erro_Y)&&(erro_P<erro_O)&&(erro_P<erro_E))
      color = BROWN;
    else if((erro_E<erro_R)&&(erro_E<erro_G)&&(erro_E<erro_B)&&(erro_E<erro_Y)&&(erro_E<erro_O)&&(erro_E<erro_P))
      color = EMPTY; 
  }  
  return color;
}

//===========================================================//

//==================== RGB LED functions ====================//
// ShowColor: Lights up the RGB LED according the color code received.
void SortingMachine::ShowColor(int color){
  int red_val;
  int green_val;
  int blue_val;
  switch(color){
    case(RED):
      red_val = 255;
      green_val = 0;
      blue_val = 0;
      break;
    case(GREEN):
      red_val = 0;
      green_val = 255;
      blue_val = 0;
      break;
   case(BLUE):
      red_val = 0;
      green_val = 0;
      blue_val = 255;
      break;
    case(YELLOW):
      red_val = 255;
      green_val = 255;
      blue_val = 0;
      break;
    case(ORANGE):
      red_val = 255;
      green_val = 120;
      blue_val = 0;
      break;
    case(PURPLE):
      if (candy_type == 0){
        red_val = 150;
        green_val = 0;
        blue_val = 255;
      }
      else{
        red_val = 128;
        green_val = 43;
        blue_val = 0;
      }
      break;     
    default:
      red_val = 0;
      green_val = 0;
      blue_val = 0;
      break;         
  }
  analogWrite(LED_R,red_val);
  analogWrite(LED_G,green_val);
  analogWrite(LED_B,blue_val);
}
//===========================================================//

//==================== Step Motor functions =================//
void SortingMachine::StpMotorMoveToInitPos(){
  
  S1 = digitalRead(IRS2);
  S2 = digitalRead(IRS3);
  S3 = digitalRead(IRS4);
  
  while(!((!S1)&&(S2)&&(!S3))){
    stepper.moveDegrees (1,2);
    S1 = digitalRead(IRS2);
    S2 = digitalRead(IRS3);
    S3 = digitalRead(IRS4);
  }
  Serial.println("Initial Position accomplished!");
}

void SortingMachine::StpMotorMoveCW(){
  int curpos = StpMotorGetPosition();
  int arrival = curpos+1;
  if (arrival == 7)
    arrival = 1;
  
  S1 = digitalRead(IRS2);
  S2 = digitalRead(IRS3);
  S3 = digitalRead(IRS4);
  bool verify = Check_Sensors(arrival);
  int angular_step = 10;
  while(!verify){
    stepper.moveDegrees (1,angular_step);
    S1 = digitalRead(IRS2);
    S2 = digitalRead(IRS3);
    S3 = digitalRead(IRS4);
    verify = Check_Sensors(arrival); 
    angular_step =1;
    delay(1);
  }
  /*Serial.print("Position ");
  Serial.print(arrival);
  Serial.println(" reached!");*/
}

void SortingMachine::StpMotorMoveCCW(){
  int curpos = StpMotorGetPosition();
  int arrival = curpos-1;
  if (arrival == 0)
    arrival = 6;
  
  S1 = digitalRead(IRS2);
  S2 = digitalRead(IRS3);
  S3 = digitalRead(IRS4);
  bool verify = Check_Sensors(arrival);
  int angular_step = 10;
  while(!verify){
    stepper.moveDegrees (0,angular_step);
    S1 = digitalRead(IRS2);
    S2 = digitalRead(IRS3);
    S3 = digitalRead(IRS4);
    verify = Check_Sensors(arrival); 
    angular_step =1;
    delay(1);
  }
  /*Serial.print("Position ");
  Serial.print(arrival);
  Serial.println(" reached!");*/
}

int SortingMachine::StpMotorGetPosition(){
  int value, output;
  S1 = digitalRead(IRS2);
  S2 = digitalRead(IRS3);
  S3 = digitalRead(IRS4);
  value = S3*4 + S2*2 + S1*1;
  switch(value){
    case 1:
      output = 6;
      break;
    case 2:
      output = 4;
      break;
    case 3:
      output = 3;
      break;
    case 4:
      output = 2;
      break;
    case 5:
      output = 5;
      break;
    case 6:
      output = 1;
      break;
    default:
      output = 0;
      break;
  }
  return output;
}

bool SortingMachine::Check_Sensors (int arrival){
  switch(arrival){
    case(1):
      return (!S1)&&(S2)&&(S3);
      break;
    case(2):
      return (!S1)&&(!S2)&&(S3);
      break;
    case(3):
      return (S1)&&(S2)&&(!S3);
      break;
    case(4):
      return (!S1)&&(S2)&&(!S3);
      break;
    case(5):
      return (S1)&&(!S2)&&(S3);
      break;
     case(6):
      return (S1)&&(!S2)&&(!S3);
      break;
  }  
}

//===========================================================//
