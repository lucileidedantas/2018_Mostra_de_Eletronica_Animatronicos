#include "Servos.h"

Servos::Servos(Servo servoEsq, Servo servoDir) {

	this->servoEsq = servoEsq;
	this->servoDir = servoDir;
	
}

void Servos::deitar() {
	servoEsq.write(c(170));
	servoDir.write(170);
}

void Servos::andar() {

	for(int j = 0; j < 20; j++) {
	
	  servoDir.write(30);
	  delay(150);
	  servoDir.write(70);;
	  delay(100);

	  servoEsq.write(c(70));
	  delay(100);
	  servoEsq.write(c(30));
	  delay(150);
	  
	}  

}

void Servos::tremer(int vezes) {

	for (int i = 0; i < vezes; i++) {

		// DIREITO
		for (int x = 70; x <= 90; x++) {
			servoDir.write(x);
			delay(1);
		}

		// ESQUERDO
		for (int x = 90; x >= 70; x--) {
			servoEsq.write(x);
			delay(1);
		} 	
	}

}

void Servos::dancarForro() {
	for (int i = 0; i < 2; i++) {

	    for(int j = 0; j < 5; j++) {
	  
	      moveB();
	      moveB();
	      moveC();
	      moveC();
	  
	      servoEsq.write(90);
	      servoDir.write(90);
	      delay(200);
	      
	    }
	  
	    servoEsq.write(c(50));
	    servoDir.write(50);
	  
	    delay(300);
	  
	    for(int j = 0; j < 20; j++) {
	    
	      servoDir.write(c(130));
	      delay(100);
	      servoDir.write(c(110));
	      delay(150);
	      servoEsq.write(110);
	      delay(100);
	      servoEsq.write(130);
	      delay(150);
	      
	    }  
	  }
}


void Servos::dancarRap() {
  
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 11; j++) {
		  dancarA();
		  delay(10);
		  dancarB();
		}

		flutuar();
		delay(1000);

		for (int i = 0; i < 3; i++) {
		  moveA();
		}
		
		delay(100);

		tremer(10);

		for(int j = 0; j < 5; j++) {
		  moveA();
		  moveB();
		  delay(50);  
		}

		tremer(20);

		flutuar();
		delay(1000);

		for (int j = 0; j < 2; j++) {
		  dancarA();
		  delay(300);
		} 

		tremer(30);
		

	}


	flutuar();
	delay(1000);

	for (int i = 0; i < 3; i++) {
	moveA();
	}

	delay(500);

	for (int i = 0; i < 3; i++) {
	moveA();
	}

	flutuar();
	delay(1000);


	servoEsq.write(90);
	servoDir.write(90);

	delay(300);

	acenar();

}

void Servos::carrinho() {

	delay(4000);

	servoEsq.write(c(2));
	servoDir.write(2);

	delay(4000);

	tremer(30);

}

void Servos::dancarA() {

	// DIREITO
	for (int x = 100; x <= 170; x++) {
	  servoDir.write(x);
	  delay(4);
	}

	// ESQUERDO
	
	for (int x = 100; x <= 170; x++) {
	  servoEsq.write(c(x));
	  delay(4);
	}


}

void Servos::dancarB() {

  // DIREITO
  for (int x = 170; x >= 100; x--) {
    servoDir.write(x);
    delay(8);
  }

  // ESQUERDO
  
  for (int x = 100; x >= 80; x--) {
    servoEsq.write(x);
    delay(4);
  }  

}

void Servos::flutuar() {

  servoEsq.write(c(2));
  servoDir.write(2);

}

void Servos::acenar() {
  // DIREITO

  servoEsq.write(c(50));

  for(int i = 50; i <= 80; i++) {
  	servoEsq.write(c(i));
  	delay(10);
  }

  for(int i = 80; i >= 50; i--) {
  	servoEsq.write(c(i));
  	delay(10);
  }
  
}

void Servos::moveA() {

  servoEsq.write(c(30));  
  servoDir.write(30);
  delay(300);
  servoEsq.write(c(90));
  servoDir.write(90);
  delay(150);

}

void Servos::moveB() {

  servoEsq.write(c(90));  
  servoDir.write(60);
  delay(300);
  servoEsq.write(90);
  servoDir.write(90);
  delay(150);

  

}

void Servos::moveC() {

  servoEsq.write(c(70));  
  servoDir.write(100);
  delay(300);
  servoEsq.write(c(90));
  servoDir.write(90);
  delay(150);

}

void Servos::moveD() {
	servoEsq.write(c(50));

	delay(100);

	for(int i = 0; i < 2; i++) {
	  for (int x = 90; x <= 170; x++) {
	    servoDir.write(x);
	  }  
	}

	servoEsq.write(90);
	servoDir.write(90);
}

int Servos::c(int ang) {
	return 180 - ang;
}

