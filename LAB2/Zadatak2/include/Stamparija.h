#ifndef _h_Stamparija


#define _h_Stamparija

#include "Slicica.h"

class Stamparija
{
	string* nizNaziva;
	int n;
public:
	Stamparija(string* naziv, int dimenzija);
	Slicica* stampajSlicicu(int brojSlicice);
	Stamparija(const Stamparija& stamparija) = delete;
	Stamparija& operator=(const Stamparija& stamparija) = delete;
	int ukupanBrojSlicica() const { return n; };
	~Stamparija() { delete [] nizNaziva; nizNaziva = nullptr; }
};

#endif