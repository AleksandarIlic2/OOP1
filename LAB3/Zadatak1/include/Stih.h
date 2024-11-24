#ifndef _h_Stih


#define _h_Stih
#include "Rec.h"
#include <string>

class Stih {
	struct Elem {
		Rec* rec;
		Elem* next;
		Elem(Rec* r1) : rec(r1), next(nullptr) {};
		~Elem() { rec = nullptr; next = nullptr; }
	};
	Elem* prvi = nullptr;
	Elem* poslednji = nullptr;
	int brojReci = 0;
	void kopiraj(const Stih& s1);
	void premesti(Stih& s1);
	void brisi();	
public:
	Stih() = default;
	Stih(const Stih& s1);
	Stih(Stih&& s1);
	Stih& operator=(const Stih& s1);
	Stih& operator=(Stih&& s1);
	virtual ~Stih();
	Stih& operator+=(Rec* r);
	int operator+() const { return brojReci; }
	int operator~() const;
	Rec& operator[](int pozicija);
	const Rec operator[] (int pozicija) const;
	void operator()(int pozicija);
	Stih& operator()(Rec& r, int pozicija);
	friend bool operator^(const Stih& s1, const Stih& s2);
	friend istream& operator>>(istream& is, Stih& s);
	friend ostream& operator<<(ostream& os, const Stih& s);
	
};

#endif 