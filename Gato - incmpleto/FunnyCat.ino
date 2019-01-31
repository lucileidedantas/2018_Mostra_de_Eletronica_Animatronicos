#include "MotorPasso.h"
#include <robo_hardware2.h>
#include "PinagemFunny.h"

MotorPasso mp(64,64);

Servo servo_frontal_dir; 
Servo servo_frontal_esq;
Servo servo_traseiro_dir;
Servo servo_traseiro_esq;

int pos = 0;    // variable to store the servo position
float valorSonarFrontal;
float valorSensorLateral;

void setup() {
  robo.configurar(false);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  
  servo_frontal_dir.attach(PIN_FRENTE_DIR);
  servo_frontal_esq.attach(PIN_FRENTE_ESQ);
  servo_traseiro_dir.attach(PIN_TRASEIRO_DIR);
  servo_traseiro_esq.attach(PIN_TRASEIRO_ESQ);// attaches the servo on pin 9 to the servo object
  
}


void loop() {
  valorSonarFrontal = robo.lerSensorSonarFrontal(); //FUNCAO PARA LER VALOR DO SENSOR FRONTAL
    
  
  if(valorSonarFrontal<=5){
    digitalWrite(LED2,LOW);
    digitalWrite(LED1,HIGH);

    delay(1000);
    servo_frontal_dir.write(90);
    servo_frontal_esq.write(90);
    servo_traseiro_dir.write(90);
    servo_traseiro_esq.write(90);// attaches the servo on pin 9 to the servo object
    delay(1000);
         
    for(int ang = 80; ang > 40; ang--){
       servo_traseiro_esq.write(ang);
       servo_traseiro_dir.write(map(ang, 80, 40, 110, 150));
      delay(40);
    }
    while(robo.lerSensorSonarFrontal() >= 5){
      
        mp.acionarMotoresEmGraus(50,45);
        delay(1000);
        mp.acionarMotoresEmGraus(50,-90);
        delay(1000);
        mp.acionarMotoresEmGraus(50,45);
        delay(1000);

        for(int ang = 90; ang > 10; ang--){
          servo_frontal_esq.write(ang); 
          delay(25); 
        }
        for(int ang = 10; ang < 45; ang++){
          servo_frontal_esq.write(ang); 
          delay(25); 
        }
        for(int ang = 45; ang > 10; ang--){
          servo_frontal_esq.write(ang); 
          delay(25); 
        }
        for(int ang = 10; ang < 90; ang++){
          servo_frontal_esq.write(ang); 
          delay(25); 
        }
      if(robo.lerSensorSonarFrontal() <= 5){
          for(int i = 90; i <= 160; i++){
            servo_frontal_esq.write(map(i, 90, 160, 90, 0));
            servo_frontal_dir.write(i);                   // METODO DEITAR FRENTE
            delay(25);     
          }
          delay(2000);
          for(int i = 160; i >= 90; i--){
            servo_frontal_esq.write(map(i, 90, 160, 90, 0));
            servo_frontal_dir.write(i);                   // METODO LEVANTAR FRENTE
            delay(25);     
          }
          delay(2000);
          break;
      }else{break;}
    }
    
  }
  else{
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    
    servo_frontal_dir.write(100); // frontal direito pra frente
    servo_traseiro_esq.write(80); // traseiro esquerdo pra frente
    servo_traseiro_dir.write(80); //traseiro direito pra tras
    servo_frontal_esq.write(100); //frontal esquerdo pra tras
    delay(800);
    servo_frontal_dir.write(80); // frontal direito pra tras
    servo_traseiro_esq.write(100); // traseiro esquerdo pra tras
    servo_traseiro_dir.write(100); //traseiro direito pra frente
    servo_frontal_esq.write(80); //frontal esquerdo pra frente
    delay(800); 
  }
}
