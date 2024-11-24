#ifndef _h_Greske


#define _h_Greske
#include <iostream>
#include <exception>
using namespace std;

class GPogresanIndeks : public exception
{

public:
	GPogresanIndeks() : exception("Greska! Indeks je van opsega.") {};
};

#endif 