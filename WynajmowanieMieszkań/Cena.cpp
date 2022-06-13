#include "Cena.h"

Cena::Cena(int cena, string metraz, bool uzywany, bool umeblowane) : cena(cena), metraz(metraz), uzywany(uzywany), wyremontowane(wyremontowane)
{
}

void Cena::zapisz(ofstream& file)
{
	file << cena << " " << metraz << " " << czyUzywany() << " " << czyWyremontowane() << endl;
}

ostream& operator<<(ostream& os, Cena& cena)
{
	os << cena.getCena() << " zl " << cena.getMetraz() << " " << (cena.czyUzywany() ? "Uzywane" : "Nieuzywane") << " wyremontowane: " << (cena.czyWyremontowane() ? "Tak" : "Nie");
	return os;
}

istream& operator>>(istream& is, Cena& cena)
{
	is >> cena.cena >> cena.metraz >> cena.uzywany >> cena.wyremontowane;
	return is;
}