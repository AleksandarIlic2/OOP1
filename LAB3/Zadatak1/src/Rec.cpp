#include "Rec.h"



void Rec::izbaciPogresne()
{
	string pom = "";
	for (int i = 0; i < (signed)stringRec.size(); i++)
	{
		if (isalpha(stringRec[i]))
			pom += stringRec[i];
	}
	this->stringRec = pom;
}

int Rec::operator~() const
{
	int br = 0;
	for (int i = 0; i < (signed)stringRec.size(); i++)
	{
		if (pripadaNosiocima(i) == true)
			br++;
	}
	return br;
}

bool Rec::pripadaSamoglasnicima(char k) const
{
	Skup samoglasnici("aeiouAEIOU");
	return samoglasnici.operator()(k);
}

bool Rec::pripadaSonantima(char k) const
{
	Skup sonanti("lnrLNR");
	return sonanti.operator()(k);
}

int Rec::operator()(int n) const
{
	int brojac = 0;
	if (n >= 0) {
		if (n > (~*(this)))
		{
			return -1;
		}
		for (int i = 0; i < (signed)stringRec.size(); i++)
		{
			if (pripadaNosiocima(i) == true)
			{
				if ((brojac) == n)
					return i;
				brojac++;
			}
		}
	}
	else
	{
		n = n + (~(*this));
		if (n < 0) { return -1; }
		
		for (int i = 0; i < (signed)stringRec.size(); i++)
		{
			if (pripadaNosiocima(i) == true)
			{
				if (brojac++ == abs(n))
					return i;
			}
		}
	}
	return -1;
		
	
}

bool Rec::pripadaNosiocima(int i) const
{	
	if (pripadaSamoglasnicima(stringRec[i]))
		return true;
	else if (i != 0 && i != (signed)stringRec.size() - 1 && pripadaSonantima(stringRec[i]) && (stringRec[i] == 'r' || stringRec[i] == 'R') && !pripadaSamoglasnicima(stringRec[i - 1]) && !pripadaSamoglasnicima(stringRec[i + 1]))
		return true;
	else if (i == 0 && pripadaSonantima(stringRec[i]) && (stringRec[i] == 'r' || stringRec[i] == 'R') && !pripadaSamoglasnicima(stringRec[i + 1]))
		return true;
	else if (i == (signed)stringRec.size() - 1 && pripadaSonantima(stringRec[i]) && (stringRec[i] == 'r' || stringRec[i] == 'R') && !pripadaSamoglasnicima(stringRec[i - 1]))
		return true;
	else if (i != 0 && i != (signed)stringRec.size() - 1 && pripadaSonantima(stringRec[i]) && (stringRec[i] != 'r' && stringRec[i] != 'R') && !pripadaSamoglasnicima(stringRec[i - 1]) && !pripadaSamoglasnicima(stringRec[i + 1]) && stringRec[i + 1] != 'J' && stringRec[i + 1] != 'j')
		return true;
	else if (i == 0 && pripadaSonantima(stringRec[i]) && (stringRec[i] != 'r' && stringRec[i] != 'R') && !pripadaSamoglasnicima(stringRec[i + 1]) && stringRec[i + 1] != 'J' && stringRec[i + 1] != 'j')
		return true;
	else if (i == (signed)stringRec.size() - 1 && pripadaSonantima(stringRec[i]) && (stringRec[i] != 'r' && stringRec[i] != 'R') && !pripadaSamoglasnicima(stringRec[i - 1]))
		return true;
	else
		return false;
}

bool operator^(const Rec& r1, const Rec& r2)
{
	if ((~(r1)) < 1 && (~(r2)) < 1) return false;
	if ((~(r1)) > 1 && (~(r2)) > 1)
	{
		for (int i = r1(-2), j = r2(-2); i < (signed)r1.stringRec.size(); i++)
		{
			if (tolower(r1.stringRec[i]) != tolower(r2.stringRec[j]))
			{
				//cout << tolower(r1.stringRec[i]) << " " << r2.stringRec[j] << endl;
				return false;
			}
				
			j++;
		}		
	}
	else
	{
		for (int i = r1(-1), j = r2(-1); i < (signed)r1.stringRec.size(); i++)
		{
			if (tolower(r1.stringRec[i]) != tolower(r2.stringRec[j]))
				return false;
			j++;
		}
	}
	return true;
}

istream& operator>>(istream& is,  Rec& r1)
{
	string noviString;
	cout << "Unesite novu rec:" << endl;
	is >> noviString;
	r1.stringRec = noviString;
	r1.izbaciPogresne();
	return is;
}

ostream& operator<<(ostream& os, const Rec& r1)
{
	os << r1.stringRec;
	return os;
}
