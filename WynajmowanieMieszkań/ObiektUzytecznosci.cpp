#include "ObiektUzytecznosci.h"

ostream& operator<<(ostream& os, ObiektUzytecznosci& ob)
{
    return os << ob.nazwa << " " << ob.pozycja;
}

istream& operator>>(istream& is, ObiektUzytecznosci& ob)
{
    return is >> ob.nazwa >> ob.pozycja;
}

string ObiektUzytecznosci::getNazwa()
{
    return nazwa;
}

void ObiektUzytecznosci::zapisz(ofstream& file)
{
    file << nazwa << " ";
    pozycja.zapisz(file);
}
