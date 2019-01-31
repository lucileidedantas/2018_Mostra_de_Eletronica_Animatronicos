// inclusão das bibliotecas necessarias no código
#include <robo_hardware2.h> 
#include <Servo.h>

// CRIAR OBJETOS DA CLASS SERVO
Servo garra;
Servo calda;

/******  PINAGUEM ********/
//  SONAR_TRIGGER_FRONTAL  uno-A4;
//  SONAR_ECHO_FRONTAL     uno-A5; 

const int pinRed = 7;  // pino para controlar a cor vermelha dos leds 
const int pinBlue = 6; // pino para controlar a cor vermelha dos leds


/***
 * método responsavel por atacar o objeto encontrado
 * seurando-le com a garra e atacando com a calda 
 */

void atacar (){
   digitalWrite (pinBlue, LOW);  
   garra.write (60); 
   delay (500);

   calda.write (0);
   delay (500);
   
   for (int i = 0; i <= 70; i ++){
       calda.write (i);
       delay (20);
   }
   
   delay (1000);
   piscarLed (3);
}



/****
 * método responsavel por fazer o led piscar
 * parametro é o total de vezes que o led deve piscar
 * na cor vermelha e azul juntas
 */
void piscarLed (int num){
   for (int i = 0; i < num; i ++){   
        digitalWrite (pinBlue, HIGH);
        digitalWrite (pinRed, HIGH);
        delay (100);
       
        digitalWrite (pinBlue, LOW);
        digitalWrite (pinRed, LOW);
        delay (100);
   }
}


/*** 
 * movimenta a calda como modo de defesa 
 * portanto não é um movimento de ataque
 */
void mexerCalda (){
   for (int i = 70; i >= 50; i --){
      calda.write (i);
      delay (20);
   }
   for (int i = 50; i <= 70; i ++){
      calda.write (i);
      delay (20);
   }   
}


// RECEBE O VALOR DA DISTANCIA ATUAL DO SONAR
float valorSensorFrontal;


void setup(){
  Serial.begin(9600);
  robo.configurar(false);

  // seta os pinos da cor azul e vermelha dos leds RGB
  pinMode (OUTPUT,pinRed);
  pinMode (OUTPUT,pinBlue);
  
  // seta a pinaguem para cada servo 
  garra.attach (9);
  calda.attach (10);

  // posição em graus para iniciar os servos
  garra.write (0); 
  calda.write (70); 
}



void loop(){
  //FUNCAO PARA LER VALOR DO SENSOR FRONTAL
  valorSensorFrontal = robo.lerSensorSonarFrontal(); 

  digitalWrite (pinBlue, HIGH);
  digitalWrite (pinRed, HIGH);
  mexerCalda ();        
  
  if (valorSensorFrontal <= 10){
     Serial.println("DISTANCIA MINIMA");
     atacar ();
  }
  else {
     Serial.println(valorSensorFrontal);
     garra.write (0);
  }
  delay(500);
}
