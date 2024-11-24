#include <iostream>
#include "Skup.h"
#include "Rec.h"
#include "Stih.h"
#include "Strofa.h"
#include "Katren.h"
using namespace std;



int main()
{
	Rec r1("vodenica");
	cout << ~r1 << endl;
	Rec r2("psenica");
	cout << ~r2 << endl;
	cout << (r1 ^ r2) << endl;
	cout << "Unesite prvi stih:" << endl;
	Stih prvi;
	cin >> prvi;	
	cout << "Unesite drugi stih:" << endl;
	Stih drugi;
	cin >> drugi;
	cout << "Unesite treci stih:" << endl;
	Stih treci;
	cin >> treci;
	cout << "Unesite cetvrti stih:" << endl;
	Stih cetvrti;
	cin >> cetvrti;
	
	Katren k1;
	k1 += prvi;
	k1 += drugi;
	k1 += treci;
	k1 += cetvrti;
	cout << k1 << endl;
	cout << *k1 << endl;
	
	return 0;

}