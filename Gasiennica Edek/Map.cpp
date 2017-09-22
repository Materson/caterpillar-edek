#define MAX 1000
#include "Map.h"
#include<iostream>
#include"Caterpillar.h"
using namespace std;


Map::Map()
{
}

Map::Map(int wid, int hei, int z)
	:w(wid), h(hei)
{
	area = NULL;
	areaBig = NULL;
	if (w > 1000)
	{
		areaBig = new char**[w/MAX];
		for (int i = 0; i < w / MAX; i++)
		{
			areaBig[i] = new char*[MAX];
			for (int j = 0; j < MAX; j++)
			{
				areaBig[i][j] = new char[h];
				for (int k = 0; k < h; k++)
				{
					areaBig[i][j][k] = '.';
				}
			}
		}
	}
	else
	{
		area = new char*[wid];
		for (int i = 0; i < w; i++)
		{
			area[i] = new char[h];
			for (int j = 0; j < h; j++)
			{
				area[i][j] = '.';
			}
		}
	}

	char ch = ' ';
	int counter = 0, x = 0, y = 0;
	int c = w*h;
	for (int i = 0; i < c; i++)	//start load map
	{
		ch = ' ';
		counter = 0;
		while (ch == ' ' || ch == '\n')
		{
			ch = getchar();
			while (ch >= '0' && ch <= '9')
			{
				counter *= 10;
				counter += ch - 48;
				ch = getchar();
			}
		}
		
		if (counter > 0)
		{
			if (ch == '.')
			{
				x += counter;
				y += x / w;
				x = x%w;
				i += counter;
			}
			else
			{
				for (int j = 0; j < counter; j++, i++)
				{
					if (area != NULL)
					{
						area[x][y] = ch;
					}
					else
					{
						areaBig[x / MAX][x%MAX][y] = ch;
					}
					x++;
					if (x == w)
					{
						y++;
						x = 0;
					}
				}
			}
			i--;	//remove digit from load
		}
		else
		{
			if (ch != '.')
			{
				if (area != NULL)
				{
					area[x][y] = ch;
				}
				else
				{
					areaBig[x / MAX][x%MAX][y] = ch;
				}
			}
			x++;
			if (x == w)
			{
				y++;
				x = 0;
			}
		}
	}
	Edek = new Caterpillar(z, w, h, this);
}

Map::~Map()
{
	if (area != NULL)
	{
		for (int i = 0; i < w; i++)
		{
			delete[](area[i]);
		}
	delete[](area);
	}
	else
	{
		for (int i = 0; i < w / MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				delete[](areaBig[i][j]);
			}
			delete[](areaBig[i]);
		}
		delete[](areaBig);
	}
	delete(Edek);
}

void Map::show()
{
	if (area != NULL)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				printf("%c", area[j][i]);
			}
			printf("\n");
		}
	}
	else
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w / MAX; j++)
			{
				for (int k = 0; k < MAX; k++)
				{
					printf("%c", areaBig[j][k][i]);
				}
			}
			printf("\n");
		}
	}
}
//int moves = 0;
int Map::round()
{
	char ch = ' ';
	ch = getchar();
	if (ch == EOF)
	{
		return 0;
	}

	if (ch == ' ')
	{
		while (ch != '\n' && !(ch >= '0' && ch <= '9' || ch >= 'a'&& ch <= 'z'))
		{
			ch = getchar();
			if (ch == EOF)
			{
				return 0;
			}
		}
	}

	char tmp = ' ';
	if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z')
	{
		tmp = ch;
	}

	int counter;
	ch = ' ';
	while (ch != EOF)	//start load commands
	{
		ch = ' ';
		counter = 0;

		if (tmp != ' ')
		{
			if (tmp >= '0' && tmp <= '9')
			{
				counter = tmp - 48;
			}
			else
			{
				ch = tmp;
			}
			tmp = ' ';
		}
		
		while (ch == ' ' && ch != EOF)
		{
			ch = getchar();
			while (ch >= '0' && ch <= '9')
			{
				counter *= 10;
				counter += ch - 48;
				ch = getchar();
			}
		}
		if (ch != '\n' && ch != EOF)
		{
			if (counter > 0)
			{
				for (int i = 0; i < counter; i++)
				{
					//moves++;
					if (!Edek->move(ch)) // Edek die
					{
						printf_s("Zegnaj, okrutny swiecie!\n");
						return 0;
					}
				}
			}
			else
			{
				//moves++;
				if (!Edek->move(ch)) // Edek die
				{
					printf_s("Zegnaj, okrutny swiecie!\n");
					return 0;
				}
			}
		}

	}
	return 0;
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
	
	if (area != NULL)
	{
		return area[x][y];
	}
	else
	{
		return areaBig[x / MAX][x%MAX][y];
	}
}

void Map::printEdekPosition()
{
	printf("%d %d \n", Edek->getX(), Edek->getY());
}

void Map::paint(int x, int y, char c)
{
	if (area != NULL)
	{
		area[x][y] = c;
	}
	else
	{
		areaBig[x / MAX][x%MAX][y] = c;
	}
}
