#include "Walidator.h"

string Walidator::wczytujDopoki(string regex, string komunikat)
{
	string text;
	getline(cin, text);

	const std::regex base_regex(regex);
	std::smatch base_match;
	while (!std::regex_match(text, base_match, base_regex))
	{
		cout << komunikat << endl;
		getline(cin, text);
	}

	return text;
}

string Walidator::wczytajImie()
{
	cout << "Podaj imie: " << endl;
	return wczytujDopoki("^[A-Z][a-z]+", "Blad, imie powinno sie skladac tylko z liter i rozpoczynac od duzej litery:");
}

string Walidator::wczytajNazwisko()
{
	cout << "Podaj nazwisko: " << endl;
	return wczytujDopoki("^[A-Z][a-z]+", "Blad, nazwisko powinno sie skladac tylko z liter i rozpoczynac od duzej litery:");
}

int Walidator::wczytajId()
{
	cout << "Podaj id: " << endl;
	auto value = wczytujDopoki("^[0-9]+$", "Blad, id powinno sie skladac tylko z liczb:");
	return stoi(value);
}

string Walidator::wczytajUlice()
{
	cout << "Podaj ulice: " << endl;
	return wczytujDopoki("^[A-Z][a-z]+", "Blad, ulica powinna sie rozpoczynac od duzej litery:");
}

string Walidator::wczytajMiasto()
{
	cout << "Podaj miasto: " << endl;
	return wczytujDopoki("^[A-Z][a-z\\s]+", "Blad, miasto powinno sie skladac tylko z liter i rozpoczynac od duzej litery:");
}

string Walidator::wczytajKodPocztowy()
{
	cout << "Podaj kod pocztowy: " << endl;
	return wczytujDopoki("^[0-9]{2}-[0-9]{3}$", "Blad, kod pocztowy powinien byc w formacie: 00-000: ");
}

int Walidator::wczytajWiek()
{
	cout << "Podaj wiek: " << endl;
	auto value = wczytujDopoki("^[1-9][0-9]{1,2}$", "Blad, wiek powinien byc liczba wieksza od 0:");
	return stoi(value);
}
