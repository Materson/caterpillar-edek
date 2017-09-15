#pragma once
#include<iostream>
class Caterpillar
{
public:
	Caterpillar();
	Caterpillar(int x);
	~Caterpillar();

	void addSegment(char content = ' ');
private:
	int segmentQ;
	int pos;

	struct segment
	{
		segment *next = NULL;
		char content;
	};

	segment *segments;
};

