#ifndef _h_Fudbaler


#define _h_Fudbaler

using namespace std;
#include <iostream>
#include <string>
enum Pozicije { GK, DEF, MID, FWD };

class Fudbaler
{
	string ime;
	string nazivRep;
	static string svePozicije[4];
	Pozicije Pozicija;

public:
	Fudbaler(string imeFudb, string reprezentacija, Pozicije pozicija) :ime(imeFudb), nazivRep(reprezentacija), Pozicija(pozicija) {};
	string dohvatiIme() const { return ime; }
	string dohvatiRep() const { return nazivRep; }
	Pozicije dohvatiPozociju() const { return Pozicija; }
	void promeniPoziciju(Pozicije poz) { Pozicija = poz; }
	Fudbaler(const Fudbaler& fudbaler) = delete;
	Fudbaler& operator=(const Fudbaler& fudbaler) = delete;
	friend ostream& operator<<(ostream& os, const Fudbaler& fudbaler);
};


#endif