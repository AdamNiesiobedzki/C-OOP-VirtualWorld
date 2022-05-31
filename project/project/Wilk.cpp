#include "Wilk.h"

#define SILA_WILKA 9
#define INICJATYWA_WILKA 5

Wilk::Wilk(int posX, int posY, Swiat& swiat)
	:Zwierze(swiat, SILA_WILKA, INICJATYWA_WILKA, posX, posY, "Wilk")
{
	swiat.dodajOrganizm(this);
}

void Wilk::rysowanie()
{
	cout << "W";
}

bool Wilk::czyTenSamGatunek(Organizm* organizm)
{
	return dynamic_cast<Wilk*>(organizm) != nullptr;
}

void Wilk::utworzDziecko(int posX, int posY, Swiat& swiat)
{
	new Wilk(posX, posY, swiat);
}
