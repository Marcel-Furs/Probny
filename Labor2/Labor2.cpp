#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <limits>

using namespace std;

int Getsize(const int maxSize = 100)
{
    int n;
    do
    {
        cout << "n= ";
        cin >> n;
    } while (n <= 0 || n > maxSize);
    return n;
}
void srednia(int tab[], const int n)
{
    int suma = 0;
    float sr;

    for (int i = 0; i < n; i++)
    {
        tab[i] = n;
        suma = suma + tab[i];
    }
    sr = suma / n;
    cout << "srednia= " << sr << endl;
}

void showdata(int tab[], const int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "Ocena" << i + 1 << " = ";
        cout << tab[i] << endl;
    }
}

int main()
{
    const int maxSize = 100;
    int n = Getsize(maxSize);
    int tablica[maxSize];
    // podawanie oceny
    for (int i = 0; i < n; ++i)
    {
        cout << "podaj ocene nr " << i + 1 << " ";
        cin >> tablica[i];
    }
    // wczytywanie ocen
    for (int i = 0; i < n; ++i)
    {
        cout << tablica[i] << endl;
    }

    // wyliczenie sumy i sredniej:
    float suma = 0;
    float sr;
    for (int i = 0; i < n; i++)
    {
        suma = suma + tablica[i];
    }
    sr = suma / n;
    cout << "suma= " << suma << endl;
    cout << "srednia= " << sr << endl;

    // Wyszukanie max i min

    int min = tablica[0];
    int max = tablica[0];
    for (int i = 0; i < n; i++)
    {
        if (min > tablica[i])
        {
            min = tablica[i];
        }
        if (max < tablica[i])
        {
            max = tablica[i];
        }
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;


    srednia(tablica, n);

    showdata(tablica, n);



   /* int a;
    int suma = 0;
    int ilosc = 0;
    int min = 0, max = 0;

        do {

            cout << "podaj ocene: " << endl;
            cin >> a;
            suma =suma + a;

            ilosc++;
            if (a < min)min = a;
            if (a > max)max = a;

        } while (a != 0);

        double sr = 1.0*suma / --ilosc;
        cout << "Suma= " << suma << endl;
        cout << "srednia= " << sr << endl;
        cout << "Min= " << min << endl;
        cout << "Max=" << max << endl;
      /////
    const int maxSize = 100;
    int n;
    do
    {
        cout << "n= ";
        cin >> n;

    } while (n <= 0 || n>100);
    int tablica[maxSize];


   /*
    vector<int> tablic(n);

    for (int i = 0; i < n; ++i)
    {
        cout << "Podaj ocene nr" << i;
        cin >> tablic[i];
    }
    */
    return 0;
}
