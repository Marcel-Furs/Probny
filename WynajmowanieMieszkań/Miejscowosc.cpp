#include "Miejscowosc.h"
#include "Blok.h"

ostream& operator<<(ostream& os, Miejscowosc& m)
{
	os << "Miejscowosc: " << m.nazwa << " ----------------------------------------" << endl;
	if (m.bloki.size() > 0)
	{
		os << "Bloki: ";
		for (auto& s : m.bloki)
		{
			os << endl << s;
			os << endl;
			if (m.obiektyUzytecznosci.size() > 0)
			{
				os << "Obiekty uzytecznosci: ";

				vector<future<double>> results;
				for (auto& ob : m.obiektyUzytecznosci)
				{
					auto func = [&ob, &s, &os]() {   // referencyjnie przekazywane elementy z poza wyrazenia lambda
						return Pozycja::Odleglosc(ob.getPozycja(), s.getPozycja());
					};
					results.push_back(std::async(func));
				}

				vector<pair<double, string>> odleglosci;   // para odleglosci i obiektu uzytecznosci 
				for (int i = 0; i < m.obiektyUzytecznosci.size(); i++)
				{
					results[i].wait();
					double odl = results[i].get();   //wynik z watku pobiera
					os << endl << m.obiektyUzytecznosci[i] << " Odleglosc od bloku: " << odl;
					odleglosci.push_back(pair<double, string>(odl, m.obiektyUzytecznosci[i].getNazwa()));
				}

				if (odleglosci.size() > 0)
				{
					os << endl << "Najblizszu obiekt: ";
					auto iterator = min_element(odleglosci.begin(), odleglosci.end(),
						[](pair<double, string>& x, pair<double, string>& y) { return x.first < y.first; });  //bierzemy dwa obiekty par i porownujemy z odleglosciami
					auto najbliszy = (*iterator);       // wyciagamy pierwszy elementy, czyli wynik 
					os << endl << najbliszy.second << " Odleglosc od bloku: " << najbliszy.first;  
				}
			}
		}
	}
	
	return os;
}

istream& operator>>(istream& is, Miejscowosc& m)
{
	int iloscBlokow = 0;
	int iloscUzytecznosci = 0;
	is >> m.nazwa >> iloscUzytecznosci;

	for (int i = 0; i < iloscUzytecznosci; i++)
	{
		ObiektUzytecznosci ob;
		is >> ob;
		m.obiektyUzytecznosci.push_back(ob);
	}

		is >> iloscBlokow;;
	for (int i = 0; i < iloscBlokow; i++)
	{
		Blok s(&m);
		is >> s;
		m.bloki.push_back(s);
	}
	return is;
}

void Miejscowosc::pokaz()
{
	cout << *this << endl;
	if (next != nullptr)
	{
		next->pokaz();
	}
}

Blok* Miejscowosc::wybieszblok()
{
	cout << "Podaj numer bloku" << endl;
	for (int i = 0; i < bloki.size(); i++)
	{
		cout << (i + 1) << ". " << bloki[i].getNazwa() << endl;
	}
	int nr;
	cin >> nr;
	nr--;

	if (nr >= 0 && nr < bloki.size())
	{
		return &bloki[nr];
	}
	else
	{
		return nullptr;
	}
}

void Miejscowosc::dodajObnizke(float obnizka)
{
	for (auto& b : bloki)
	{
		b.dodajObnizke(obnizka);
	}
}

void Miejscowosc::zapisz(ofstream& file)
{
	file << nazwa << endl;
	file << obiektyUzytecznosci.size() << endl;
	for (auto& ob : obiektyUzytecznosci)
	{
		ob.zapisz(file);
	}
	file << bloki.size() << endl;
	for (auto& b : bloki)
	{
		b.zapisz(file);
	}
}
