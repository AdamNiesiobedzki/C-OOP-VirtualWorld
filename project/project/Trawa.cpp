#include "Trawa.h"

#define SILA_TRAWY 0

Trawa::Trawa(int posX, int posY, Swiat& swiat)
	:Roslina(swiat,SILA_TRAWY,posX,posY, "Trawa")
{
	swiat.dodajOrganizm(this);
}

void Trawa::rysowanie()
{
	cout << "T";
}

bool Trawa::czyTenSamGatunek(Organizm* organizm)
{
	return dynamic_cast<Trawa*>(organizm) != nullptr;
}

void Trawa::utworzDziecko(int posX, int posY, Swiat& swiat)
{
	new Trawa(posX, posY, swiat);
}