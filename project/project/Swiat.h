#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include "Organizm.h"
using namespace std;
class Organizm;


class Swiat
{
private:
	int width;
	int height;
	int tura;
	int populacja;
	vector < vector < Organizm* > > plansza;
	Organizm** organizmy;
	Organizm* czlowiek;
public:
	Swiat(const int& width, const int& height);

	void rysuj();
	void rysujInterface();
	void save();
	int getWidth();
	int getHeight();
	int getPopulacja();
	void dodajOrganizm(Organizm* nowyOrganizm);
	void przypiszCzlowieka(Organizm* organizm);
	void aktualizujPlansze();
	int wykonajTure();
	void sortujOrganizmy();
	void postarzOrganizmy();
	void zliczOrganizmy();
	Organizm* getPolePlanszy(int x, int y);
	void usunOrganizm(int posX, int posY);
	bool czyBezpieczne(int posX, int posY, int sila);
	void zabij(Organizm* zabija, Organizm* umiera);
};