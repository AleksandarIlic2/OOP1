#include <iostream>
#include "Greske.h"
#include "Lista.h"
#include "Boja.h"
#include "Ukras.h"
#include "Kugla.h"
using namespace std;

int main()
{
	try {
		Boja b1(2, 4, 120);
		Boja b2(2, 3, 200);
		Boja b3(1, 17, 18);
		Boja b4(4, 39, 174);
		Ukras** listaKugli = new Ukras*[4];
		Kugla k1(50, b1, MALA);
		Kugla k2(100, b2, SREDNJA);
		Kugla k3(150, b3, VELIKA);
		Kugla k4(200, b4, NAJVECA);
		listaKugli[0] = &k1;
		listaKugli[1] = &k2;
		listaKugli[2] = &k3;
		listaKugli[3] = &k4;
		for (int i = 0; i < 4; i++)
			cout << *(listaKugli[i]) << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	
	return 0;
}