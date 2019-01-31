#include "Leds.h"

Leds::Leds(int pino1, int pino2) {

	this->pino1 = pino1;
	this->pino2 = pino2;
	pinMode(pino1, OUTPUT);
	pinMode(pino2, OUTPUT);

}

void Leds::piscar(int vezes) {

	for (int i = 0; i < vezes; i++) {
		digitalWrite(pino1, !digitalRead(pino1));
		delay(200);
		digitalWrite(pino2, !digitalRead(pino2));
		delay(200);	
	}

}

void Leds::piscar(int vezes, int tempo) {

	for (int i = 0; i < vezes; i++) {
		digitalWrite(pino1, !digitalRead(pino1));
		delay(tempo);
		digitalWrite(pino2, !digitalRead(pino2));
		delay(tempo);	
	}

}

void Leds::ligar() {
	digitalWrite(pino1, HIGH);
	digitalWrite(pino2, HIGH);
}

void Leds::desligar() {
	digitalWrite(pino1, LOW);
	digitalWrite(pino2, LOW);
}