#include "Caterpillar.h"
#include"Map.h"
#include<cstdlib>

Caterpillar::Caterpillar()
{
}

Caterpillar::Caterpillar(int x, int w, int h, Map *m)
	:map(m)
{
	pos.x = 0;
	pos.y = 0;
	this->z = x;
	segments = new segment;
	segments->next = segments;
	segmentQ = 1;
	for (int i = 1; i < x; i++)
	{
		addSegment(segments);
	}
	curr = segments;
}


Caterpillar::~Caterpillar()
{
	while (segmentQ != 0)
	{
		delSegment();
	}
}

void Caterpillar::addSegment(segment *head)
{
	segment *n = new segment;
	n->content = '.';
	n->next = head->next;
	head->next = n;
	segmentQ++;
}

//int tmp = 0;
int Caterpillar::move(char x)
{
	char p;
	switch (x)
	{
	case 'g':
		p = map->checkPlace(pos.x, pos.y - 1);
		if (p != 'T')
		{
			pos.y--;
			mushroom(p);
			if (p == 'K')
			{
				delSegment();
				if (segmentQ == 0)
				{
					pos.y++;
					return 0;
				}
			}
			curr = curr->next;
			colors(p);
		}
		break;
	case 'p':
		p = map->checkPlace(pos.x + 1, pos.y);
		if (p != 'T')
		{
			pos.x++;
			mushroom(p);
			if (p == 'K')
			{
				delSegment();
				if (segmentQ == 0)
				{
					pos.x--;
					return 0;
				}
			}
			curr = curr->next;
			colors(p);
		}
		break;
	case 'd':
		p = map->checkPlace(pos.x, pos.y + 1);
		if (p != 'T')
		{
			pos.y++;
			mushroom(p);
			if (p == 'K')
			{
				delSegment();
				if (segmentQ == 0)
				{
					pos.y--;
					return 0;
				}
			}
			curr = curr->next;
			colors(p);
		}
		break;
	case 'l':
		p = map->checkPlace(pos.x - 1, pos.y);
		if (p != 'T')
		{
			pos.x--;
			mushroom(p);
			if (p == 'K')
			{
				delSegment();
				if (segmentQ == 0)
				{
					pos.x++;
					return 0;
				}
			}
			curr = curr->next;
			colors(p);
			
		}
		break;
	}
	////if(!tmp)
	//	loop++;
	///*if (pos.x == 8 && pos.y == 29)
	//{*/
	//	tmp = 1;
	//	system("cls");
	//	printf_s("%d\n", loop);
	//	map->printEdekPosition();
	//	printSegments();
	//	printf_s("\n %c \n", x);
	//	map->show();
	//	system("pause");
	////}
	return 1;
}

int Caterpillar::getX()
{
	return pos.x;
}

int Caterpillar::getY()
{
	return pos.y;
}

void Caterpillar::colors(char p)
{
	if (p >= 'a' && p <= 'z')
	{
		curr->content = p;
	}

	if (p == '.' && curr->content >= 'a' && curr->content <= 'z')
	{
		map->paint(pos.x, pos.y, curr->content);
	}
}

void Caterpillar::mushroom(char p)
{
	if (p == 'G')
	{
		addSegment(curr);
		map->paint(pos.x, pos.y, '.');
	}
}

void Caterpillar::delSegment()
{
	segment *tmp = curr->next;
	curr->next = curr->next->next;
	delete(tmp);
	segmentQ--;
}

void Caterpillar::printSegments()
{
	segment *tmp = curr;
	for (int i = 0; i < segmentQ; i++)
	{
		printf_s("%c ", tmp->content);
		tmp = tmp->next;
	}
}
