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
	curr = segments;
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
			pos.y--;
			mushroom(p);
			if (p = 'K')
			{
				spike();
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
			if (p = 'K')
			{
				spike();
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
			if (p = 'K')
			{
				spike();
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
			if (p = 'K')
			{
				spike();
			}
			curr = curr->next;
			colors(p);
			
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

void Caterpillar::spike()
{
	segment *tmp = curr->next;
	curr->next = curr->next->next;
	delete(tmp);
	segmentQ--;
}