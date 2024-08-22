#pragma once
#include <SFML/Graphics.hpp>
#include "Levels.h"

using namespace sf;
using namespace std;

class Blocks
{
public:
	void InitializeBlocks(Levels& levels);

	void InitRectanglesHit();
	bool AllRectanglesHit() const;
	void MarkRectangleHit(int Index);
	bool IsRectangleHit(int Index) const;
	void IncrementRectanglesHit();

	void DrawBlocks(RenderWindow& window);

	vector<RectangleShape> Rectangles;
	int RectanglesHitCount = 0;

private:
	float x = 0, y = 0;
	int Column = 0, Row = 0;

	vector<bool> RectanglesHit;
};

