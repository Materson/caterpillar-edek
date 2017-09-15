#include "Map.h"
#include<iostream>
#include"Caterpillar.h"
using namespace std;


Map::Map()
{
}


Map::Map(int x, int y, int z)
	:w(x), h(y)
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

	Edek = new Caterpillar(z, w, h, this);
}

Map::~Map()
{
}

void Map::show()
{
	for (int i = 0; i < w*h; i++)
	{
		
		printf_s("%c", area[i]);
		
		if ((i+1) % w == 0)
		{
			cout << endl;
		}
	}
}

void Map::round()
{
	char ch = ' ';
	scanf_s("%c", &ch);
	ch = ' ';
	int k;
	while (ch != '\n')
	{
		ch = ' ';
		k = 0;
		while (ch == ' ')
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
			for (int i = 0; i < k; i++)
			{
				Edek->move(ch);
			}
		}
		else
		{
			Edek->move(ch);
		}
	}
}

int Map::getW()
{
	return w;
}

int Map::getH()
{
	return h;
}

char Map::checkPlace(int x, int y)
{
	if (x < 0 || x >= w || y < 0 || y >= h)
	{
		return 'T';
	}
	return area[y*h + x];
}

void Map::printEdekPosition()
{
	printf_s("%d %d \n", Edek->getX(), Edek->getY());
}

void Map::paint(int x, int y, char c)
{
	area[h*y + x] = c;
}