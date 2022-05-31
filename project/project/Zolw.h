#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
public:
	Zolw(int posX, int posY, Swiat& swiat);
	void rysowanie();
	bool czyTenSamGatunek(Organizm* organizm);
	void utworzDziecko(int posX, int posY, Swiat& swiat);
	bool czyOdbilAtak(Organizm* atakujacy) override;
};