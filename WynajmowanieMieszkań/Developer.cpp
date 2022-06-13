#include "Developer.h"

Developer::Developer(std::string imie, std::string nazwisko, int id, int stazPracy) : Osoba(imie, nazwisko, id), stazPracy(stazPracy)
{
}

std::ostream& operator<<(std::ostream& os, Developer& p)
{
	os << p.imie << " " << p.nazwisko << "id: " << p.id << " Staz pracy: " << p.stazPracy;
	return os;
}
std::istream& operator>>(std::istream& is, Developer& p)
{
	is >> p.imie >> p.nazwisko >> p.id >> p.stazPracy;
	return is;
}