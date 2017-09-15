#pragma once
class Map
{
public:
	Map();
	Map(int x, int y);
	~Map();

	void show();
private:
	int x, y;
	char *area;

};

