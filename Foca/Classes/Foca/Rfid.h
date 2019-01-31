#ifndef RFID_H
#define RFID_H

#include <MFRC522.h>

class Rfid {

	public:

		Rfid(MFRC522 mfrc522);

		bool tagDefault();
		bool tagForro();
		bool tagRap();
		bool tagCarrinho();

	private:

		MFRC522 mfrc522;

};

#endif