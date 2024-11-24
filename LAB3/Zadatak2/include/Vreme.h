#ifndef _h_Vreme


#define _h_Vreme
#include <iostream>
#include <iomanip>
using namespace std;

class Vreme {

	int minuti = 0;
public:
	Vreme(int s, int m) { minuti = s * 60 + m; };
	friend bool operator>(const Vreme& v1, const Vreme& v2);
	friend bool operator<(const Vreme& v1, const Vreme& v2);
	Vreme operator+ (const Vreme& v2);
	friend ostream& operator<< (ostream& os, const Vreme& v);
};


#endif 