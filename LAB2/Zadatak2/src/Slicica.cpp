#include "Slicica.h"

int Slicica::idStat = 0;

ostream& operator<<(ostream& os, const Slicica& sl)
{
	os << "Slicica" << sl.brojSlicice << " - " << sl.naziv << "(" << sl.id << ")" << endl;
	return os;
}
