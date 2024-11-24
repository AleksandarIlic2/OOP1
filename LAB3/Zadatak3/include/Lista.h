#ifndef _h_Lista


#define _h_Lista
#include <iostream>
#include "Greske.h"
using namespace std;

template<typename T>
class Lista {
	struct Elem
	{
		T t;
		Elem* next;
		Elem(T t1) : t(t1) , next(nullptr) {};
		~Elem() { next = nullptr; }
	};
	Elem* prvi = nullptr;
	Elem* poslednji = nullptr;
	mutable Elem* tekuci = nullptr;
public:
	Lista() = default;
	Lista(const Lista& lista) = delete;
	Lista& operator=(const Lista& lista) = delete;
	Lista& operator<<=(T t) { poslednji = (!prvi ? prvi : poslednji->next) = new Elem(t); return *this; }
	Lista& operator>>=(T t);
	~Lista() {
		Elem* stari = prvi;
		while (prvi)
		{
			prvi = prvi->next;
			delete stari;
			stari = prvi;
		}
	}
	void setTekuci() const { tekuci = prvi; }
	void pomeriTekuci() const { tekuci = tekuci->next; }
	bool postojiTekuci() const { return tekuci != nullptr; }
	T& dohvatiTekuci() const {
		if (tekuci == nullptr)throw GNepostojiTekuci();
		return tekuci->t; 
	}
};
template<typename T>
Lista<T>& Lista<T>::operator>>=(T t)
{
	Elem* novi = new Elem(t);
	if (prvi == nullptr) { prvi = poslednji = novi; return *this; }
	novi->next = prvi;
	prvi = novi;
	return *this;
}
#endif 