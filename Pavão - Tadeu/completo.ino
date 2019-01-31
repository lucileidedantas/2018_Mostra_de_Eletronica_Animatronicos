#include <robo_hardware2.h> 
#include <Servo.h>
//********PINOS PARA SENSORES DE DISTANCIA***********//
//  SONAR_TRIGGER_FRONTAL  uno-A4; mega-16
//  SONAR_ECHO_FRONTAL    uno-A5; mega-17

Servo myservo;
Servo myservo2;
int pos;  
float valorSensorFrontal;
int led;  
  
void setup() {
  Serial.begin(9600);
  myservo.attach(9); // anexa o servo no pino 9 ao servo objeto
  myservo2.attach(11);
  robo.configurar(false);
  p
 nMode (led, OUTPUT);
}

void loop() {
  digitalWrite (led, HIGH);
  valorSensorFrontal = robo.lerSensorSonarFrontal();
 
  
  if (valorSensorFrontal <= 3 ){
    for(pos = 90; pos <= 140; pos+= 1){
    myservo.write(pos); //Servo1 
    myservo2.write(140 - pos); //Servo2 
    delay(150);
    }
    
    delay(3000); //tempo de abertura
    
    for (pos = 140; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    myservo2.write(140 - pos); // tell servo to go to position in variable 'pos'
    delay(150);  // waits 15ms for the servo to reach the position
    Serial.println(valorSensorFrontal);
  }
  


  }
  
}
