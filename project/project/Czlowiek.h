#pragma once
#include "Zwierze.h"


class Czlowiek : public Zwierze
{
private:
	int nextMove;
	int skillCD;
public:
	Czlowiek(int posX,int posY, Swiat& swiat);
	void setNextMove() override;
	void akcja() override;
	void rysowanie();
	bool czyTenSamGatunek(Organizm* organizm);
	void utworzDziecko(int posX, int posY, Swiat& swiat);
	void umiejetnosc();
};