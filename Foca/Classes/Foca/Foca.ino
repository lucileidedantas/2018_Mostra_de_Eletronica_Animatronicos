#include "Rfid.h"
#include "Servos.h"
#include "Leds.h"

#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

// RFID

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

// FOTORESISTOR

#define LDR A0
#define LDR_MIN 100

MFRC522 mfrc522(SS_PIN, RST_PIN); 

Servo servoEsq, servoDir;

Led leds(7,8);

void setup() {

	servoEsq.attach(6);
	servoDir.attach(5);

	pinMode(LDR, INPUT);

	SPI.begin();
	mfrc522.PCD_Init();
	mfrc522.PCD_DumpVersionToSerial();

}

Rfid rfid(mfrc522);
Servos servos(servoEsq, servoDir);

void loop() {

	if (analogRead(LDR) < LDR_MIN) { // quando o dedo for colocado
		leds.piscar(3,10);
 		servos.tremer(5); // treme 5 vezes
 		return;
	} 
	else if ( ! mfrc522.PICC_IsNewCardPresent()) {
    	return;
  	}
  	else if ( ! mfrc522.PICC_ReadCardSerial()) {
    	return;
  	}
  	else if (rfid.tagDefault()) {
  		leds.desligar();
  		servos.deitar();
  	} 
  	else if (rfid.tagForro()) {
  		leds.piscar(3);
  		leds.ligar();
  		servos.dancarForro();
  	}
  	else if (rfid.tagRap()) {
  		leds.piscar(3);
  		leds.ligar();
  		servos.dancarRap();
  	}
  	else if (rfid.tagCarrinho()) {
  		leds.piscar(3);
  		leds.ligar();
  		servos.carrinho();
  	}

}
