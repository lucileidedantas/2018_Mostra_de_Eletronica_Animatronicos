//código para dois servos moverem em 180º simutâneos 
#include <robo_hardware2.h>
#include <Servo.h>

Servo servo1;  
Servo servo2;
int pos = 0;    // posicao do servo;
float valorSensorMaisEsq;

void setup() {
 servo1.attach(9);  // attaches the servo on pin 9 to the servo object
 servo2.attach(9);
 robo.configurar(false);
} 
 

void loop() {
 
valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();

Serial.print("Sensores refletancia: +esq  ");
Serial.println(valorSensorMaisEsq);

delay(1000);
     
 if(valorSensorMaisEsq>90 ){  //Com movimento mantem o o servo em movimento.
   
   for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
  
    // in steps of 1 degree
    servo1.write(pos);             
    servo2.write(pos);              
    delay(4);                         
  }
 }
 }
 
 
