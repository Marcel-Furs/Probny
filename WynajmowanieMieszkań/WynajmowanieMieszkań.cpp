#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <future>
#include <chrono>
#include <sstream>
#include <filesystem>
#include "Klient.h"
#include "Walidator.h"
#include "WyszukiwarkaMieszkan.h"

namespace fs = std::filesystem;
using namespace std;

struct Lista
{
	Miejscowosc* head = nullptr;
	Miejscowosc* tail = nullptr;
};

Lista wczytajWszystko(string nazwaPliku)
{
    ifstream file(nazwaPliku);

    if (!file.is_open())
    {
        cout << "Nie mozna otworzyc pliku: " << nazwaPliku << endl;
        exit(-1);
    }

    stringstream s;
    while (!file.eof())
    {
        string line;
        getline(file, line);
        auto index = line.find("//");
        if (index != string::npos)
        {
            line = line.substr(0, index);
        }
        s << line << endl;
    }
    file.close();

    int iloscMiejscowosci = 0;
    s >> iloscMiejscowosci;
    Lista miejscowosci;
    for (int i = 0; i < iloscMiejscowosci; i++)
    {
        Miejscowosc* m = new Miejscowosc();
        s >> *m;
        if (miejscowosci.head == nullptr)
        {
            miejscowosci.head = m;
        }
        else
        {
            miejscowosci.tail->setNext(m);
        }
        miejscowosci.tail = m;
    }
    return miejscowosci;
}

string stworzNazwePliku()
{
    string nazwa = "wynik";
    string rozszerzenie = ".txt";
    string nowa_nazwa = nazwa + rozszerzenie;
    int i = 1;
    while (fs::exists(nowa_nazwa))
    {
        nowa_nazwa = nazwa + "_" + to_string(i) + rozszerzenie;
        i++;
    }
    return nowa_nazwa;
}

void zapiszWszystko(Miejscowosc* miejscowosc)
{
    ofstream file(stworzNazwePliku());
    Miejscowosc* wsk = miejscowosc;
    while (wsk != nullptr)
    {
        wsk->zapisz(file);
        wsk = wsk->getNext();
    }
    file.close();
}

Klient* utworzKlienta(Miejscowosc* lista)
{
    Walidator w;
    auto imie = w.wczytajImie();
    auto nazwisko = w.wczytajNazwisko();
    auto id = w.wczytajId();
    auto ulica = w.wczytajUlice();
    auto miasto = w.wczytajMiasto();
    auto kodPocztowy = w.wczytajKodPocztowy();
    auto wiek = w.wczytajWiek();
    return new Klient(lista, imie, nazwisko, id, ulica, miasto, kodPocztowy, wiek);
}

int main(int argc, char** argv)
{
    auto miejscowosc = wczytajWszystko("TekstMieszkania.txt").head;
    Klient* klient = utworzKlienta(miejscowosc);
	klient->menu();
    zapiszWszystko(miejscowosc);
    delete klient;
	return 0;
}