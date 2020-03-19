/*  
 *  Universidade Federal de Pernambuco
 *  Departamento de Engenharia Mecânica
 *  Autor: Victor Gomes Cardoso
 *  Adaptação: Renata Tavares
 *  Última atualização: 11/12/19
 *  Descrição: Implementação do autômato de template "Controle_Serial" do arquivo mm_teste.xml 
 *  desenvolvido no software UPPAAL para modelagem do Separador de MM com funcionamento serial.
 */
 
// Include libraries
#include "SortingMachineLib.h"

SortingMachine mymachine;

int color, pos;
int decisao, number;
int esperar, menu;

/*
 *  FUNÇÃO DECISION
 * 
 *  Foi implementada para decidir se o caminho mais curto para o distribuidor 
 *  é seguindo no sentido horário ou anti horário. Para os casos em que o 
 *  número de passos vai ser igual independente do sentido, o sentido anti 
 *  horário foi escolhido como default uma vez que seu tempo de execução é menor.
 *  
 */

int decision(int color, int color_mm){
    
    // Declaração de Variáveis    
    int decision;
    int result;
    int mod;    

    result = color - color_mm;
    
        if (result > 0){
            mod = result;
             
            if (mod <= 3){
                decision = 0; // Backward
            }
            else{    
                decision = 1; // Forward
            }
        }
        
        if (result < 0){
            mod = result*-1;        
            
            if (mod < 3){
                decision = 1; // Foward
            }
            else{
                decision = 0; // Backward
            }
        }
    return (decision); // Retornar valor do inteiro decision
}


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
  menu = 1;
  pos = 4;
}

void loop(){
  menu = Execute(menu);
}

int Execute (int menu){
  switch(menu){
    case(1):
      mymachine.SrvMotorMoveForward();
      menu = 2;
      break;
      
    case(2):
      color = mymachine.GetColor();
      
      mymachine.ShowColor(color);
      Serial.print("\t Cor detectada:");
      PrintColorTxt(color);
      
      menu = 3;
      break;
      
    case(3):
      decisao = decision(pos, color);
      
      if(color == pos){
        number = 1;
      }
      else{
        if(decisao == 0){
          number = 2;
        }
        else{
          number = 3;
        }
      }
      
      switch(number){
        case(1):
          mymachine.SrvMotorMoveForward();
          menu = 2;
          break;
        case(2):          
          mymachine.StpMotorMoveCCW();
          break;
          menu = 3;
        case(3):
          mymachine.StpMotorMoveCW();
          break;
      }
  }
  return(menu); // A função retornará o novo valor do inteiro menu todas as vezes que for
                //executada para que dessa forma os diferentes estados do autômato possam ser executados.
}
