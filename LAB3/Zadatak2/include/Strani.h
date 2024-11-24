#ifndef _h_Strani


#define _h_Strani
#include <iostream>
#include "Film.h"
using namespace std;
enum Prevod {TITLOVAN, SINHRONIZOVAN};

class Strani: public Film
{
	string zemljaPorekla;
	static char const oznaka = 'S';
	Prevod prevod;
	static string nizPrevoda[];
protected:
	void pisi(ostream& os) const override { Film::pisi(os); os << zemljaPorekla << " " << nizPrevoda[prevod]; }
public:	
	Strani(string nazivFilma, Vreme v1, string zemlja, Prevod p) : Film(nazivFilma, v1), zemljaPorekla(zemlja), prevod(p) {};
	virtual char dohvatiOznaku() const override { return oznaka; }
	virtual Strani* kopija() const { return new Strani(*this); };

};

#endif 