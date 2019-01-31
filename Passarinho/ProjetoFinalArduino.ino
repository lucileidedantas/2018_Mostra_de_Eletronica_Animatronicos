#include <Ultrasonic.h>
#include "pitches.h"
#include <Buzzer.h>
Ultrasonic sonar(12,11);
int distancia; 
int ledOlho1 = 6;
int ledOlho2 = 5;
int buzzer = 2;
// Vetor com as notas na ordem em que devem ser tocadas:
int notas[] = {
 NOTE_A4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_T0, NOTE_G4, NOTE_C4, NOTE_F4, NOTE_E4, NOTE_G4, NOTE_C4, NOTE_F4, NOTE_E3, NOTE_D4, 0
};
int duracao[] = {700, 500, 300, 250, 250, 300, 200, 200, 700, 200, 500, 500, 200, 200, 200, 500, 200, 200, 500};

void setup() {
  //Define o pino 6 como saída DO LED 1
  pinMode(ledOlho1,OUTPUT);
  //Define o pino 5 como saída DO LED 2 
  pinMode(ledOlho2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 distancia = sonar.read();
  Serial.print("Distância em CM: ");
  Serial.println(distancia);
  if((distancia <= 35)&&(distancia > 10)){ 
   digitalWrite(ledOlho1, HIGH);   
   digitalWrite(ledOlho2, HIGH);
   for (int i = 0; notas[i] != 0 ; i++) {
      tone(buzzer, notas[i], duracao[i]);
      delay(duracao[i]);
   }
  }
  else{
    digitalWrite(ledOlho1, LOW);
    digitalWrite(ledOlho2, LOW);
  }
}
