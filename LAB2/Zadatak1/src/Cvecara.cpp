#include "Cvecara.h"

void Cvecara::dodajBuket(Buket* buket)
{	
	double procenat = (double)((double)buket->zaradaBuketa() / buket->nabavnaCenaBuketa()) * 100;
	if (procenat > 20)
	{
		Elem* pom = this->prvi;
		Elem* novi = new Elem(buket);		
		if (prvi == nullptr)
		{
			this->prvi = novi;
		}
		else
		{
			pom = this->prvi;
			if (buket->prodajnaCenaBuketa() < pom->buket->prodajnaCenaBuketa())
			{ 
				novi->next = pom; 
				this->prvi = novi;
				this->zarada = this->zarada - buket->nabavnaCenaBuketa();
				return;
			}
			while (pom->next != nullptr && *(buket) > *(pom->next->buket))
			{
				pom = pom->next;
			}
			novi->next = pom->next;
			pom->next = novi;
		}
		this->zarada = this->zarada - buket->nabavnaCenaBuketa();
	}	
}

void Cvecara::prodajBuket(Buket* buket) 
{
	Elem* no = nullptr;
	Elem* pom = prvi;
	if (!prvi) return;
	if (!(*(prvi->buket) > * (buket)) && !(*(buket) > * (prvi->buket))) {
		prvi = prvi->next;
		delete pom;
	}
	else
	{
		while (pom->next != nullptr) {
			if (!(*(pom->next->buket) > * (buket)) && !(*(buket) > * (pom->next->buket))) {
				Elem* tmp = pom->next;
				pom->next = pom->next->next;
				delete tmp;
				break;
			}
			pom = pom->next;
		}
	}	

	this->zarada = this->zarada + buket->prodajnaCenaBuketa();
}

void Cvecara::kopiraj(const Cvecara& cvecara)
{
	this->zarada = 1000;
	Elem* pom = cvecara.prvi;
	while (pom != nullptr)
	{
		dodajBuket(pom->buket);
		pom = pom->next;
	}
}
void Cvecara::premesti(Cvecara& cvecara)
{
	this->zarada = cvecara.zarada;
	this->prvi = cvecara.prvi;
}

void Cvecara::obrisi()
{
	Elem* pom = this->prvi;
	while (pom != nullptr)
	{
		prvi = prvi->next;
		delete pom;
		pom = prvi;
	}
	prvi = nullptr;
}

Cvecara::Cvecara(const Cvecara& cvecara)
{
	kopiraj(cvecara);
}

Cvecara::Cvecara(Cvecara&& cvecara)
{
	premesti(cvecara);
}

Cvecara& Cvecara::operator=(const Cvecara& cvecara)
{
	if (this != &cvecara)
	{
		obrisi();
		kopiraj(cvecara);
	}
	return *this;
}

Cvecara& Cvecara::operator=(Cvecara&& cvecara)
{
	if (this != &cvecara)
	{
		obrisi();
		premesti(cvecara);
	}
	return *this;
}
ostream& operator<<(ostream& os, const Cvecara& cvecara)
{
	os << "zarada=" << cvecara.zarada << "RSD" << endl;
	Cvecara::Elem* pom = cvecara.prvi;
	while (pom != nullptr)
	{
		os << *(pom->buket) << endl;
		pom = pom->next;
	}	
	return os;
}
Cvecara::~Cvecara()
{
	obrisi();
}
