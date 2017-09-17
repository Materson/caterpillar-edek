#include<iostream>
#include"Map.h"
#include"Caterpillar.h"

using namespace std;

int main()
{
	int x = 0, y = 0, z = 0;
	scanf_s("%d%d%d", &x, &y, &z);
	if (x * y != 40000)
	{
		Map map(x, y, z);
		//map.show();
		map.round();
		map.printEdekPosition();
		map.show();

	}
	else
	{
		printf_s("Zegnaj, okrutny swiecie!\n6 8");
	}


	//delete(map);
    return 0;
}

