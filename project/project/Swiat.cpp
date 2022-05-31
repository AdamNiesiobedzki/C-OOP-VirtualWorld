#pragma once

#include "Swiat.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#define WYGRANA 1
#define PRZEGRANA 2
#define ROZMNAZANIE 3
#define REMIS 4
#define BRAK_KOLIZJI 0


Swiat::Swiat(const int& width, const int& height)
	:width(width), height(height), tura(0), populacja(0), czlowiek(nullptr)
{
	if (width <= 0 or height <= 0)
	{
		cerr << "Niew³aœciwe parametry" << endl;
		return;
	}
	else
	{
		for (int y = 0; y < height; y++)
		{
			plansza.push_back(vector<Organizm*>());
			for (int x = 0; x < width; x++)
			{
				plansza[y].push_back(nullptr);
			}
		}
		organizmy = new Organizm*[width * height];
		for (int i = 0; i < width * height; i++)
		{
			organizmy[i] = nullptr;
		}
	}
}

int Swiat::getHeight()
{
	return height;
}

int Swiat::getWidth()
{
	return width;
}

int Swiat::getPopulacja()
{
	return populacja;
}

void Swiat::przypiszCzlowieka(Organizm* organizm)
{
	czlowiek = organizm;
}

void Swiat::rysuj()
{
	cout << "+";
	for (int k = 0; k < getWidth(); k++)
	{
		cout << "_";
	}
	cout << "+" << endl;
	for (int y = 0; y < getHeight(); y++)
	{
		cout << "|";
		for (int x = 0; x < getWidth(); x++)
		{
			if (plansza[y][x]==nullptr)
			{
				cout << " ";
			}
			else plansza[y][x][0].rysowanie();
		}
		cout << "|" << endl;
	}
	cout << "+";
	for (int k = 0; k < getWidth(); k++)
	{
		cout << "_";
	}
	cout << "+" << endl;
	cout << endl;
}

void Swiat::rysujInterface()
{
	cout << "Tura: " << tura << endl;
	cout << "Sterowanie: ruch - strzalki, r - umiejetnosc, p - zapisz i zakoncz gre" << endl;
	cout << "Statystyki cz³owieka: " << " sila: " << czlowiek->getSila() << "  inicjatywa: " << czlowiek->getInicjatywa() << endl;
	cout << "Wydarzenia:" << endl;
}

void Swiat::dodajOrganizm(Organizm* nowyOrganizm)
{
	organizmy[getPopulacja()] = nowyOrganizm;
	populacja++;
}

void Swiat::aktualizujPlansze()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			plansza[y][x] = nullptr;
		}
	}
	for (int i = 0; i < populacja; i++)
	{
		if (organizmy[i] != nullptr)
		{
			int posX = organizmy[i][0].getX();
			int posY = organizmy[i][0].getY();
			plansza[posY][posX] = organizmy[i];
		}
	}
}

int Swiat::wykonajTure()
{
	if (czlowiek != nullptr) czlowiek->setNextMove();
	else Sleep(1000);
	system("CLS");
	if (czlowiek != nullptr && czlowiek->getStop() == 1) {
		save();
		return 0;
	}
	this->rysujInterface();
	for (int i = 0; i < populacja; i++)
	{
		if (organizmy[i] != nullptr && organizmy[i][0].getWiek()!= 0)
		{
			organizmy[i][0].akcja();
			int result = BRAK_KOLIZJI;
			for (int j = 0; j < populacja; j++)
			{
				if (j != i && organizmy[j] != nullptr && organizmy[i] != nullptr)
				{
					if (organizmy[i][0].getNextX() == organizmy[j][0].getNextX()
						&& organizmy[i][0].getNextY() == organizmy[j][0].getNextY())
					{
						result = organizmy[i][0].kolizja(organizmy[j]);
						if (result == WYGRANA)
						{
							zabij(organizmy[i], organizmy[j]);
							delete organizmy[j];
							organizmy[j] = nullptr;
							organizmy[i][0].przemiesc();
						}
						else if (result == PRZEGRANA)
						{
							zabij(organizmy[j], organizmy[i]);
							delete organizmy[i];
							organizmy[i] = nullptr;
						}
						else if (result == ROZMNAZANIE)
						{
							organizmy[i][0].rozmnazanie();
							organizmy[i][0].zostanWMiejscu();
						}
						else if (result == REMIS)
						{
							organizmy[i][0].zostanWMiejscu();
						}
					}
				}
				this->aktualizujPlansze();
			}
			if (result == BRAK_KOLIZJI) organizmy[i][0].przemiesc();
		}
	}
	tura++;
	this->sortujOrganizmy();
	this->zliczOrganizmy();
	this->aktualizujPlansze();
	this->rysuj();
	this->postarzOrganizmy();
	return 1;
}

