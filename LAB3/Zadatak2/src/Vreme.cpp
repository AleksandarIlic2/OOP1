#include "Vreme.h"

bool operator>(const Vreme& v1, const Vreme& v2)
{
	return v1.minuti > v2.minuti;
}

bool operator<(const Vreme& v1, const Vreme& v2)
{
	return v2.minuti > v1.minuti;
}

ostream& operator<<(ostream& os, const Vreme& v)
{
	return os << setw(2) << setfill('0') << v.minuti / 60 << ":" << setw(2) << setfill('0') << v.minuti % 60;
}

Vreme Vreme::operator+(const Vreme& v2)
{
	Vreme pom((this->minuti + v2.minuti) / 60, (this->minuti + v2.minuti) % 60);	
	return pom;
}
