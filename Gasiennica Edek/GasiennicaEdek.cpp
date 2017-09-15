#include<iostream>
#include"Map.h"
#include"Caterpillar.h"

using namespace std;

int main()
{
	int x, y, z;
	scanf_s("%d %d %d", &x, &y, &z);

	Map *map = new Map(x, y, z);
	map->round();
	map->printEdekPosition();
	map->show();

    return 0;
}

