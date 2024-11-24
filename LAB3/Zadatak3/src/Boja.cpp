#include "Boja.h"

bool operator==(const Boja& b1, const Boja& b2)
{
	if (b1.crvena == b2.crvena && b1.plava == b2.plava && b1.zelena == b2.zelena)
		return true;
	return false;
}

Boja operator+(const Boja& b1, const Boja& b2)
{
	return Boja((b1.crvena + b2.crvena) / 2, (b1.zelena + b2.zelena) / 2, (b1.plava + b2.plava) / 2);
}
