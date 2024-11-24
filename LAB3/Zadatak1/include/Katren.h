#ifndef _h_Katren


#define _h_Katren
#include "Strofa.h"

class Katren: public Strofa
{
protected:
	void pisi(ostream& os) const override { Strofa::pisi(os); }
public:
	Katren(int d = 4) :Strofa(d) { };
	virtual bool operator*() const override;
	virtual char dohvatiOznaku() const override { return 'K'; };
};

#endif 