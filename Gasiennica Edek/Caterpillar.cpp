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
	segments->next = NULL;
	for (int i = 0; i < x; i++)
	{
		addSegment();
	}
	curr = segments->next;
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
