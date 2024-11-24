#include "Pogodak.h"



int main()
{
	Fudbaler f1("Miinkovic Savic", "Srbija", Pozicije::GK);
	Fudbaler f2("Aleksandar Mitrovic", "Srbija", Pozicije::FWD);
	Fudbaler f3("Dusan Vlahovic", "Srbija", Pozicije::MID);

	Pogodak p1(&f1,73);
	Pogodak p2(&f2, 43);

	cout << p1 << endl;
	cout << p2 << endl;
	
}