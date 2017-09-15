#include "Caterpillar.h"


Caterpillar::Caterpillar()
{
}

Caterpillar::Caterpillar(int x)
	:segmentQ(x)
{
	segments = new segment;
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
	segment * tmp;
	tmp = this->segments;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = n;
}
