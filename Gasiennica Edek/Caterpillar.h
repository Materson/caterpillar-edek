#pragma once
#include<iostream>
class Map;
class Caterpillar
{
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
	segment *curr;

public:
	Caterpillar();
	Caterpillar(int x, int w, int h, Map *m);
	~Caterpillar();

	void addSegment(segment *head);
	int move(char x);
	int getX();
	int getY();

};

