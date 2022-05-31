#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
public:
	Roslina(Swiat& swiat, const int sila, const int posX, const int posY, string nazwa);
	void akcja() override;
	void przemiesc() override;
	int kolizja(Organizm* organizm) override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	int getNextX();
	int getNextY();
	void setNextMove();
};

