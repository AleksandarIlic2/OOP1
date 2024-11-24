#ifndef _h_Film


#define _h_Film

#include "Vreme.h"
#include "Lista.h"
#include <iostream>
using namespace std;

class Film
{
	Vreme vremeTrajanja;
	string naziv;
	Lista<int> listaOcena;
protected:
	virtual void pisi(ostream& os) const { os << dohvatiOznaku() << " " << naziv << " " << vremeTrajanja << " " << prosecnaOcena() << " "; }
public:
	Film(string nazivFilma, Vreme v1) : naziv(nazivFilma), vremeTrajanja(v1) {};
	Film& oceniFilm(int ocena) { listaOcena += ocena; return *this; }
	Vreme dohvatiVreme() const { return vremeTrajanja; }
	double prosecnaOcena() const;
	virtual char dohvatiOznaku() const = 0;
	virtual Film* kopija() const = 0;
	friend ostream& operator<<(ostream& os, const Film& film) { film.pisi(os); return os; }	
	virtual ~Film() {};
};

#endif 