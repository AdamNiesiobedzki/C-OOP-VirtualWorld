#include "WilczeJagody.h"

#define SILA_WILCZE_JAGODY 99

WilczeJagody::WilczeJagody(int posX, int posY, Swiat& swiat)
	:Roslina(swiat, SILA_WILCZE_JAGODY, posX, posY, "WilczeJagody")
{
	swiat.dodajOrganizm(this);
}

void WilczeJagody::rysowanie()
{
	cout << "T";
}

bool WilczeJagody::czyTenSamGatunek(Organizm* organizm)
{
	return dynamic_cast<WilczeJagody*>(organizm) != nullptr;
}

void WilczeJagody::utworzDziecko(int posX, int posY, Swiat& swiat)
{
	new WilczeJagody(posX, posY, swiat);
}