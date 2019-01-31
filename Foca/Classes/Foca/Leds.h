#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>

class Leds {

	public:

	Leds(int pino1, int pino2);

	void piscar(int vezes);
	void piscar(int vezes, int tempo);

	void ligar();
	void desligar();

	private:
		
		int pino1, pino2;
};

#endif