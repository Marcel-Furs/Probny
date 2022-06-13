#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Cena
{
private:
	int cena;
	string metraz;
	bool uzywany;
	bool wyremontowane;
public:
	Cena() = default;
	Cena(int cena, string metraz, bool uzywany, bool umeblowane);
	int getCena() { return cena; }
	string getMetraz() { return metraz; }
	bool czyUzywany() { return uzywany; }
	bool czyWyremontowane() { return wyremontowane; }
	void setCena(int cena) { this->cena = cena; }
	void zapisz(ofstream& file);
	friend istream& operator>>(istream& is, Cena& cena);
};

ostream& operator<<(ostream& os, Cena& cena);
istream& operator>>(istream& is, Cena& cena);