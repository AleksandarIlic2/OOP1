#ifndef _h_Strofa


#define _h_Strofa
#include "Stih.h"

class Strofa {
	

	int kap = 0;
	int trBrojStihova = 0;
protected:
	Stih** nizStihova = nullptr;
	virtual void pisi(ostream& os) const {
		for (int i = 0; i < trBrojStihova; i++)
		{
			os << (*(nizStihova[i])) << endl;
		}
	}
	void kopiraj(const Strofa& s);
	void premesti(Strofa& s);
	void brisi();
public:
	Strofa(int n) : kap(n), nizStihova(nullptr) { 
	nizStihova = new Stih*[kap];
	for (int i = 0; i < kap; i++)
		nizStihova[i] = nullptr;
	};
	Strofa(const Strofa& s);
	Strofa(Strofa&& s);
	Strofa& operator=(const Strofa& s);
	Strofa& operator=(Strofa&& s);
	

	Strofa& operator+=(Stih s);
	Stih& operator[](int indeks);
	const Stih& operator[](int indeks) const;
	Strofa& operator()(int i, int j);
	void operator-();
	int operator+() const;
	virtual bool operator*() const = 0;
	virtual char dohvatiOznaku() const = 0;
	friend ostream& operator<<(ostream& os, const Strofa& s) { s.pisi(os); return os; }
	int dohvatiKapacitet() const { return kap; }
	virtual ~Strofa()
	{
		brisi();
	};

};

#endif 