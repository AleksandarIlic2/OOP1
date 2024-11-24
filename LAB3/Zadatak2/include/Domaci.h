#ifndef _h_Domaci


#define _h_Domaci
#include "Film.h"

class Domaci: public Film {
	static const char oznaka = 'D';
protected:
	void pisi(ostream& os) const { Film::pisi(os);  }
public:
	Domaci(string nazivFilma, Vreme v1) : Film(nazivFilma, v1) {};
	virtual char dohvatiOznaku() const override { return oznaka; }
	virtual Domaci* kopija() const { return new Domaci(*this); };
};

#endif 