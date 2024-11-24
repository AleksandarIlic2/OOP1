#include "Cvet.h"
#include "Buket.h"
#include "Cvecara.h"

int main()
{
	Cvet c1("Ruza", 250, 300);
	Cvet c2("Kadifa", 260, 320);
	Cvet c3("Lala", 260, 370);

	Cvet c11("Cuvarkuca", 250, 300);
	Cvet c22("Visibaba", 260, 320);
	Cvet c33("Maslacak", 260, 370);

	Buket b1 = Buket();
	b1.dodajCvet(&c1);
	b1.dodajCvet(&c2);
	b1.dodajCvet(&c2);
	b1.dodajCvet(&c3);

	Buket b2;
	b2 = b1;
	b2.dodajCvet(&c11);

	cout << "Nabavna cena buketa b1:" << b1.nabavnaCenaBuketa() << endl;
	cout << "Prodajna cena buketa b1: " << b1.prodajnaCenaBuketa() << endl;
	cout << "Nabavna cena buketa b2:" << b2.nabavnaCenaBuketa() << endl;
	cout << "Prodajna cena buketa b2: " << b2.prodajnaCenaBuketa() << endl;

	Cvecara cvecara;
	cvecara.dodajBuket(&b1);
	cvecara.dodajBuket(&b2);
	cout << cvecara << endl;
	Cvecara cvecaraCopy = cvecara;
	cvecara.prodajBuket(&b2);
	cvecara.prodajBuket(&b1);
	cout << cvecara << endl;

}