#pragma once
#include "Roslina.h"
class Guarana : public Roslina
{
public:
	Guarana(int posX, int posY, Swiat& swiat);
	void rysowanie();
	bool czyTenSamGatunek(Organizm* organizm);
	void utworzDziecko(int posX, int posY, Swiat& swiat);
	bool czyOdbilAtak(Organizm* atakujacy) override;
};

