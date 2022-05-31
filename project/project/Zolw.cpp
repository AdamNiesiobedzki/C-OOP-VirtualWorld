#include "Zolw.h"

#define SILA_ZOLWIA 2
#define INICJATYWA_ZOLWIA 1
#define PANCERZ 5

Zolw::Zolw(int posX, int posY, Swiat& swiat)
	:Zwierze(swiat, SILA_ZOLWIA, INICJATYWA_ZOLWIA, posX, posY, "Zolw")
{
	swiat.dodajOrganizm(this);
}

void Zolw::rysowanie()
{
	cout << "Z";
}

bool Zolw::czyTenSamGatunek(Organizm* organizm)
{
	return dynamic_cast<Zolw*>(organizm) != nullptr;
}

void Zolw::utworzDziecko(int posX, int posY, Swiat& swiat)
{
	new Zolw(posX, posY, swiat);
}

bool Zolw::czyOdbilAtak(Organizm* atakujacy)
{
	if (atakujacy->getSila() < PANCERZ)
	{ 
		cout << "Zolw odbil atak" << endl;
		return true;
	}
	else return false;
}

