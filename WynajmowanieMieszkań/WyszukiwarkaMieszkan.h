#pragma once
#include "Miejscowosc.h"
#include <ranges>
#include <vector>

class WyszukiwarkaMieszkan
{
private:
	Miejscowosc* miejscowosc;

public:
	WyszukiwarkaMieszkan() = default;
	WyszukiwarkaMieszkan(Miejscowosc* miejscowosc);
	void wyszukajPoCenie(int limit);
};