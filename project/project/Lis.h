#pragma once
#include "Zwierze.h"
class Lis : public Zwierze
{
public:
	Lis(int posX, int posY, Swiat& swiat);
	void rysowanie();
	bool czyTenSamGatunek(Organizm* organizm);
	void utworzDziecko(int posX, int posY, Swiat& swiat);
	void akcja() override;
};

