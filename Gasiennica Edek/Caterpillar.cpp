#include "Caterpillar.h"
#include"Map.h"

Caterpillar::Caterpillar()
{
}

Caterpillar::Caterpillar(int x, int w, int h, Map *m)
	:segmentQ(x), map(m)
{
	segments = new segment;
	segments->next = NULL;
	pos.x = 0;
	pos.y = 0;
	for (int i = 0; i < x; i++)
	{
		addSegment();
	}
}


Caterpillar::~Caterpillar()
{
}

void Caterpillar::addSegment(char content)
{
	segment *n = new segment;
	n->content = content;
	n->next = NULL;
	segment * tmp;
	tmp = this->segments;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = n;
}

int Caterpillar::move(char x)
{
	switch (x)
	{
	case 'g':
		if (map->checkPlace(pos.x, pos.y - 1) != 'T')
		{
			pos.y--;
		}
		break;
	case 'p':
		if (map->checkPlace(pos.x + 1, pos.y) != 'T')
		{
			pos.x++;
		}
		break;
	case 'd':
		if (map->checkPlace(pos.x, pos.y + 1) != 'T')
		{
			pos.y++;
		}
		break;
	case 'l':
		if (map->checkPlace(pos.x - 1, pos.y) != 'T')
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
