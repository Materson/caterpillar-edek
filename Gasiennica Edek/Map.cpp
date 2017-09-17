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
	int c = wid*hei;
	anchor = new field;
	anchor->x = 0;
	anchor->y = 0;
	anchor->right = NULL;
	anchor->down = NULL;
	anchor->content = '.';

	char ch = ' ';
	int k = 0, x = 0, y = 0;
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
				if(ch != '.')
					addField(x, y, ch);
				x++;
				if (x == w)
				{
					y++;
					x = 0;
				}
			}
			i--;
		}
		else
		{
			if (ch != '.')
				addField(x, y, ch);
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
}

void Map::show()
{
	field *tmp = anchor;
	field *level = anchor;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (tmp->x == j && tmp->y == i)
			{
				printf_s("%c", tmp->content);
				if (tmp->right != NULL)
					tmp = tmp->right;
			}
			else
			{
				printf_s(".");
			}
		}
		printf_s("\n");
		if (level->down != NULL)
		{
			tmp = level->down;
			level = level->down;
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
				if (Edek->move(ch)) //if TRUE Edek die
				{
					printf_s("Zegnaj, okrutny swiecie!\n");
					ch = '\n';
				}
			}
		}
		else
		{
			if (Edek->move(ch)) //if TRUE Edek die
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
	field *find = new field;
	find->x = x;
	find->y = y;
	findField(find);
	char c = find->content;
	delete(find);
	return c;
}

void Map::printEdekPosition()
{
	printf_s("%d %d \n", Edek->getX(), Edek->getY());
}

void Map::paint(int x, int y, char c)
{
	//area[w*y + x] = c;
}

void Map::addField(int x, int y, char con)
{
	field *newf = new field;
	newf->content = con;
	newf->x = x;
	newf->y = y;
	newf->right = NULL;
	newf->down = NULL;

	field *tmp = anchor;
	while ( tmp->down != NULL && tmp->down->y <= y)
	{
		tmp = tmp->down;
	}

	if (tmp->y == y)
	{
		while (tmp->right != NULL && tmp->right->x < x)
		{
			tmp = tmp->right;
		}
		if (tmp->right != NULL)
		{
			newf->right = tmp->right;
		}
		tmp->right = newf;
	}
	else
	{
		if (tmp->down != NULL)
		{
			newf->down = tmp->down;
		}
		tmp->down = newf;
	}
}

int Map::findField(field * find)
{
	find->content = '.';
	field *tmp = anchor;
	while (tmp->down != NULL && tmp->down->y <= find->y)
	{
		tmp = tmp->down;
	}

	if (tmp->y == find->y)
	{
		while (tmp->right != NULL && tmp->right->x <= find->x)
		{
			tmp = tmp->right;
		}
		if (tmp->x == find->x)
		{
			find->content = tmp->content;
			return 1;
		}
	}
	return 0;
}
