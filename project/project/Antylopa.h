#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze
{
public:
	Antylopa(int posX, int posY, Swiat& swiat);
	void rysowanie();
	bool czyTenSamGatunek(Organizm* organizm);
	void utworzDziecko(int posX, int posY, Swiat& swiat);
	void akcja() override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
};

