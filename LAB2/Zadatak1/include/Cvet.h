#ifndef _h_cvet_h


#define _h_cvet_h
#include <iostream>
#include <string>
using namespace std;

class Cvet
{
	string naziv;
	int nabavnaCena;
	int prodajnaCena;
public:
	Cvet(string naz,int nabCena, int prodCena):naziv(naz),nabavnaCena(nabCena),prodajnaCena(prodCena){}
	string dohvatiIme() const { return naziv; }
	int dohvatiNabavnuCenu() { return nabavnaCena; }
	int dohvatiProdajnuCenu() { return prodajnaCena; }
	int zarada();
	bool operator==(const Cvet& c2);
	friend ostream& operator<<(ostream& os, const Cvet& c1);

};

#endif