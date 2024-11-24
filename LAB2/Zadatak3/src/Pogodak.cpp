#include "Pogodak.h"

ostream& operator<<(ostream& os, const Pogodak& pogodak)
{
	os << "[" << pogodak.minut << "']" << " - " << (*pogodak.fudbaler);
	return os;
}
