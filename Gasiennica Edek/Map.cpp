#include "Map.h"
#include<iostream>

using namespace std;


Map::Map()
{
}


Map::Map(int x, int y)
	:x(x), y(y)
{
	area = new char[x*y];

	char ch;
	
	for (int i = 0; i < x*y; i++)
	{
		scanf_s("%c", &ch);
		//cin >> ch;.
		area[i] = ch;

	}
}

Map::~Map()
{
}

void Map::show()
{
	for (int i = 0; i < x*y; i++)
	{
		
		cout << area[i];
		
		if ((i+1) % x == 0)
		{
			cout << endl;
		}
	}
}
