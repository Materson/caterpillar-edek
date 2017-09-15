#include<iostream>
#include"Map.h"
#include"Caterpillar.h"

using namespace std;

int main()
{
	int x, y;
	cout << "Podaj szerokosc i wysokosc mapy"<<endl;
	cin >> x;
	cin >> y;

	Map *map = new Map(x, y);
	map->show();

	cin >> x;

	Caterpillar *Edek = new Caterpillar(x);

	cin >> x;

    return 0;
}