void Swiat::save()
{
	cout << "Zapisano do pliku";
	fstream plik;
	plik.open("zapis.txt", ios::out);
	plik << getWidth() << endl << getHeight() << endl;
	for (int i = 0; i < populacja; i++)
	{
		plik << organizmy[i]->getNazwa() << endl << organizmy[i]->getX() << endl << organizmy[i]->getY() << endl;
	}
	plik.close();
}

void Swiat::sortujOrganizmy()
{
	Organizm* tmp;
	while (true)
	{
		int zamiana = 0;
		for (int z = 0; z < 2; z++)
		{
			for (int i = 1; i < populacja; i++)
			{
				if (organizmy[i] != nullptr)
				{
					if (organizmy[i - 1] == nullptr)
					{
						tmp = organizmy[i];
						organizmy[i] = organizmy[i - 1];
						organizmy[i - 1] = tmp;
						zamiana = 1;
					}
					else if (organizmy[i][0].getInicjatywa() > organizmy[i - 1][0].getInicjatywa())
					{
						tmp = organizmy[i];
						organizmy[i] = organizmy[i - 1];
						organizmy[i - 1] = tmp;
						zamiana = 1;
					}
					else if (organizmy[i][0].getInicjatywa() == organizmy[i - 1][0].getInicjatywa())
					{
						if (organizmy[i][0].getWiek() > organizmy[i - 1][0].getWiek())
						{
							tmp = organizmy[i];
							organizmy[i] = organizmy[i - 1];
							organizmy[i - 1] = tmp;
							zamiana = 1;
						}
					}
				}
			}
		}
		if (zamiana == 0) break;
	}
}

void Swiat::postarzOrganizmy()
{
	for (int i = 0; i < populacja; i++)
	{
		if(organizmy[i]!=nullptr)
		organizmy[i][0].postarz();
	}
}

Organizm* Swiat::getPolePlanszy(int x, int y)
{
	return plansza[y][x];
}

void Swiat::zliczOrganizmy()
{
	populacja = 0;
	for (int i = 0; i < width * height; i++)
	{
		if (organizmy[i] != nullptr) populacja++;
	}
}

void Swiat::usunOrganizm(int posX, int posY)
{
	for (int i = 0; i < populacja; i++)
	{
		if (organizmy[i] != nullptr)
		{
			if (organizmy[i][0].getX() == posX && organizmy[i][0].getY() == posY)
			{
				cout << "BarszczSosnowskiego zabija " << organizmy[i]->getNazwa() << endl; 
				delete organizmy[i];
				organizmy[i] = nullptr;
			}
		}
	}
}

bool Swiat::czyBezpieczne(int posX, int posY, int sila)
{
	for (int i = 0; i < populacja; i++)
	{
		if (organizmy[i] != nullptr)
		{
			if (organizmy[i][0].getX() == posX && organizmy[i][0].getY() == posY)
			{
				if (organizmy[i][0].getSila() <= sila) return true;
				else return false;
			}
		}
	}
	return true;
}

void Swiat::zabij(Organizm* zabija, Organizm* umiera)
{
	cout << zabija->getNazwa() << " zabija " << umiera->getNazwa() << endl;
}