#pragma once

#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Walidator
{
private:
	string wczytujDopoki(string regex, string komunikat);

public:
	string wczytajImie();
	string wczytajNazwisko();
	int wczytajId();
	string wczytajUlice();
	string wczytajMiasto();
	string wczytajKodPocztowy();
	int wczytajWiek();
};

