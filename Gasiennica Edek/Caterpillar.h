#pragma once
#include<iostream>
class Map;
class Caterpillar
{
public:
	Caterpillar();
	Caterpillar(int x, int w, int h, Map *m);
	~Caterpillar();

	void addSegment(char content = ' ');
	int move(char x);
	int getX();
	int getY();

private:
	int segmentQ;
	Map *map;
	
	struct position
	{
		int x;
		int y;
	};

	position pos;

	struct segment
	{
		segment *next;
		char content;
	};

	segment *segments;
};

