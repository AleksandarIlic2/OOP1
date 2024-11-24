#ifndef _h_Lista


#define _h_Lista
#include <iostream>
#include "Greske.h"
using namespace std;

template<typename T>
class Lista
{
	struct Elem {
		T t;
		Elem* next;
		Elem(T t1) :t(t1), next(nullptr) {};
		~Elem() { next = nullptr; }
	};
	Elem* prvi = nullptr;
	Elem* poslednji = nullptr;
	int brTrenutnih = 0;
	void kopiraj(const Lista& lista);
	void premesti(Lista& lista);
	void brisi();
public:
	Lista() = default;
	Lista(const Lista& lista) { kopiraj(lista); }
	Lista(Lista&& lista) { premesti(lista); }
	Lista& operator=(const Lista& lista)
	{
		if (this != &lista)
		{
			brisi();
			kopiraj(lista);
		}
		return *this;
	}
	Lista& operator=(Lista&& lista)
	{
		if (this != &lista)
		{
			brisi();
			premesti(lista);
		}
		return *this;
	}
	~Lista() { brisi(); }
	Lista& operator+=(T pod)
	{
		poslednji = (!prvi ? prvi : poslednji->next) = new Elem(pod);
		brTrenutnih++;
		return *this;
	}
	int dohvatiBrojTrenutnih() const { return brTrenutnih; }
	T& operator[](int indeks);
	const T& operator[](int indeks) const { return const_cast<Lista&>(*this)[indeks]; }

};

template<typename T>
T& Lista<T>::operator[](int indeks)
{
	if (indeks >= brTrenutnih || indeks < 0 ) throw GPogresanIndeks();
	int br = 0;
	Elem* pom = prvi;
	while (br != indeks) { pom = pom->next; br++; }
	return pom->t;
}
template<typename T>
void Lista<T>::kopiraj(const Lista& lista)
{
	this->brTrenutnih = 0;
	for (int i = 0; i < lista.dohvatiBrojTrenutnih(); i++)
	{
		(*this) += lista[i];
	}
}
template<typename T>
void Lista<T>::premesti(Lista& lista)
{
	this->prvi = lista.prvi;
	this->poslednji = lista.poslednji;
	this->brTrenutnih = lista.brTrenutnih;
	lista.prvi = nullptr;
	lista.poslednji = nullptr;
}

template<typename T>
void Lista<T>::brisi()
{
	Elem* stari = prvi;
	while (prvi)
	{
		prvi = prvi->next;
		delete stari;
		stari = prvi;
	}
	prvi = poslednji = nullptr;
}

#endif 