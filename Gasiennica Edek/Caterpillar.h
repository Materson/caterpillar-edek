#pragma once
#include<iostream>
class Map;

class Caterpillar
{
private:
	Map *map;
	int segmentQ;
	
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
	Caterpillar(int x,  Map *m);
	~Caterpillar();

	void addSegment(segment *head);
	void delSegment();
	void printSegments();
	int move(char x);
	int getX();
	int getY();
	void colors(char p);
	void mushroom(char p);
	

};

