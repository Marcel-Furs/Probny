#include "Blok.h"
#include "Miejscowosc.h"

Blok::Blok(Miejscowosc* miejscowosc) : miejscowosc(miejscowosc)
{
}
//Mieszkanie(Cena cena, int metraz, int IloscPokoi, int KtorePietro, bool Umeblowane);
void Blok::Sprzedaz()
{
	int metraz, IloscPokoi, KtorePietro;
	bool Umeblowane;
	Cena cena;
	
	cout << "Podaj metraz mieszkania: ";
	cin >> metraz;
	cout << "Podaj ilosc pokoi: ";
	cin >> IloscPokoi;
	cout << "Podaj Ktore na ktorym pietrze znajduje sie mieszkanie: ";
	cin >> KtorePietro;
	cout << "Podaj wariant cenowy [cena metraz uzywane(0/1) wyremontowane(0/1)]";
	cin >> cena;
	cout << "Czy mieszkanie jest umeblowane? ";
	cin >> Umeblowane;

	Mieszkanie m(cena, metraz, IloscPokoi, KtorePietro, Umeblowane);
	mieszkania.push_back(m);
	cout << "Sprzedano pomyœlnie! " << endl;
}

void Blok::Kupno()
{
	for (int i = 0; i < mieszkania.size(); i++)
	{
		cout << (i + 1) << "))" << endl << mieszkania[i] << endl;
	}
	cout << "Podaj nr mieszkania i cene: " << endl;
	int nr, cena;
	cin >> nr >> cena;
	nr--;
	if (nr >= 0 and nr < mieszkania.size() and mieszkania[nr].sprzedaj(cena))
	{
		cout << "Sprzedano! " << endl;
		//Jesli nie ma wariantow cenowy, to mieszkanie mozna porzucic
		if (mieszkania[nr].getCeny().size() == 0)
		{
			mieszkania.erase(mieszkania.begin() + nr);
		}
	}
	else
	{
		cout << "Niepoprawny numer lub cena " << endl;
	}
}

void Blok::dodajObnizke(float obnizka)
{
	for (auto& m : mieszkania)
	{
		m.dodajObnizke(obnizka);
	}
}

void Blok::zapisz(ofstream& file)
{
	file << nazwa << endl;
	pozycja.zapisz(file);
	file << mieszkania.size() << endl;
	for (auto& m : mieszkania)
	{
		m.zapisz(file);
	}
}

std::ostream& operator<<(std::ostream& os, Blok& s)
{
	os << "Blok: " << s.nazwa << " Miejscowosc: " << s.miejscowosc->getNazwa() << " mieszkania " << nazwyTypow[s.TypMieszkan] << " pozycja: " << s.pozycja << endl;
	if (s.mieszkania.size() > 0)
	{
		os << "Mieszkania: " << endl;
		for (auto& mie : s.mieszkania)
		{
			os << mie << endl;
		}
	}
	if (s.developerzy.size() > 0)
	{
		os << "Developerzy: ";
		for (auto& developer : s.developerzy)
		{
			os << endl << developer;
		}
	}
	cout << endl << "==================================================" << endl;
	return os; 
}

std::istream& operator>>(std::istream& is, Blok& s)
{
	int iloscDeveloperow = 0, IloscMieszkan=0;
	is >> s.nazwa;
	is >> s.pozycja;
	is >> IloscMieszkan;
	for (int i = 0; i < IloscMieszkan; i++)
	{
		Mieszkanie p;
		is >> p;
		s.mieszkania.push_back(p);
	}
	is >> iloscDeveloperow;
	for (int i = 0; i < iloscDeveloperow; i++)
	{
		Developer d;
		is >> d;
		s.developerzy.push_back(d);
	}
	return is;
}