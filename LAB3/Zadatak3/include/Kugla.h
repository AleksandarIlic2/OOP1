#ifndef _h_Kugla


#define _h_Kugla

#include "Ukras.h"
enum Velicina {MALA, SREDNJA, VELIKA, NAJVECA};

class Kugla: public Ukras {
	Velicina velicina;
protected:
	void pisi(ostream& os) const override;
public:
	Kugla(double masaUkrasa, Boja bojaUkrasa, Velicina v) : Ukras(masaUkrasa, bojaUkrasa), velicina(v) {};
	Kugla* kopija() const { return new Kugla(*this); }
};

#endif 