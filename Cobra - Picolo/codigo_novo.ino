#include <robo_hardware2.h> 
#include <Servo.h>

 float valorSensorMaisEsq;
 void setup(){
  Serial.begin(9600);
  robo.configurar(false);
   // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3, OUTPUT);
}
void loop(){
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq(); //le um valor do sensor. O sensor retornar um valor de 0 100
  if(valorSensorMaisEsq<=40){
      
      digitalWrite(13, HIGH); 
      digitalWrite(12, HIGH);
      analogWrite(3, 500);
      
      }
  if(valorSensorMaisEsq>=80){
     
      digitalWrite(13, LOW); 
      digitalWrite(12, LOW);
      analogWrite(3, 0);
      }

  //Impressão dos valores dos sensores
  Serial.println("Sensores refletancia ");
  Serial.println(valorSensorMaisEsq); //Imprime o valor do sensor pela porta serial
  delay(1000);

}

