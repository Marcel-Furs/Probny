#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

class Pozycja
{
private:
	double dlugoscGeo;
	double szerokoscGeo;

public:
	Pozycja();
	void zapisz(ofstream& file);
	friend ostream& operator<<(ostream& os, Pozycja& poz);
	friend istream& operator>>(istream& is, Pozycja& poz);
	static double Odleglosc(Pozycja p1, Pozycja p2);
};


ostream& operator<<(ostream& os, Pozycja& poz);
istream& operator>>(istream& is, Pozycja& poz);