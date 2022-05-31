#include "Mlecz.h"
#define SILA_MLECZA 0
#define SZANSA_NA_ROZSIANIE 1
#define ILOSC_PROB_ROZSIANIA 3

Mlecz::Mlecz(int posX, int posY, Swiat& swiat)
	:Roslina(swiat, SILA_MLECZA, posX, posY, "Mlecz")
{
	swiat.dodajOrganizm(this);
}

void Mlecz::rysowanie()
{
	cout << "M";
}

bool Mlecz::czyTenSamGatunek(Organizm* organizm)
{
	return dynamic_cast<Mlecz*>(organizm) != nullptr;
}

void Mlecz::utworzDziecko(int posX, int posY, Swiat& swiat)
{
	new Mlecz(posX, posY, swiat);
}

void Mlecz::akcja()
{
	wykonanoRuch = 1;
	for (int i = 0; i < ILOSC_PROB_ROZSIANIA; i++)
	{
		int zasiew = rand() % 10;
		if (zasiew < SZANSA_NA_ROZSIANIE)
		{
			this->rozmnazanie();
		}
	}
}