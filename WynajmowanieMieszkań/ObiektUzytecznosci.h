#pragma once
#include "Pozycja.h"

#include <iostream>
#include <fstream>
using namespace std;

class ObiektUzytecznosci
{
private:
	string nazwa;
	Pozycja pozycja;

public:
	string getNazwa();
	friend ostream& operator<<(ostream& os, ObiektUzytecznosci& ob);
	friend istream& operator>>(istream& is, ObiektUzytecznosci& ob);
	Pozycja getPozycja() { return pozycja; }
	void zapisz(ofstream& file);
};

ostream& operator<<(ostream& os, ObiektUzytecznosci& ob);
istream& operator>>(istream& is, ObiektUzytecznosci& ob);