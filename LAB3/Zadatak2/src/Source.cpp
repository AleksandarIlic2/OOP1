#include <iostream>
#include "Lista.h"
#include "Greske.h"
#include "Vreme.h"
#include "Film.h"
#include "Strani.h"
#include "Domaci.h"
using namespace std;


int main()
{
	try {
		Vreme v1(2, 35);
		Vreme v2(15, 25);	
		Domaci d1("Ko to tamo peva", v1);
		Strani s1("Mali Budo", v2, "Crna Gora", SINHRONIZOVAN);	
		d1.oceniFilm(5);
		d1.oceniFilm(7);
		s1.oceniFilm(9);
		cout << d1 << endl;
		cout << s1 << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	
}
