#include <Arduino.h>
#include <SoftwareSerial.h>
#include <robo_hardware2.h>

//Define os pinos para a serial  (RX, TX)
SoftwareSerial minhaSerial(9, 8);

#define LED_CORPO_BRANCO 11 //Corpo Branco
#define LED_CORPO_VERMELHO 12 //Corpo Vermelho
#define LED3 2
#define LED4 3

boolean pisque = false;
void teste();
void controle();

void setup() {
  Serial.begin(9600);
  minhaSerial.begin(9600);
  robo.configurar(false); 
  
  pinMode(LED_CORPO_BRANCO, OUTPUT);
  pinMode(LED_CORPO_VERMELHO, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  digitalWrite(12, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  
  for(int i = 1; i <= 3; i++){
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(12, LOW);
    delay(100);
  }

  digitalWrite(12, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
}

void loop(){ 
  //c.executar();
  //teste();
  controle();
  //toy.corpoBranco();
}

void teste(){
  if(minhaSerial.available()){
    char leitura = minhaSerial.read(); 
    Serial.println(leitura);
    pisque = true;
    //c.executar(); 
  }

  if(pisque){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(20);
    digitalWrite(LED_BUILTIN, LOW);
    delay(20);
  }
}

void controle(){
    char leitura = minhaSerial.read(); 
    Serial.println(leitura);
    
    if (leitura == 'F'){
      
      robo.acionarMotores(50,50);
      Serial.println(F("Andando para Frente"));
    
    } else if (leitura == 'T'){
      robo.acionarMotores(0,0);
      Serial.println(F("Andando para Traz"));
    
    } else if (leitura == 'E'){
      robo.acionarMotores(0,50);
      Serial.println(F("Girando para a Esquerda"));
    
    } else if (leitura == 'D'){
      robo.acionarMotores(50,0);
      Serial.println(F("Girando para a Direita"));
    
    } else if (leitura == 'P'){
        Serial.println(F("Sem Movimento"));
        robo.acionarMotores(0,0);
    
    } else if(leitura == 'C'){
      leitura = 'P';
      robo.acionarMotores(0,0);
      digitalWrite(12, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);

      robo.acionarMotores(50,50);      
      
      for(int i = 1; i <= 10; i++){
        digitalWrite(12, HIGH);
        delay(40);
        digitalWrite(12, LOW);
        delay(40);
        if(i == 3){
          robo.acionarMotores(0,0);
        }
      }

    
      digitalWrite(12, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);   

       
    /*
    } else if (leitura = 'C' ){
      
      robo.acionarMotores(0,0);
      delay(1000);
      robo.acionarMotores(50,50);
      delay(100);
      robo.acionarMotores(0,0);
      
      for(int i = 1; i <= 3; i++){
        digitalWrite(12, HIGH);
        delay(100);
        digitalWrite(12, LOW); 
      }
    } else if (leitura = 'L' ){
      robo.acionarMotores(0,0);
      delay(500);
      robo.acionarMotores(0,50);
      delay(50);
      robo.acionarMotores(0,0);
      delay(500);
      
      for(int i = 1; i <= 5; i++){
        robo.acionarMotores(0,-50);
        delay(50);
        robo.acionarMotores(0,0);
        delay(50); 
      }
      delay(300);

      robo.acionarMotores(0, 50);
      delay(100);
      robo.acionarMotores(0, 0);
    */
    } else {
        //motores
        //robo.acionarMotores(0,0);
        Serial.println(F("Nenhum Comando Recebido"));
    }
}
