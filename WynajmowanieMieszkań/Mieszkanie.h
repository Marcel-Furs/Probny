#pragma once
#include "Cena.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Mieszkanie
{
private:
	vector<Cena>ceny;
	string rodzaj;
	int metraz;
	int IloscPokoi;
	int KtorePietro;
	bool Umeblowane;
public:
	Mieszkanie(Cena cena, int metraz, int IloscPokoi, int KtorePietro, bool Umeblowane);
	Mieszkanie() = default;
	bool sprzedaj(int cena);
	vector<Cena> getCeny() { return ceny; }
	string getRodzaj() { return rodzaj; }
	int getMetraz() { return metraz; }
	int getIloscPokoi() { return IloscPokoi; }
	int getKtorePietro() { return KtorePietro; }
	bool getUmeblowane() { return Umeblowane; }
	void dodajObnizke(float obnizka);
	void zapisz(ofstream& file);

	friend ostream& operator<<(ostream& os, Mieszkanie& p);
	friend istream& operator>>(istream& is, Mieszkanie& p);
	friend class WyszukiwarkaMieszkan;
};

ostream& operator<<(ostream& os, Mieszkanie& p);
istream& operator>>(istream& is, Mieszkanie& p);