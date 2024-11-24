#ifndef _h_Skup


#define _h_Skup
#include <iostream>

using namespace std;

class Skup {
	struct Elem {
		char karakter;
		Elem* next;
		Elem(char k) : karakter(k), next(nullptr) {};
		~Elem() { next = nullptr; };
	};
	Elem* prvi = nullptr;
	Elem* poslednji = nullptr;

public:
	Skup(string niska)	
	{
		for (int i = 0; i < (signed)niska.length(); i++)
		{
			if ((*this)(niska[i]) == true)continue;
			*(this) += niska[i];
		}
	}
	Skup(const Skup& skup) = delete;
	Skup& operator=(const Skup& skup) = delete;
	Skup& operator+=(char k);
	bool operator()(char znak) const;
	~Skup();
	
};

#endif 