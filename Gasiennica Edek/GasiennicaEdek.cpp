#include<iostream>
#include"Map.h"
#include"Caterpillar.h"

using namespace std;

int main()
{
	int x = 0, y = 0, z = 0;
	scanf_s("%d%d%d", &x, &y, &z);
	Map map(x, y, z);
	map.show();
	map.checkPlace(2, 3);
	//map.round();
	//map.printEdekPosition();


    return 0;
}

