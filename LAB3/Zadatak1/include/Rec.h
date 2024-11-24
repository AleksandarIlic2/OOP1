#ifndef _h_Rec


#define _h_Rec
#include <iostream>
#include "Skup.h"
using namespace std;



class Rec {
	string stringRec;
	
//	static const string samoglasnici;
	//static const string sonanti;
public:
	Rec(string niska) : stringRec(niska) { this->izbaciPogresne(); };
	int operator+() const {return size(this->stringRec); }
	void izbaciPogresne();
	int operator~() const;
	bool pripadaSamoglasnicima(char k) const;
	bool pripadaSonantima(char k) const;
	int operator()(int n) const;
	bool pripadaNosiocima(int i) const;
	friend bool operator^(const Rec& r1, const Rec& r2);
	friend istream& operator>>(istream& is,  Rec& r1);
	friend ostream& operator<<(ostream& os, const Rec& r1);
	
};

#endif 