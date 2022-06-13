#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "Developer.h"
#include "Mieszkanie.h"
#include "Pozycja.h"
using namespace std;

enum TYP_MIESZKAN {KOMUNALNE, WSPOLDZIELCZE, ZAKLADOWE};
const string nazwyTypow[] = { "komunalne", "wspoldzielcze", "zakladowe" };

class Miejscowosc;
class Developer;

class Blok
{
private:
	string nazwa;
	Miejscowosc* miejscowosc;
	vector<Developer> developerzy;
	vector<Mieszkanie> mieszkania;
	TYP_MIESZKAN TypMieszkan;
	Pozycja pozycja;

public:
	Blok(Miejscowosc* miejscowosc);
	void Sprzedaz();
	void Kupno();
	std::string getNazwa() { return nazwa; }
	void dodajObnizke(float obnizka);
	void zapisz(ofstream& file);

	friend ostream& operator<<(ostream& os, Blok &s);
	friend istream& operator>>(istream& is, Blok &s);
	friend class WyszukiwarkaMieszkan;
	Pozycja getPozycja() { return pozycja; }
};

ostream& operator<<(ostream& os, Blok& s);
istream& operator>>(istream& is, Blok& s);