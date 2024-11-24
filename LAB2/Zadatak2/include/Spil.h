#ifndef _h_Spil


#define _h_Spil
#include "Stamparija.h"

class Spil
{
	struct Elem 
	{
		Slicica* slicica;
		Elem* next;
		Elem(Slicica* sl): slicica(sl), next(nullptr){}
		~Elem() { delete slicica; slicica = nullptr; next = nullptr; }
	};
	Elem* prvi = nullptr;
	Elem* tekuci = nullptr;
public:
	friend Spil& operator+=(Spil& sp, Slicica* sl);
	friend bool operator%(Spil& sp, int broj);
	Slicica* izbaciSlicicu(int broj);
	void postaviTekuci() { tekuci = prvi; }
	void pomeriTekuci() { tekuci = tekuci->next; }
	Slicica* dohvatiTekucuSlicicu(){ return tekuci->slicica; }
	bool krajListe();
	Spil(const Spil& sp) = delete;
	Spil& operator=(const Spil& sp) = delete;
	friend ostream& operator<<(ostream& os, const Spil& sp);
	Spil() = default;
	~Spil();



};

#endif