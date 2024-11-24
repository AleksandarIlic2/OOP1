#ifndef _h_Greske


#define _h_Greske
#include <iostream>
#include <exception>
using namespace std;

class GNepostojiTekuci : public exception
{
public:
	GNepostojiTekuci() : exception("Greska! Tekuci element ne postoji.") {};
};

class GPogresnaBoja : public exception
{

public:
	GPogresnaBoja() : exception("Greska! Ta nijansa boje ne postoji.") {};
};

#endif 