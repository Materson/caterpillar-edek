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
private:
	int w, h;
	char *area;
	Caterpillar *Edek;

};

