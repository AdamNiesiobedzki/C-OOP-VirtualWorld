#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
public:
	Trawa(int posX, int posY, Swiat& swiat);
	void rysowanie();
	bool czyTenSamGatunek(Organizm* organizm);
	void utworzDziecko(int posX, int posY, Swiat& swiat);
};

