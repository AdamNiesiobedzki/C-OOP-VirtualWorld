#pragma once
#pragma warning(disable : 4996)
#include "Czlowiek.h"
#include <conio.h>
#include <iostream>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define INICJATYWA_CZLOWIEKA 4
#define SILA_CZLOWIEKA 4
#define DODATKOWA_SILA 10
#define CZAS_ODNOWIENIA 10

Czlowiek::Czlowiek(int posX, int posY, Swiat& swiat)
	:Zwierze(swiat,SILA_CZLOWIEKA,INICJATYWA_CZLOWIEKA,posX,posY, "Czlowiek")
{
	stop = 0;
	skillCD = 0;
	this->nextMove = 0;
	swiat.dodajOrganizm(this);
	swiat.przypiszCzlowieka(this);
}

void Czlowiek::rysowanie()
{
	cout << "C";
}

void Czlowiek::setNextMove()
{
	if (skillCD > 0) { skillCD--; sila--; }
	nextMove = getch();
	if (nextMove == 'q')
	{
		this->umiejetnosc();
		nextMove = getch();
		nextMove = getch();
	}
	else if (nextMove == 'p')stop = 1;
	else nextMove = getch();
}

void Czlowiek::akcja()
{
	if (nextMove == KEY_UP)
	{
		if(y > 0) 
			nextY--;
	}
	else if (nextMove == KEY_DOWN)
	{
		if (this->swiat.getHeight() - 1 > y) 
			nextY++;
	}
	else if (nextMove == KEY_LEFT)
	{
		if (x > 0) 
			nextX--;
	}
	else if (nextMove == KEY_RIGHT)
	{
		if (this->swiat.getWidth() - 1 > x) 
			nextX++;
	}
}

bool Czlowiek::czyTenSamGatunek(Organizm* organizm)
{
	return false;
}

void Czlowiek::utworzDziecko(int posX, int posY, Swiat& swiat)
{}

void Czlowiek::umiejetnosc()
{
	if (skillCD == 0)
	{
		this->zwiekszSile(DODATKOWA_SILA);
		skillCD = CZAS_ODNOWIENIA;
	}
}

