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
	int c = x*y;
	/*if (x * y == 40000)
	{
		c = 100;
		w = 10;
		h = 10;
	}*/
	area = new char[c];

	char ch = ' ';
	int k = 0;
	for (int i = 0; i < c; i++)
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
				if (Edek->move(ch)) //if 1 Edek die
				{
					printf_s("Zegnaj, okrutny swiecie!\n");
					ch = '\n';
				}
			}
		}
		else
		{
			if (Edek->move(ch)) //if 1 Edek die
			{
				printf_s("Zegnaj, okrutny swiecie!\n");
				ch = '\n';
			}
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
	return area[y*w + x];
}

void Map::printEdekPosition()
{
	printf_s("%d %d \n", Edek->getX(), Edek->getY());
}

void Map::paint(int x, int y, char c)
{
	area[w*y + x] = c;
}