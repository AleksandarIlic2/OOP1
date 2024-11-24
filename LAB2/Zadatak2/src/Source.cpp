#include "Spil.h"
#include <string>

int main()
{
	const int n = 10;
	string karte[n] = { "Kuribo", "Zmaj", "Dama", "Carobnjak" };
	Stamparija leptiric(karte, n);
	Slicica* sl1 = leptiric.stampajSlicicu(0);
	Slicica* sl2 = leptiric.stampajSlicicu(1);
	Slicica* sl3 = leptiric.stampajSlicicu(2);
	Spil mojSpil;
	mojSpil += sl1;
	mojSpil += sl2;
	mojSpil += sl3;
	
	
	for (mojSpil.postaviTekuci(); mojSpil.krajListe() == false; mojSpil.pomeriTekuci())
	{
		cout << *(mojSpil.dohvatiTekucuSlicicu());
	}
	cout << endl;
	mojSpil.izbaciSlicicu(0);
	mojSpil.izbaciSlicicu(1);
	mojSpil.izbaciSlicicu(2);
	cout << mojSpil << endl;
	Stamparija s2(karte,n) ;	

}