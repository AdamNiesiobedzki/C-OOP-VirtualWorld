#include "Antylopa.h"

#define SILA_ANTYLOPY 4
#define INICJATYWA_ANTYLOPY 4
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define UCIECZKA 0

Antylopa::Antylopa(int posX, int posY, Swiat& swiat)
	:Zwierze(swiat, SILA_ANTYLOPY, INICJATYWA_ANTYLOPY, posX, posY, "Antylopa")
{
	swiat.dodajOrganizm(this);
}

void Antylopa::rysowanie()
{
	cout << "A";
}

bool Antylopa::czyTenSamGatunek(Organizm* organizm)
{
	return dynamic_cast<Antylopa*>(organizm) != nullptr;
}

void Antylopa::utworzDziecko(int posX, int posY, Swiat& swiat)
{
	new Antylopa(posX, posY, swiat);
}

void Antylopa::akcja()
{
	wykonanoRuch = 1;
	int direction;
	direction = rand() % 4;
	if (direction == UP)
	{
		if (y > 1)
		{
			nextY--;
			nextY--;
		}	
	}
	else if (direction == DOWN)
	{
		if (this->swiat.getHeight() - 2 > y)
		{
			nextY++;
			nextY++;
		}
	}
	else if (direction == LEFT)
	{
		if (x > 1)
		{
			nextX--;
			nextX--;
		}
	}
	else if (direction == RIGHT)
	{
		if (this->swiat.getWidth() - 2 > x)
		{
			nextX++;
			nextX++;
		}	
	}
}

bool Antylopa::czyOdbilAtak(Organizm* organizm)
{
	int obrona = rand() % 2;
	int sukces = 0;
	if (obrona == UCIECZKA)
	{
		if (y - 1 >= 0 && swiat.getPolePlanszy(x, y - 1) == nullptr)
		{
			y--;
			nextY = y;
			sukces = 1;
		}
		else if (x - 1 >= 0 && swiat.getPolePlanszy(x - 1, y) == nullptr)
		{
			x--;
			nextX = x;
			sukces = 1;
		}
		else if (x + 1 < swiat.getWidth() && swiat.getPolePlanszy(x + 1, y) == nullptr)
		{
			x++;
			nextX = x;
			sukces = 1;
		}
		else if (y + 1 < swiat.getHeight() && swiat.getPolePlanszy(x, y + 1) == nullptr)
		{
			y++;
			nextY = y;
			sukces = 1;
		}
	}
	if (sukces == 1)
	{
		cout << "Antylopie udalo sie uciec" << endl;
		return true;
	} 
	else return false;
}