#include<iostream>
#include"Map.h"
#include"Caterpillar.h"

using namespace std;

int main()
{
	int x = 0, y = 0, z = 0;
	scanf_s("%d%d%d", &x, &y, &z);

	Map *map = new Map(x, y, z);
	map->round();
	map->printEdekPosition();
	map->show();

	delete(map);
    return 0;
}

