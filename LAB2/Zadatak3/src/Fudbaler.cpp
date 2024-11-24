#include "Fudbaler.h"

string Fudbaler::svePozicije[4] = { "GK", "DEF", "MID", "FWD" };

ostream& operator<<(ostream& os, const Fudbaler& fudbaler)
{
	os << fudbaler.ime << "(" << Fudbaler::svePozicije[fudbaler.dohvatiPozociju()] << ")" << ": " << fudbaler.nazivRep << endl;
	return os;
}


