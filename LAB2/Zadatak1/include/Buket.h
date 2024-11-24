#ifndef _h_Buket_h


#define _h_Buket_h
#include "Cvet.h"

class Buket
{ 
	struct Elem
	{
		Cvet* cvet;
		Elem* next;
		Elem() :cvet(nullptr), next(nullptr) {};
		~Elem() { cvet = nullptr; next = nullptr; }
	};
	Elem* prvi = nullptr;
	Elem* vrsteCvetova = nullptr; //
	void kopiraj(const Buket& buket);
	void premesti(Buket& buket);
	void obrisi();
public:
	Buket() {};
	void dodajCvet(Cvet* cvet);
	int nabavnaCenaBuketa() const;
	int prodajnaCenaBuketa() const;
	int zaradaBuketa() const ;
	bool operator>(Buket& b2) const;
	friend ostream& operator<<(ostream& os, const Buket& b1);
	Buket(const Buket& buket);
	Buket(Buket&& buket);
	Buket& operator= (const Buket& buket);
	Buket& operator=(Buket&& buket);
	~Buket();
};

#endif