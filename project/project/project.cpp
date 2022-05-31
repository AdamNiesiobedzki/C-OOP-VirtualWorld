#include <iostream>
#include "Swiat.h"
#include "Swiat_parametry.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "BarszczSosnowskiego.h"
#include "WilczeJagody.h"
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void preset()
{
	Swiat_parametry config;
	Swiat swiat(config.getWidth(), config.getHeight());
	Czlowiek* Hania = new Czlowiek(config.getWidth() / 2, config.getHeight() / 2, swiat);
	Wilk* Sendi = new Wilk(10, 1, swiat);
	Wilk* Bibi = new Wilk(16, 1, swiat);
	Wilk* Drops = new Wilk(15, 15, swiat);
	Lis* lisek = new Lis(11, 13, swiat);
	Lis* lis = new Lis(15, 10, swiat);
	BarszczSosnowskiego* barszczyk = new BarszczSosnowskiego(1, 1, swiat);
	Trawa* trawa = new Trawa(12, 12, swiat);
	Mlecz* mlecz = new Mlecz(4, 2, swiat);
	Zolw* zolw = new Zolw(2, 5, swiat);
	Zolw* zolw2 = new Zolw(6, 4, swiat);
	Antylopa* antylopa = new Antylopa(1, 18, swiat);
	Antylopa* antylopa2 = new Antylopa(18, 7, swiat);
	Guarana* guarana = new Guarana(7, 10, swiat);
	while (true)
	{
		swiat.wykonajTure();
	}
}

void wczytaj()
{
	fstream plik;
	plik.open("zapis.txt", ios::in);
	string linia;
	int nr_linii = 1;
	int width;
	int height;
	getline(plik, linia); 
	width = atoi(linia.c_str());
	getline(plik, linia);
	height = atoi(linia.c_str());
	Swiat swiat(width, height);
	while (getline(plik, linia))
	{
		string x,y; 
		int posX, posY;
		getline(plik, x); getline(plik, y);
		posX = atoi(x.c_str());
		posY = atoi(y.c_str());
		if (linia == "Antylopa")new Antylopa(posX, posY, swiat);
		else if(linia == "BarszczSosnowskiego") new BarszczSosnowskiego(posX, posY, swiat);
		else if(linia == "Czlowiek") new Czlowiek(posX, posY, swiat);
		else if(linia == "Guarana") new Guarana(posX, posY, swiat);
		else if(linia == "Lis") new Lis(posX, posY, swiat);
		else if(linia == "Mlecz") new Mlecz(posX, posY, swiat);
		else if(linia == "Trawa") new Trawa(posX, posY, swiat);
		else if(linia == "WilczeJagody") new WilczeJagody(posX, posY, swiat);
		else if(linia == "Wilk") new Wilk(posX, posY, swiat);
		else if(linia == "Zolw") new Zolw(posX, posY, swiat);
	}
	plik.close();
	while (true)
	{
		swiat.wykonajTure();
	}
}

int main()
{
	int select;
	cout << "1. Rozpocznij gre" << endl << "2. Wczytaj gre" << endl;
	cin >> select;
	if (select == 1)
	{
		preset();
	}
	else if (select == 2)
	{
		wczytaj();
	}
}

