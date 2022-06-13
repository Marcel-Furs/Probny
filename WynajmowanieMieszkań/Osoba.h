#pragma once

#include <iostream>

class Osoba
{
protected:
	std::string imie;
	std::string nazwisko;
	int id;

public:
	Osoba() = default;
	Osoba(std::string imie, std::string nazwisko, int id);
};