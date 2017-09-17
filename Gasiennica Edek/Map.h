#pragma once
#include"Caterpillar.h"
class Caterpillar;
class Map
{
public:
	Map();
	Map(int x, int y, int z);
	~Map();

	void show();
	void round();
	int getW();
	int getH();
	char checkPlace(int x, int y);
	void printEdekPosition();
	void paint(int x, int y, char c);
	void addField(int x, int y, char con);
private:
	int w, h;
	Caterpillar *Edek;

	struct field
	{
		int x, y;
		char content;
		field *right;
		field *down;
	};
	field *anchor;

};

