#include "Pozycja.h"

Pozycja::Pozycja()
    : dlugoscGeo(0), szerokoscGeo(0)
{
}

void Pozycja::zapisz(ofstream& file)
{
    file << dlugoscGeo << " " << szerokoscGeo << endl;
}

double Pozycja::Odleglosc(Pozycja p1, Pozycja p2)
{
    return sqrt(pow(p1.dlugoscGeo - p2.dlugoscGeo, 2) + pow(p1.szerokoscGeo - p2.szerokoscGeo, 2));
}

ostream& operator<<(ostream& os, Pozycja& poz)
{
    return os << "(" << poz.dlugoscGeo << ", " << poz.szerokoscGeo << ")";
}

istream& operator>>(istream& is, Pozycja& poz)
{
    return is >> poz.dlugoscGeo >> poz.szerokoscGeo;
}
