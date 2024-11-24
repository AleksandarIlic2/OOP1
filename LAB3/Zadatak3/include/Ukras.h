#ifndef _h_Ukras


#define _h_Ukras
#include <iostream>
#include "Boja.h"
using namespace std;

class Ukras
{
	double masa;
	Boja boja;
protected:
	virtual void pisi(ostream& os) const = 0;
public:
	Ukras(double masaUkrasa, Boja bojaUkrasa) : masa(masaUkrasa), boja(bojaUkrasa) {};
	double dohvatiMasu() const { return masa; }
	Boja dohvatiBoju() const { return boja; }
	friend ostream& operator<<(ostream& os, const Ukras& ukras) { ukras.pisi(os); return os; }	
	virtual Ukras* kopija() const = 0;
	virtual ~Ukras() {};
};

#endif 
