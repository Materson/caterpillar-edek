#include "Caterpillar.h"
#include"Map.h"

Caterpillar::Caterpillar()
{
}

Caterpillar::Caterpillar(int x, int w, int h, Map *m)
	:segmentQ(x), map(m)
{
	pos.x = 0;
	pos.y = 0;
	segments = new segment;
	segments->next = segments;
	for (int i = 1; i < x; i++)
	{
		addSegment(segments);
	}
	curr = segments->next;
}


Caterpillar::~Caterpillar()
{
}

void Caterpillar::addSegment(segment *head)
{
	segment *n = new segment;
	n->content = ' ';
	n->next = head->next;
	head->next = n;
}

int Caterpillar::move(char x)
{
	char p;
	switch (x)
	{
	case 'g':
		p = map->checkPlace(pos.x, pos.y - 1);
		if (p != 'T')
		{
			if (p >= 'a' && p <= 'z')
			{
				
			}
			pos.y--;
		}
		break;
	case 'p':
		p = map->checkPlace(pos.x + 1, pos.y);
		if (p != 'T')
		{
			pos.x++;
		}
		break;
	case 'd':
		p = map->checkPlace(pos.x, pos.y + 1);
		if (p != 'T')
		{
			pos.y++;
		}
		break;
	case 'l':
		p = map->checkPlace(pos.x - 1, pos.y);
		if (p != 'T')
		{
			pos.x--;
		}
		break;
	}
	return 0;
}

int Caterpillar::getX()
{
	return pos.x;
}

int Caterpillar::getY()
{
	return pos.y;
}
