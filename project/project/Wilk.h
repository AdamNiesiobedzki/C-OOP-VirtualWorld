#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
public:
	Wilk(int posX, int posY, Swiat& swiat);
	void rysowanie();
	bool czyTenSamGatunek(Organizm* organizm);
	void utworzDziecko(int posX, int posY, Swiat& swiat);
};