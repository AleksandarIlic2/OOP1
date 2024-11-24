#include "Spil.h"

Spil& operator+=(Spil& sp, Slicica* sl)
{
	Spil::Elem* pom = sp.prvi;
	Spil::Elem* novi = new Spil::Elem(sl);
	if (sp.prvi == nullptr) { sp.prvi = novi; }
	else
	{
		while (pom->next != nullptr)
		{
			pom = pom->next;
		}
		pom->next = novi;
	}
	return sp;
}

bool operator%(Spil& sp, int broj)
{
	Spil::Elem* pom = sp.prvi;
	while (pom != nullptr)
	{
		if (pom->slicica->dohvatiBrojSlicice() == broj)
			return true;
		pom = pom->next;
	}
	return false;
}

Slicica* Spil::izbaciSlicicu(int broj)
{
	Spil::Elem* pom = prvi;
	Slicica* sl = nullptr;
	if (prvi == nullptr)return nullptr;
	if (prvi->slicica->dohvatiBrojSlicice() == broj)
	{
		sl = prvi->slicica;
		prvi = prvi->next;
		delete pom;		
		return sl;
	}
	else
	{
		while (pom->next != nullptr)
		{
			if (pom->next->slicica->dohvatiBrojSlicice() == broj)
			{
				Elem* tmp = pom->next;
				pom->next = tmp->next;
				sl = tmp->slicica;
				delete tmp;
				break;
			}
			pom = pom->next;
		}
	}
	return sl;	
}

bool Spil::krajListe()
{
	if (tekuci == nullptr)
		return true;
	else
		return false;
}

Spil::~Spil()
{
	Elem* pom = prvi;
	while (pom != nullptr)
	{
		prvi = prvi->next;
		delete pom;
		pom = prvi;
	}
	prvi = nullptr;
	tekuci = nullptr;
}

ostream& operator<<(ostream& os, const Spil& sp)
{
	Spil::Elem* pom = sp.prvi;
	while (pom != nullptr)
	{
		os << *(pom->slicica);
		pom = pom->next;
	}
	os << endl;
	return os;
}