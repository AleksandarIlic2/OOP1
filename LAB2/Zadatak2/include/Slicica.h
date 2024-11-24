#ifndef _Slicica_h

#define _Slicica_h
using namespace std;
#include <iostream>
#include <string>
class Slicica
{
	string naziv;
	int brojSlicice;
	static int idStat;
	int id = idStat++;
	Slicica(int broj, string naz) :naziv(naz), brojSlicice(broj) {}
	friend class Stamparija;
public:
	Slicica(const Slicica& sl) = delete;
	Slicica& operator=(const Slicica& sl) = delete;
	friend ostream& operator<<(ostream& os, const Slicica& sl);
	string dohvatiNaziv() const { return naziv; }
	int dohvatiBrojSlicice() const { return brojSlicice; }
	int dohvatiId() const { return id; }

};

#endif