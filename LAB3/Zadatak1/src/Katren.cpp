#include "Katren.h"

bool Katren::operator*() const
{
	if (+(*this) == 4)
	{
		if (*(nizStihova[0]) ^ (*(nizStihova[3])) && (*nizStihova[1]) ^ (*nizStihova[2]))
			return true;
	}
	return false;
}
