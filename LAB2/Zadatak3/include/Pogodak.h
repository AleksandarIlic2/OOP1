#ifndef _h_Pogodak

#define _h_Pogodak
#include "Fudbaler.h"

class Pogodak
{
	Fudbaler* fudbaler;
	int minut;
public:
	Fudbaler* dohvatiFudbalera() { return fudbaler; }
	Pogodak(Fudbaler* strelac, int min) : fudbaler(strelac), minut(min) {};
	friend ostream& operator<<(ostream& os, const Pogodak& pogodak);
};

#endif