#include "BarszczSosnowskiego.h"

#define SILA_BARSZCZ 10

BarszczSosnowskiego::BarszczSosnowskiego(int posX, int posY, Swiat& swiat)
	:Roslina(swiat, SILA_BARSZCZ, posX, posY, "BarszczSosnowskiego")
{
	swiat.dodajOrganizm(this);
}

void BarszczSosnowskiego::rysowanie()
{
	cout << "B";
}

bool BarszczSosnowskiego::czyTenSamGatunek(Organizm* organizm)
{
	return dynamic_cast<BarszczSosnowskiego*>(organizm) != nullptr;
}

void BarszczSosnowskiego::utworzDziecko(int posX, int posY, Swiat& swiat)
{
	new BarszczSosnowskiego(posX, posY, swiat);
}

void BarszczSosnowskiego::akcja()
{
	wykonanoRuch = 1;

	if (y > 0)
	{
		int deleteX = x;
		int deleteY = y - 1;
		swiat.usunOrganizm(deleteX, deleteY);
		if (x > 0)
		{
			deleteX = x - 1;
			swiat.usunOrganizm(deleteX, deleteY);
		}
		if (x < swiat.getWidth() - 1)
		{
			deleteX = x + 1;
			swiat.usunOrganizm(deleteX, deleteY);
		}
	}
	if (x > 0)
	{
		int deleteX = x - 1;
		int deleteY = y;
		swiat.usunOrganizm(deleteX, deleteY);
		if (y > 0)
		{
			deleteY = y - 1;
			swiat.usunOrganizm(deleteX, deleteY);
		}
		if (y < swiat.getHeight() - 1)
		{
			deleteY = y + 1;
			swiat.usunOrganizm(deleteX, deleteY);
		}
	}
	if (y < swiat.getHeight() - 1)
	{
		int deleteY = y + 1;
		int deleteX = x;
		swiat.usunOrganizm(deleteX, deleteY);
		if (x > 0)
		{
			deleteX = x - 1;
			swiat.usunOrganizm(deleteX, deleteY);
		}
		if (x < swiat.getWidth() - 1)
		{
			deleteX = x + 1;
			swiat.usunOrganizm(deleteX, deleteY);
		}
	}
	if (x < swiat.getWidth() - 1)
	{
		int deleteX = x + 1;
		int deleteY = y;
		swiat.usunOrganizm(deleteX, deleteY);
		if (y > 0)
		{
			deleteY = y - 1;
			swiat.usunOrganizm(deleteX, deleteY);
		}
		if (y < swiat.getHeight() - 1)
		{
			deleteY = y + 1;
			swiat.usunOrganizm(deleteX, deleteY);
		}
	}
}