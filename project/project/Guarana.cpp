#include "Guarana.h"


#define SILA_GUARANY 0
#define BONUS_SILY 3

Guarana::Guarana(int posX, int posY, Swiat& swiat)
	:Roslina(swiat, SILA_GUARANY, posX, posY, "Guarana")
{
	swiat.dodajOrganizm(this);
}

void Guarana::rysowanie()
{
	cout << "G";
}

bool Guarana::czyTenSamGatunek(Organizm* organizm)
{
	return dynamic_cast<Guarana*>(organizm) != nullptr;
}

void Guarana::utworzDziecko(int posX, int posY, Swiat& swiat)
{
	new Guarana(posX, posY, swiat);
}

bool Guarana::czyOdbilAtak(Organizm* atakujacy)
{
	atakujacy->zwiekszSile(BONUS_SILY);
	return false;
}