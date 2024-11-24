#include "Cvet.h"

int Cvet::zarada()
{
	return prodajnaCena - nabavnaCena;
}

bool Cvet::operator==(const Cvet& c2)
{
	return this->naziv == c2.naziv;
}

ostream& operator<<(ostream& os, const Cvet& c1)
{
	os << c1.naziv;
	return os;
}
