#include "Stih.h"


Stih& Stih::operator+=(Rec* r)
{
	poslednji = (!prvi ? prvi : poslednji->next) = new Elem(r);
	brojReci++;
	return *this;
}

int Stih::operator~() const
{
	int brojSlogova = 0;
	Elem* pom = prvi;
	while (pom != nullptr)
	{
		brojSlogova += (~(*(pom->rec)));
		pom = pom->next;
	}
	return brojSlogova;
}

Rec& Stih::operator[](int pozicija)
{
	int br = 0;
	Elem* pom = prvi;
	while (1)
	{
		if (br == pozicija)
			break;
		pom = pom->next;
		br++;
	}
	return (*(pom->rec));
}

const Rec Stih::operator[](int pozicija) const
{
	
	int br = 0;
	Elem* pom = prvi;
	while (1)
	{
		if (br == pozicija)
			break;
		pom = pom->next;
		br++;
	}
	return (*(pom->rec));
}

void Stih::operator()(int pozicija)
{
	int br = 0;
	if (pozicija == 0 && prvi == poslednji) { delete prvi; prvi = poslednji = nullptr; brojReci--; return; }	
	if (br == pozicija) { Elem* stari = prvi; prvi = prvi->next; delete stari; brojReci--; return; }
	Elem* pom = prvi;
	while (1)
	{
		if (br + 1 == pozicija)
			break;
		pom = pom->next;
		br++;
	}
	Elem* stari = pom->next;
	pom->next = pom->next->next;
	brojReci--;
	delete stari;
}

Stih& Stih::operator()(Rec& r, int pozicija)
{
	Elem* pom = prvi;
	if (pozicija == 0) { Elem* novi = new Elem(&r); novi->next = prvi; prvi = novi; brojReci++; return *this; }
	if (pozicija <= (brojReci - 1))
	{
		while (pozicija - 1 != 0) { pozicija--; pom = pom->next; }
		Elem* novi = new Elem(&r);
		novi->next = pom->next;
		pom->next = novi;
		brojReci++;
		return *this;
	}
	if (pozicija == (brojReci)) { Elem* novi = new Elem(&r);  poslednji->next = novi; poslednji = novi; brojReci++; return *this; }
	else { return *this; }
	
}

bool operator^(const Stih& s1, const Stih& s2)
{	
	return (s1[+s1 - 1]) ^ (s2[+s2 - 1]);	
}

istream& operator>>(istream& is, Stih& s)
{
	string noviString;
	string pomocniString = "";
	int flag = 0;
	getline(is, noviString);
	for (int i = 0; i < noviString.length(); i++)
	{
		char p = noviString[i];
		if (noviString[i] == ' ') {
			flag = 1;
			s += (new Rec(pomocniString)); pomocniString = "";
		}
		else {
			pomocniString += p;
			if (i == (signed)noviString.length() - 1) { s += new Rec(pomocniString); return is; }
		}
	}
	if (flag == 0) { s += (new Rec(noviString)); }
	return is;
}

ostream& operator<<(ostream& os, const Stih& s)
{
	Stih::Elem* pom = s.prvi;
	while (pom != nullptr)
	{
		os << (*pom->rec) << " ";
		pom = pom->next;
	}
	return os;
}

void Stih::kopiraj(const Stih& s1)
{
	this->brojReci = 0;
	Elem* pom = s1.prvi;
	while (pom != nullptr)
	{
		(*(this)) += pom->rec;
		pom = pom->next;
	}
}

void Stih::premesti(Stih& s1)
{
	this->brojReci = s1.brojReci;
	this->prvi = s1.prvi;
	s1.prvi = nullptr;
}

void Stih::brisi()
{
	Elem* stari = prvi;
	while (prvi)
	{
		prvi = prvi->next;
		delete stari;
		stari = prvi;
	}
}

Stih::Stih(const Stih& s1)
{
	kopiraj(s1);
}

Stih::Stih(Stih&& s1)
{
	premesti(s1);
}

Stih& Stih::operator=(const Stih& s1)
{
	if (this != &s1)
	{
		brisi();
		kopiraj(s1);
	}
	return *this;
}

Stih& Stih::operator=(Stih&& s1)
{
	if (this != &s1)
	{
		brisi();
		premesti(s1);
	}
	return *this;
}

Stih::~Stih()
{
	brisi();
}
