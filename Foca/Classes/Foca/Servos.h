#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>

class Servos {
	
	public:

		Servos(Servo servoEsq, Servo servoDir);

		void deitar();

		void andar();
		void tremer(int vezes);
		void acenar();

		void dancarRap();
		void dancarForro();

		void carrinho();

	private:

		Servo servoEsq, servoDir;

		void dancarA();
		void dancarB();
		void flutuar();


		void moveA();
		void moveB();
		void moveC();
		void moveD();

		int c(int ang);

};

#endif