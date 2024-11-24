#include "Skup.h"
#include <iostream>

Skup& Skup::operator+=(char k)
{
	if ((*this)(k) == true) return *this;
	poslednji = (!prvi ? prvi : poslednji->next) = new Elem(k);
	return *this;
}

bool Skup::operator()(char znak) const
{
	Elem* pom = prvi;
	while (pom != nullptr)
	{
		if (pom->karakter == znak)
			return true;
		pom = pom->next;
	}
	return false;
}

Skup::~Skup()
{
	Elem* stari = prvi;
	while (prvi)
	{
		prvi = prvi->next;
		delete stari;
		stari = prvi;
	}
}
