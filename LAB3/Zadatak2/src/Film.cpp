#include "Film.h"

double Film::prosecnaOcena() const
{
	double pOcena = 0.0;
	for (int i = 0; i < listaOcena.dohvatiBrojTrenutnih(); i++)
	{
		pOcena += listaOcena[i];
	}
	return (double)pOcena / (double)listaOcena.dohvatiBrojTrenutnih();
}
