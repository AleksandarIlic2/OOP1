#include "Stamparija.h"


Slicica* Stamparija::stampajSlicicu(int brojSlicice)
{
	if (brojSlicice > n || brojSlicice < 0)
		return nullptr;
	return new Slicica(brojSlicice, nizNaziva[brojSlicice]);
}

Stamparija::Stamparija(string* naziv, int dimenzija)
{
	n = dimenzija;
	nizNaziva = new string[dimenzija];
	for (int i = 0; i < dimenzija; i++)
		nizNaziva[i] = naziv[i];
}