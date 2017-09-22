#include<iostream>
#include"Map.h"
#include"Caterpillar.h"

int compare(Map map1, Map map2)
{
	int com = 0;
	for (int i = 0; i < map1.getH(); i++)
	{
		for (int j = 0; j < map1.getW(); j++)
		{
			if (map1.checkPlace(j, i) != map2.checkPlace(j, i))
			{
				com++;
			}
		}
	}
	return com;
}

using namespace std;
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