#include "Mieszkanie.h"

ostream& operator << (ostream & os, Mieszkanie & m)
{
	os << m.metraz << " " << m.IloscPokoi << " " << m.KtorePietro << " " << m.Umeblowane << endl;
	if (m.ceny.size() > 0)
	{
		os << "Warianty cenowe: ";
		for (auto& c : m.ceny)
		{
			os << endl << c;
		}
	}
	return os;
}

istream& operator>>(istream& is, Mieszkanie& m)
{
	int IloscCen = 0;
	is >> m.rodzaj >> m.metraz >> m.IloscPokoi >> m.KtorePietro >> m.Umeblowane >> IloscCen;
	for (int i = 0; i < IloscCen; i++)
	{
		Cena c;
		is >> c;
		m.ceny.push_back(c);
	}
	return is;
}
//Mieszkanie(Cena cena, int metraz, int IloscPokoi, int KtorePietro, bool Umeblowane);
Mieszkanie::Mieszkanie(Cena cena, int metraz, int IloscPokoi, int KtorePietro, bool Umeblowane) : metraz(metraz), IloscPokoi(IloscPokoi), KtorePietro(KtorePietro), Umeblowane(Umeblowane)
{
	ceny.push_back(cena);
}

bool Mieszkanie::sprzedaj(int cena)
{
	for (int i = 0; i < ceny.size(); i++)
	{
		if (ceny[i].getCena() == cena)
		{
			ceny.erase(ceny.begin() + i);
			return true;
		}
	}
	return false;
}

void Mieszkanie::dodajObnizke(float obnizka)
{
	if (obnizka < 0 or obnizka > 1)
	{
		return;
	}

	for (auto& c : ceny)
	{
		c.setCena((1 - obnizka) * c.getCena());
	}
}

void Mieszkanie::zapisz(ofstream& file)
{
	file << rodzaj << " " << metraz << " " << IloscPokoi << " " << KtorePietro << " " << Umeblowane << " " << ceny.size() << endl;
	for (auto& c : ceny)
	{
		c.zapisz(file);
	}
}
