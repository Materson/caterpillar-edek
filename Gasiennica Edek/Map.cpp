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

	char ch = ' ';
	int k = 0;
	for (int i = 0; i < x*y; i++)
	{
		ch = ' ';
		k = 0;
		while (ch == ' ' || ch == '\n')
		{
			scanf_s("%c", &ch);
			while (ch >= '0' && ch <= '9')
			{
				k += ch - 48;
				k *= 10;
				scanf_s("%c", &ch);
			}
		}
		k /= 10;

		if (k > 0)
		{
			for (int j = 0; j < k; j++, i++)
			{
				area[i] = ch;
			}
			i--;
		}
		else
		{
			area[i] = ch;
		}

	}
}

Map::~Map()
{
}

void Map::show()
{
	for (int i = 0; i < x*y; i++)
	{
		
		printf_s("%c ", area[i]);
		
		if ((i+1) % x == 0)
		{
			cout << endl;
		}
	}
}
