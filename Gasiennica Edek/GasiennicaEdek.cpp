// GasiennicaEdek.cpp: Definiuje punkt wejścia dla aplikacji konsolowej.
//
#include<iostream>
#include"Map.h"

using namespace std;

int main()
{
	int x, y;
	cout << "Podaj szerokosc i wysokosc mapy"<<endl;
	cin >> x;
	cin >> y;

	Map *map = new Map(x, y);
	map->show();


    return 0;
}

