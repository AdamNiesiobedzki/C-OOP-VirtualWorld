#pragma once
#include "Roslina.h"

#define INICJATYWA_ROSLINY 0
#define SZANSA_NA_ROZSIANIE 1

Roslina::Roslina(Swiat& swiat, const int sila, const int posX, const int posY, string nazwa)
	:Organizm(swiat, sila, INICJATYWA_ROSLINY, posX, posY, nazwa)
{}

void Roslina::akcja()
{
	wykonanoRuch = 1;
	int zasiew = rand() % 10;
	if (zasiew < SZANSA_NA_ROZSIANIE)
	{
		this->rozmnazanie();
	}
}

void Roslina::przemiesc()
{
	x = nextX;
	y = nextY;
}

int Roslina::kolizja(Organizm* organizm)
{
	return false;
}

bool Roslina::czyOdbilAtak(Organizm* atakujacy)
{
	return false;
}

void Roslina::setNextMove()
{}