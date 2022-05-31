#pragma once
#include "Roslina.h"
class Mlecz :public Roslina
{
public:
	Mlecz(int posX, int posY, Swiat& swiat);
	void rysowanie();
	bool czyTenSamGatunek(Organizm* organizm);
	void utworzDziecko(int posX, int posY, Swiat& swiat);
	void akcja() override;
};

