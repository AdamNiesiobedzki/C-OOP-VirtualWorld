#pragma once
#include <iostream>
#include "Swiat.h"
using namespace std;

class Swiat;

class Organizm
{
protected:
	int sila;
	int inicjatywa;
	int wiek;
	int x, y;
	string nazwa;
	int nextX, nextY;
	int wykonanoRuch;
	Swiat& swiat;
	int stop;
public:
	Organizm(Swiat& swiat, const int sila, const int inicjatywa, const int posX, const int posY, string nazwa);
	void set_X(int x);
	void set_Y(int y);
	int getSila();
	int getStop(); //co to?
	int getInicjatywa();
	int getWiek();
	int getX();
	int getY();
	int getNextX();
	int getNextY();
	string getNazwa();
	int czyWykonanoRuch();
	virtual void setNextMove() = 0;
	void postarz();
	void zwiekszSile(int bonus);
	virtual void akcja() = 0;
	virtual void przemiesc() = 0;
	virtual int kolizja(Organizm* organizm) = 0;
	virtual void rysowanie() = 0;
	void rozmnazanie();
	virtual void utworzDziecko(int posX, int posY, Swiat& swiat) = 0;
	virtual bool czyTenSamGatunek(Organizm* organizm) = 0;
	virtual bool czyOdbilAtak(Organizm* atakujacy) = 0;
	void zostanWMiejscu();
	bool czyCzlowiek();
};