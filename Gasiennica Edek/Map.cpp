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

	area = new char*[w];
	for (int i = 0; i < w; i++)
	{
		area[i] = new char[h];
		for (int j = 0; j < h; j++)
		{
			area[i][j] = '.';
		}
	}

	char ch = ' ';
	int counter = 0, x = 0, y = 0;
	for (int i = 0; i < w*h; i++)
	{
		ch = ' ';
		counter = 0;
		while (ch == ' ' || ch == '\n')
		{
			scanf_s("%c", &ch);
			while (ch >= '0' && ch <= '9')
			{
				counter *= 10;
				counter += ch - 48;
				scanf_s("%c", &ch);
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
					area[x][y] = ch;
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
				area[x][y] = ch;
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
	for (int i = 0; i < w; i++)
	{
		delete[](area[i]);
	}
	delete[](area);
	delete(Edek);
}

void Map::show()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf_s("%c", area[j][i]);
		}
		printf_s("\n");
	}
}
int endin = 0;
int Map::round()
{
	char ch = ' ';
	int scanResult = 0;
	scanResult = scanf_s("%c", &ch);
	if (w == 100 && h == 100 && Edek->segmentQ == 1)
	{
		printf_s("1", ch);
	}
	if (scanResult == EOF)
	{
		printf("114");
		endin = 114;
		return 0;
	}

	if (ch == ' ')
	{
		while (ch != '\n' && !(ch >= '0' && ch <= '9' || ch >= 'a'&& ch <= 'z'))
		{
			scanResult = scanf_s("%c ,2", &ch);
			if (w == 100 && h == 100 && Edek->segmentQ == 1)
			{
				printf_s("%c", ch);
			}
			if (scanResult == EOF)
			{
				printf("125");
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
	while (ch != '\n' && ch != EOF)	//start load commands
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
		
		while (ch == ' ')
		{
			scanResult = scanf_s("%c", &ch);
			if (w == 100 && h == 100 && Edek->segmentQ == 1)
			{
				scanResult = scanf_s("%c", &ch);
				printf_s("%c ,3", ch);
			}
			if (scanResult == EOF)
			{
				printf("163");
				return 0;
			}
			while (ch >= '0' && ch <= '9')
			{
				counter *= 10;
				counter += ch - 48;
				scanf_s("%c", &ch);
			}
		}

		if (counter > 0)
		{
			for (int i = 0; i < counter; i++)
			{
				if (!Edek->move(ch)) // Edek die
				{
					printf_s("Zegnaj, okrutny swiecie!\n");
					ch = '\n';
				}
			}
		}
		else
		{
			if (!Edek->move(ch)) // Edek die
			{
				printf_s("Zegnaj, okrutny swiecie!\n");
				ch = '\n';
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
	
	return area[x][y];
}

void Map::printEdekPosition()
{
	printf_s("%d %d \n", Edek->getX(), Edek->getY());
}

void Map::paint(int x, int y, char c)
{
	area[x][y] = c;
}

//void Map::addField(int x, int y, char con)
//{
//	if (x == 0 && y == 0)
//	{
//		anchor->content = con;
//	}
//	else
//	{
//		field *newf = new field;
//		newf->content = con;
//		newf->x = x;
//		newf->y = y;
//		newf->right = NULL;
//		newf->down = NULL;
//
//		field *tmp = anchor;
//		field *levelup=NULL;
//		while ( tmp->down != NULL && tmp->down->y <= y)
//		{
//			levelup = tmp;
//			tmp = tmp->down;
//		}
//
//		if (tmp->y == y)
//		{
//			while (tmp->right != NULL && tmp->right->x < x)
//			{
//				tmp = tmp->right;
//			}
//
//			if (tmp->x > x)
//			{
//				newf->right = tmp;
//				if (levelup->down->down != NULL)
//					newf->down = levelup->down->down;
//				levelup->down = newf;
//			}
//			else
//			{
//				if (tmp->right != NULL)
//				{
//					newf->right = tmp->right;
//				}
//				tmp->right = newf;
//			}
//		}
//		else
//		{
//			if (tmp->down != NULL)
//			{
//				newf->down = tmp->down;
//			}
//			tmp->down = newf;
//		}
//	}
//}

//void Map::findField(field * find)
//{
//	field *tmp = anchor;
//	field *levelup = NULL;
//	while (tmp->down != NULL && tmp->down->y <= find->y)
//	{
//		levelup = tmp;
//		tmp = tmp->down;
//	}
//
//	if (tmp->y == find->y)
//	{
//		while (tmp->right != NULL && tmp->right->x <= find->x)
//		{
//			tmp = tmp->right;
//		}
//
//		if (tmp->x == find->x)
//		{
//			if (tmp->content == '.' && find->content != '.')
//			{
//				tmp->content = find->content;	//paint
//			}
//			else
//			{
//				find->content = tmp->content;	//checkPlace
//				if (tmp->content == 'G')			//delete mushroom
//					tmp->content = '.';
//			}
//		}
//		else
//		{
//			if (find->content != '.')	//add pool
//			{
//				field *pool = new field;
//				pool->x = find->x;
//				pool->y = find->y;
//				pool->content = find->content;
//				pool->right = NULL;
//				pool->down = NULL;
//
//				if (tmp->x > find->x)
//				{
//					pool->right = tmp;
//					if(levelup->down->down != NULL)
//						pool->down = levelup->down->down;
//					levelup->down = pool;
//				}
//				else
//				{
//					if (tmp->right != NULL)
//					{
//						pool->right = tmp->right;
//					}
//					tmp->right = pool;
//				}
//			}
//		}
//	}
//	else
//	{
//		if (find->content != '.')
//		{
//			field *pool = new field;
//			pool->x = find->x;
//			pool->y = find->y;
//			pool->content = find->content;
//			pool->right = NULL;
//			pool->down = NULL;
//
//			if (tmp->down != NULL)
//			{
//				pool->down = tmp->down;
//			}
//			tmp->down = pool;
//		}
//	}
//}
