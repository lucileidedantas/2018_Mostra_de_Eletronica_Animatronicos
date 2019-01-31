
#include <robo_hardware2.h> 
#include <Servo.h>

Servo myservo; // Criar servo objeto para controlar um servo
Servo myservo2; // novo objeto para o segundo servo.

int pos = 0; //Variável que armazena a posição do servo
int pos2 = 0;

int ledUm = 11; // O LED 1  está conectado ao pino 11.
int ledDois = 11;  // O LED 2 está conectado ao pino 11.
int servo = 9; 

//********PINOS PARA SENSORES DE COR I2C***********//
//********SENSOR**********************//
//  SCL	uno-A4;
//  SDA	uno-A5;
//  VIN	uno-2;	
//*********PINOS PARA SENSORES DE COR I2C*********//

//  O tipo HSV e formado por tres valores: 
//  float h   //valor varia de 0 ate 359
//  float s   //valor varia de 0 ate 1. Isso inclui: 0.1 0.34 0.73
//  int v     //valor vaira de 0 ate 255

HSV leituraSensorCor; //Declaração de uma variável do tipo RGB

void setup(){
  pinMode (ledUm, OUTPUT);
  pinMode (ledDois, OUTPUT);
  digitalWrite(ledUm, LOW);
  digitalWrite(ledDois,LOW);
  
  Serial.begin(9600);
  myservo.attach(9); // Todos os servos estão no pino 9.
  myservo2.attach(9);
  
  robo.configurar(false);
  robo.habilitaTCS34();
}

void loop(){

  leituraSensorCor = robo.getHSVEsquerdo(); //FUNCAO PARA LER VALOR DO SENSOR LATERAL


  //imprime os 3 valores retornardos pelo sensor cor
  Serial.print("Valor do sensor de cor: ");
  Serial.print(leituraSensorCor.h);
  Serial.print(", ");
  Serial.print(leituraSensorCor.s);
  Serial.print(", ");
  Serial.print(leituraSensorCor.v);

  if (leituraSensorCor.h > 2 && leituraSensorCor.h <= 32 && leituraSensorCor.s > 0.39 && leituraSensorCor.s <= 0.70 && leituraSensorCor.v > 63 && leituraSensorCor.v <= 500){ // Se o valor do sensor com a cor vermelha entrar na condição, os LED's acendem.
  digitalWrite(ledUm, HIGH);
  delay(500);
  digitalWrite(ledUm, LOW);
  delay(250);
  digitalWrite(ledUm, HIGH);
  delay(500);
  digitalWrite(ledUm, LOW);
  delay(250);
  digitalWrite(ledDois, HIGH); 
  delay(500);
  digitalWrite(ledDois, LOW); 
  delay(250);
  digitalWrite(ledDois, HIGH);
  delay(500);
  digitalWrite(ledDois, LOW);
  delay(250);
  }
  else if (leituraSensorCor.h > 80 && leituraSensorCor.h <= 230 && leituraSensorCor.s > 0.12 && leituraSensorCor.s <= 0.48 && leituraSensorCor.v > 140 && leituraSensorCor.v <= 710){ // Se o valor do sensor com a cor azul entrar na condição, movimenta os servos.
      myservo2.write(pos);
      myservo.write(pos);
      delay(5);
      delay(10);
      
      for (pos = 180; pos >= 0; pos--) {
        myservo2.write(pos);
        myservo.write(pos);
        delay(5);
      }
      for (pos = 180; pos >= 0; pos--) {
        myservo2.write(pos);
        myservo.write(pos);
        delay(5);
      }
      for (pos = 180; pos >= 0; pos--) {
        myservo2.write(pos);
        myservo.write(pos);
        delay(5);
      }
      myservo.write(pos);
      myservo2.write(pos);
      
  }
  
  Serial.println();
  delay(500);
}
