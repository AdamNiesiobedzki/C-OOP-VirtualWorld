#pragma once
#include "Zwierze.h"
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define WYGRANA 1
#define PRZEGRANA 2
#define ROZMNAZANIE 3
#define REMIS 4

Zwierze::Zwierze(Swiat& swiat, const int sila, const int inicjatywa, const int posX, const int posY, string nazwa)
	:Organizm(swiat,sila,inicjatywa,posX,posY,nazwa)
{}

void Zwierze::akcja()
{
	wykonanoRuch = 1;
	int direction;
	direction = rand() % 4;
	if (direction == UP)
	{
		if (y > 0)
			nextY--;
	}
	else if (direction == DOWN)
	{
		if (this->swiat.getHeight() - 1 > y)
			nextY++;
	}
	else if (direction == LEFT)
	{
		if (x > 0)
			nextX--;
	}
	else if (direction == RIGHT)
	{
		if (this->swiat.getWidth() - 1 > x)
			nextX++;
	}
}

void Zwierze::przemiesc()
{
	x = nextX;
	y = nextY;
}

int Zwierze::kolizja(Organizm* organizm)
{
	if(this->czyTenSamGatunek(organizm))
	{
		return ROZMNAZANIE;
	}
	else if (this->getSila() >= organizm[0].getSila())
	{
		if (organizm[0].czyOdbilAtak(this))
		{
			return REMIS;
		}
		else return WYGRANA;
	}
	else if (this->getSila() < organizm[0].getSila())
	{
		if (this->czyOdbilAtak(organizm)) return REMIS;
		else return PRZEGRANA;
	}
}

bool Zwierze::czyOdbilAtak(Organizm* atakujacy)
{
	return false;
}

void Zwierze::setNextMove()
{}

