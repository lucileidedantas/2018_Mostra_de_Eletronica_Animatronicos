#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR		uno-A0;	

//*********PINOS PARA SENSORES REFLETANCIA*********//

float valorSensorMaisEsq;
int buzzer = 10;

void setup(){
  pinMode(buzzer,OUTPUT);
	Serial.begin(9600);
	robo.configurar(false);
}

void loop(){
	valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq(); //le um valor do sensor. O sensor retornar um valor de 0 100
	
	//Impressão dos valores dos sensores
	Serial.print("Sensor refletancia: +esq; esq; ");
	Serial.println(valorSensorMaisEsq); //Imprime o valor do sensor pela porta serial
	

	
  if (valorSensorMaisEsq > 40 ) {
    chirp(); 
    delay(500); 
  }
  
  
  

}
void chirp() {  // Bird chirp
  for(uint8_t i=200; i>180; i--)
     playTone(i,9);
}
void playTone(uint16_t tone1, uint16_t duration) {
  if(tone1 < 50 || tone1 > 15000) return;  // these do not play on a piezo
  for (long i = 0; i < duration * 1000L; i += tone1 * 2) {
     digitalWrite(buzzer, HIGH);
     delayMicroseconds(tone1);
     digitalWrite(buzzer, LOW);
     delayMicroseconds(tone1);
  }     
}
