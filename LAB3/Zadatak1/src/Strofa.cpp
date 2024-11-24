#include "Strofa.h"

Strofa::Strofa(const Strofa& s)
{
	kopiraj(s);
}

Strofa::Strofa(Strofa&& s)
{
	premesti(s);
}

Strofa& Strofa::operator=(const Strofa& s)
{
	if (this != &s)
	{
		brisi();
		kopiraj(s);
	}
	return *this;
}

Strofa& Strofa::operator=(Strofa&& s)
{
	if (this != &s)
	{
		brisi();
		premesti(s);
	}
	return *this;
}

Strofa& Strofa::operator+=(Stih s)
{
	if (trBrojStihova == kap) { return *this; }
	for (int i = 0; i < kap; i++) 
	{
		if (nizStihova[i] != nullptr && (~(*nizStihova[i]) != (~s))) { return *this; }
		if (nizStihova[i] == nullptr)
		{
			nizStihova[i] = new Stih(s);
			trBrojStihova++;
			return *this;
		}
	}
	return *this;
}

Stih& Strofa::operator[](int indeks)
{
	return *(nizStihova[indeks]);
}

const Stih& Strofa::operator[](int indeks) const
{
	return *(nizStihova[indeks]);
}

Strofa& Strofa::operator()(int i, int j)
{
	Stih* tmp = nizStihova[i];
	nizStihova[i] = nizStihova[j];
	nizStihova[j] = tmp;
	return *this;
}

void Strofa::operator-()
{
	if (trBrojStihova == 0) return;
	delete nizStihova[trBrojStihova - 1];
	nizStihova[trBrojStihova - 1] = nullptr;	
	trBrojStihova--;
}

int Strofa::operator+() const
{
	return trBrojStihova;
}

void Strofa::kopiraj(const Strofa& s)
{
	this->kap = s.kap;
	this->nizStihova = nullptr;
	this->nizStihova = new Stih * [s.kap];
	for (int i = 0; i < s.kap; i++) nizStihova[i] = nullptr;
	for (int i = 0; i < this->kap; i++)
	{
		*(this) += (*(s.nizStihova[i]));
	}
}

void Strofa::premesti(Strofa& s)
{
	this->kap = s.kap;
	this->nizStihova = s.nizStihova;
	s.nizStihova = nullptr;	
}

void Strofa::brisi()
{
	for (int i = 0; i < trBrojStihova; i++)
		delete nizStihova[i];
	delete[] nizStihova;
}
