#pragma once
#include"Caterpillar.h"
class Caterpillar;
class Map
{
private:
	int w, h;
	Caterpillar *Edek;

	char **area;
	char ***areaBig;

public:
	Map();
	Map(int x, int y, int z);
	~Map();

	void show();
	int round();
	int getW();
	int getH();
	char checkPlace(int x, int y);
	void printEdekPosition();
	void paint(int x, int y, char c);
};

