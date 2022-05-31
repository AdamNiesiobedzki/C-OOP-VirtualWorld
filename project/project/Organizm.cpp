#pragma once
#include "Organizm.h"
#include "Czlowiek.h"

Organizm::Organizm(Swiat& swiat, const int sila, const int inicjatywa, const int posX, const int posY, string nazwa)
	:swiat(swiat), sila(sila), inicjatywa(inicjatywa), x(posX), y(posY), nextX(posX), nextY(posY), wiek(0), wykonanoRuch(0), nazwa(nazwa)
{}

int Organizm::getSila()
{
	return sila;
}

int Organizm::getStop()
{
	return stop;
}

string Organizm::getNazwa()
{
	return nazwa;
}

int Organizm::getInicjatywa()
{
	return inicjatywa;
}

int Organizm::getWiek()
{
	return wiek;
}

int Organizm::getX()
{
	return x;
}

int Organizm::getY()
{
	return y;
}

int Organizm::getNextX()
{
	return nextX;
}

int Organizm::getNextY()
{
	return nextY;
}

int Organizm::czyWykonanoRuch()
{
	return wykonanoRuch;
}

void Organizm::postarz()
{
	wiek++;
	wykonanoRuch = 0;
}

void Organizm::zwiekszSile(int bonus)
{
	sila = sila + bonus;
}

void Organizm::rozmnazanie()
{
	if (y - 1 >= 0 && swiat.getPolePlanszy(x, y - 1) == nullptr)
	{
		this->utworzDziecko(x, y - 1, swiat);
		cout << "Rodzi sie nowy " << getNazwa() << endl;
	}
	else if (x - 1 >= 0 && swiat.getPolePlanszy(x - 1, y) == nullptr)
	{
		this->utworzDziecko(x - 1, y, swiat);
	}
	else if (x + 1 < swiat.getWidth() && swiat.getPolePlanszy(x + 1, y) == nullptr)
	{
		this->utworzDziecko(x + 1, y, swiat);
	}
	else if (y + 1 < swiat.getHeight() && swiat.getPolePlanszy(x, y + 1) == nullptr)
	{
		this->utworzDziecko(x, y + 1, swiat);
	}
}

void Organizm::zostanWMiejscu()
{
	nextX = x;
	nextY = y;
}

bool Organizm::czyOdbilAtak(Organizm* atakujacy)
{
	return false;
}

bool Organizm::czyCzlowiek()
{
	return dynamic_cast<Czlowiek*>(this) != nullptr;
}

