#include "Kugla.h"

void Kugla::pisi(ostream& os) const
{
	if (velicina == 0)
		os << ".";
	else if (velicina == 1)
		os << "o";
	else if (velicina == 2)
		os << "O";
	else if (velicina == 3)
		os << "( )";
}
