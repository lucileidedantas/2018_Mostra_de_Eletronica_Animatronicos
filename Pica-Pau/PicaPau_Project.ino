
#include <robo_hardware2.h> 
#include <Servo.h>

float valorSensorMaisEsq = A0;
int leds = 7;
int buzzer = 10;
Servo myservo;
int pos = 0;

void setup(){
	Serial.begin(9600);
	robo.configurar(false);
  myservo.attach(9);
}

void loop(){
	valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq(); //le um valor do sensor. O sensor retornar um valor de 0 100
 
  if(valorSensorMaisEsq > 35 ){ //verifica se o valor do sensor é maior que 35(não tem nada na frente do sensor)
    for(int x = 0; x < 10; x++){ //repete 10 vezes e para
      ////////////////////////////LEDS/////////////////////////////////
      for(int x = 0; x < 3; x++){
        digitalWrite(leds, HIGH);
        delay(100);
        digitalWrite(leds, LOW);
        delay(100);
      }
      //////////////////////////SERVO////////////////////////////////
     for (pos = 90; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 15ms for the servo to reach the position
      }
      for (pos = 180; pos >= 90; pos -= 10) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 15ms for the servo to reach the position
      }
      //////////////////////////BUZZER////////////////////////////////
      tone(buzzer,780,20);
      delay(20);
      tone(buzzer,900,30);
      delay(500);
      }
    }
  	//Impressão dos valores dos sensores
  	Serial.print(valorSensorMaisEsq); //Imprime o valor do sensor pela porta serial
  	Serial.print("; ");
}
