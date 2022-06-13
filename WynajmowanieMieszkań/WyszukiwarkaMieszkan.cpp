#include "WyszukiwarkaMieszkan.h"

WyszukiwarkaMieszkan::WyszukiwarkaMieszkan(Miejscowosc* miejscowosc) : miejscowosc(miejscowosc)
{
}

void WyszukiwarkaMieszkan::wyszukajPoCenie(int limit)
{
	Miejscowosc* wsk = miejscowosc;
	while (wsk != nullptr)
	{
		for (auto& s : wsk->bloki)
		{
			for(auto& p: s.mieszkania)
			{
				for (auto& c : p.ceny | std::views::filter([limit](Cena& c) { return c.getCena() < limit;  }))  //jak dana cena c nie spe³nia zalozenia, to nie zostaje uzyta w petli
				{
					cout << "Blok: " << s.nazwa << " Mieszkanie:  metraz: " << p.metraz << "m2, ilosc pokoi: " << p.IloscPokoi << ", ktore pietro: " <<  p.KtorePietro << ", " << c << endl;
				}
			}
		}
		wsk = wsk->getNext();
	}
}