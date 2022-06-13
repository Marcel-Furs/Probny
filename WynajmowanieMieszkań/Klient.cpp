#include "Klient.h"


Klient::Klient(Miejscowosc* miejscowosci) : miejscowosci(miejscowosci), wyszukiwarka(WyszukiwarkaMieszkan(miejscowosci))
{
}

Klient::Klient(Miejscowosc* miejscowosci, string imie, string nazwisko, int id, string ulica, string miasto, string kodPocztowy, int wiek)
	: Osoba(imie, nazwisko, id), ulica(ulica), miasto(miasto), kodPocztowy(kodPocztowy), wiek(wiek), miejscowosci(miejscowosci), wyszukiwarka(WyszukiwarkaMieszkan(miejscowosci))
{
	dodajObnizke();
}

void Klient::dodajObnizke()
{
	Miejscowosc* wsk = miejscowosci;
	while (wsk != nullptr)
	{
		if (wsk->getNazwa() == miasto)
		{
			wsk->dodajObnizke(0.1);
			break;
		}
		wsk = wsk->getNext();
	}
}


void Klient::menu()
{
	int wybor;
	do {
		cout << "Podaj nr opcji (0 - wyjscie, 1 - wyszukaj po cenie, 2 - kupno, 3 - sprzedaz, 4 - pokaz wszystkie dane): ";
		cin >> wybor;
		realizujOpcje(wybor);
	} while (wybor != 0);
}

void Klient::realizujOpcje(int opcja)
{
	switch (opcja)
	{
	case 0:
		cout << "Koniec programu!" << endl;
		break;
	case 1:
		wyszukajPoCenie();
		break;
	case 2:
		kupno();
		break;
	case 3:
		sprzedaz();
		break;
	case 4:
		miejscowosci->pokaz();
		break;
	default:
		cout << "Niepoprawna opcja!" << endl;
		break;
	}
}

void Klient::wyszukajPoCenie()
{
	cout << "Podaj limit cenowy: ";
	int cena;
	cin >> cena;
	wyszukiwarka.wyszukajPoCenie(cena);
}

Blok* Klient::wybierzBlok()
{
	Miejscowosc* wsk = miejscowosci;
	int i = 1;
	cout << "Podaj nr miejscowosci: " << endl;
	while (wsk != nullptr)
	{
		cout << i << ". " << wsk->getNazwa() << endl;
		wsk = wsk->getNext();
		i++;
	}

	int nr;
	cin >> nr;

	Miejscowosc* wybrana = nullptr;
	wsk = miejscowosci;
	i = 1;
	while (wsk != nullptr)
	{
		if (i == nr)
		{
			wybrana = wsk;
			break;
		}
		i++;
		wsk = wsk->getNext();
	}

	if (wybrana == nullptr)
	{
		return nullptr;
	}
	
	return wybrana -> wybieszblok();
}

void Klient::kupno()
{
	Blok* s = wybierzBlok();
	if (s == nullptr)
	{
		cout << "Wybrano niepoprawna miejscowosc lub blok" << endl;
	}
	else
	{
		s->Kupno();
	}
}

void Klient::sprzedaz()
{
	Blok* s = wybierzBlok();
	if (s == nullptr)
	{
		cout << "Wybrano niepoprawna miejscowosc lub blok" << endl;
	}
	else
	{
		s->Sprzedaz();
	}
}

ostream& operator<<(ostream& os, Klient& p)
{
	os << p.imie << " " << p.nazwisko << " id: " << p.id << " wiek: " << p.wiek << " adres: " << p.ulica << " " << p.miasto << " " << p.kodPocztowy;
	return os;
}

istream& operator>>(istream& is, Klient& p)
{
	is >> p.imie >> p.nazwisko >> p.id >> p.wiek >> p.ulica >> p.miasto >> p.kodPocztowy;
	return is;
}