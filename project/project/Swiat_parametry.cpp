#pragma once
#include "Swiat_parametry.h"
#include <iostream>
using namespace std;

Swiat_parametry::Swiat_parametry()
{
	srand(time(NULL));
	cout << "Podaj szerokosc swiata" << endl;
	cin >> this->width;
	cout << "Podaj wysokosc swiata" << endl;
	cin >> this->height;
}

int Swiat_parametry::getHeight()
{
	return this->height;
}

int Swiat_parametry::getWidth()
{
	return this->width;
}