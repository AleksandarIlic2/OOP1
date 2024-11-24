#include "Buket.h"

void Buket::dodajCvet(Cvet* cvet)
{
	Buket::Elem* pom = this->prvi;
	Buket::Elem* novi = new Buket::Elem();
	novi->next = nullptr;
	novi->cvet = cvet;
	if (prvi == nullptr)
	{		
		this->prvi = novi;		
	}
	else
	{		
		while (pom->next != nullptr && !((*pom->next->cvet) == *cvet))
		{
			pom = pom->next;
		}
		novi->next = pom->next;
		pom->next = novi;		
	}
}

ostream& operator<<(ostream& os, const Buket& b1)
{
	Buket::Elem* pom = b1.prvi;
	os << "(";
	Buket::Elem* trenutni = b1.prvi; 
	while (pom != nullptr)
	{
		if (pom->next != nullptr)
			os << *(pom->cvet) << ",";
		else
			os << *(pom->cvet);
		pom = pom->next;
		while (pom != nullptr && *(pom->cvet) == *(trenutni->cvet))
		{
			pom = pom->next;
		}
		trenutni = pom;
	}	
	os << ")" << b1.prodajnaCenaBuketa() << "RSD" << endl;
	return os;
}

int Buket::nabavnaCenaBuketa() const
{
	Elem* pom = this->prvi;
	int nabavna = 0;
	while (pom != nullptr)
	{
		if(pom->cvet != nullptr) nabavna += pom->cvet->dohvatiNabavnuCenu();
		pom = pom->next;
	}
	return nabavna;
}

int Buket::prodajnaCenaBuketa() const
{
	Elem* pom = this->prvi;
	int prodajna = 0;
	while (pom != nullptr)
	{
		if (pom->cvet != nullptr) prodajna += pom->cvet->dohvatiProdajnuCenu();
		pom = pom->next;
	}
	return prodajna;
}

int Buket::zaradaBuketa() const
{
	return prodajnaCenaBuketa() - nabavnaCenaBuketa();
}



bool Buket::operator>(Buket& b1) const 
{	
	return (this->prodajnaCenaBuketa() > b1.prodajnaCenaBuketa());
}
void Buket::kopiraj(const Buket& buket)
{
	Elem* pom = buket.prvi;
	while (pom != nullptr)
	{
		dodajCvet(pom->cvet); 
		pom = pom->next;
	}
}

void Buket::premesti(Buket& buket)
{
	this->prvi = buket.prvi;
	buket.prvi = nullptr;
}

void Buket::obrisi()
{
	Elem* pom = prvi;
	while (pom != nullptr)
	{
		prvi = prvi->next;
		delete pom;
		pom = prvi;
	}
	prvi = nullptr;
}
Buket::Buket(const Buket& buket) 
{
	kopiraj(buket);
}
Buket::Buket(Buket&& buket)
{
	premesti(buket);
}

Buket& Buket::operator=(const Buket& buket)
{
	if (this != &buket)
	{
		obrisi();
		kopiraj(buket);
	}
	return *this;
}

Buket& Buket::operator=(Buket&& buket)
{
	if (this != &buket)
	{
		obrisi();
		premesti(buket);
	}
	return *this;
}

Buket::~Buket()
{
	obrisi();
}