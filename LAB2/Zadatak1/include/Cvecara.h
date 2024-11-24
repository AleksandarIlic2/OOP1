#ifndef _h_cvecara_h

#define _h_cvecara_h
#include "Buket.h"

class Cvecara
{
	int zarada;
	typedef struct elem
	{
		Buket* buket;
		struct elem* next;
		elem(Buket* zadatiBuket) :buket(zadatiBuket), next(nullptr) {};
		~elem() { buket = nullptr; next = nullptr; }
	}Elem;
	Elem* prvi = nullptr;
	void kopiraj(const Cvecara& cvecara);
	void premesti(Cvecara& cvecara);
	void obrisi();
public:
	Cvecara() { zarada = 1000; }
	void dodajBuket(Buket* buket);
	void prodajBuket(Buket* buket);
	friend ostream& operator<<(ostream& os, const Cvecara& cvecara);
	Cvecara(const Cvecara& cvecara);
	Cvecara(Cvecara&& cvecara);
	Cvecara& operator=(const Cvecara& cvecara);
	Cvecara& operator=(Cvecara&& cvecara);
	~Cvecara();

};

#endif