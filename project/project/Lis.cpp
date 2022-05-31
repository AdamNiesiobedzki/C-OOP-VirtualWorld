#include "Lis.h"

#define SILA_LISA 3
#define INICJATYWA_LISA 7
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

Lis::Lis(int posX, int posY, Swiat& swiat)
	:Zwierze(swiat, SILA_LISA, INICJATYWA_LISA, posX, posY, "Lis")
{
	swiat.dodajOrganizm(this);
}

void Lis::rysowanie()
{
	cout << "L";
}

bool Lis::czyTenSamGatunek(Organizm* organizm)
{
	return dynamic_cast<Lis*>(organizm) != nullptr;
}

void Lis::utworzDziecko(int posX, int posY, Swiat& swiat)
{
	new Lis(posX, posY, swiat);
}

void Lis::akcja()
{
	int sprawdzX;
	int sprawdzY;
	wykonanoRuch = 1;
	int direction;
	direction = rand() % 4;
	if (direction == UP)
	{
		if (y > 0)
		{
			sprawdzX = nextX;
			sprawdzY = nextY - 1;
			if (swiat.czyBezpieczne(sprawdzX, sprawdzY, getSila())) nextY--;
		}
			
	}
	else if (direction == DOWN)
	{
		if (this->swiat.getHeight() - 1 > y)
		{
			sprawdzY = nextY + 1;
			sprawdzX = nextX;
			if (swiat.czyBezpieczne(sprawdzX, sprawdzY, getSila())) nextY++;
		}
	}
	else if (direction == LEFT)
	{
		if (x > 0)
		{
			sprawdzX = nextX - 1;
			sprawdzY = nextY;
			if (swiat.czyBezpieczne(sprawdzX, sprawdzY, getSila())) nextX--;
		}
			
	}
	else if (direction == RIGHT)
	{
		if (this->swiat.getWidth() - 1 > x)
		{
			sprawdzX = nextX + 1;
			sprawdzY = nextY;
			if (swiat.czyBezpieczne(sprawdzX, sprawdzY, getSila())) nextX++;
		}	
	}
}

