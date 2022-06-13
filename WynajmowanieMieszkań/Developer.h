#pragma once
#include "Osoba.h"
#include <iostream>
#include "Blok.h"

class Blok;

class Developer: public Osoba
{
private:
	int stazPracy;
	Blok* blok;
public:
	Developer() = default;
	Developer(std::string imie, std::string nazwisko, int id, int stazPracy);

	friend std::ostream& operator<<(std::ostream& os, Developer& p);
	friend std::istream& operator>>(std::istream& is, Developer& p);
};

 std::ostream& operator<<(std::ostream& os, Developer& p);
 std::istream& operator>>(std::istream& is, Developer& p);