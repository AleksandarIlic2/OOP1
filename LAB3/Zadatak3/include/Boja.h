#ifndef _h_Boja


#define _h_Boja
#include <iostream>
#include "Greske.h"
using namespace std;

class Boja {
	int crvena = 0;
	int zelena = 0;
	int plava = 0;
public:
	Boja(int c, int z, int p) {
		if (c < 0 || c > 255 || z < 0 || z > 255 || p < 0 || p > 255) throw GPogresnaBoja();
		crvena = c;
		zelena = z;
		plava = p;
	};
	friend bool operator==(const Boja& b1, const Boja& b2);
	friend Boja operator+(const Boja& b1, const Boja& b2);

};

#endif 
