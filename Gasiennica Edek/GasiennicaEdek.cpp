#include<iostream>
#include"Map.h"
#include"Caterpillar.h"

int main()
{
	int x = 0, y = 0, z = 0;
	scanf("%d%d%d", &x, &y, &z);
	Map map(x, y, z);

	map.round();
	map.printEdekPosition();
	map.show();

    return 0;
}