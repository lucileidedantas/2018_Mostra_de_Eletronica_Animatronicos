#include "Rfid.h"

Rfid::Rfid(MFRC522 mfrc522) {
	this->mfrc522 = mfrc522;
}

bool Rfid::tagDefault() { // antigo andar
  return mfrc522.uid.uidByte[0] == 219 && 
     mfrc522.uid.uidByte[1] == 87 &&
     mfrc522.uid.uidByte[2] == 238 &&
     mfrc522.uid.uidByte[3] == 171;
}

bool Rfid::tagForro() { // antigo tremer
  return mfrc522.uid.uidByte[0] == 197 && 
     mfrc522.uid.uidByte[1] == 246 &&
     mfrc522.uid.uidByte[2] == 6 &&
     mfrc522.uid.uidByte[3] == 166;
}

bool Rfid::tagRap() { // antigo dancar
  return mfrc522.uid.uidByte[0] == 107 && 
     mfrc522.uid.uidByte[1] == 181 &&
     mfrc522.uid.uidByte[2] == 213 &&
     mfrc522.uid.uidByte[3] == 229;
}

bool Rfid::tagCarrinho() { // antigo brinchar
  return mfrc522.uid.uidByte[0] == 144 && 
     mfrc522.uid.uidByte[1] == 95 &&
     mfrc522.uid.uidByte[2] == 235 &&
     mfrc522.uid.uidByte[3] == 135;
}