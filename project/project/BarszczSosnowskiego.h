#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :public Roslina
{
public:
	BarszczSosnowskiego(int posX, int posY, Swiat& swiat);
	void rysowanie();
	bool czyTenSamGatunek(Organizm* organizm);
	void utworzDziecko(int posX, int posY, Swiat& swiat);
	void akcja() override;
};

