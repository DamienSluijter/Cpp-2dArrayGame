#include <SFML/Graphics.hpp>
#include "../include/Blocks.h"
#include "../include/Levels.h"
#include <iostream>

void Blocks::InitializeBlocks(Levels& levels)
{
	Rectangles.clear();
	x = 40;
	y = 40;
	Column = levels.LevelColumn;
	Row = levels.LevelRow;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (levels.Level[levels.Count][i][j] == 1)
			{
				RectangleShape Rectangle;
				Rectangle.setFillColor(Color{ 75, 75, 75 });
				Rectangle.setOutlineThickness(1);
				Rectangle.setOutlineColor(Color{ 20, 20, 20 });
				Rectangle.setSize(Vector2f(40, 40));
				Rectangle.setPosition(j * x, i * y);
				Rectangles.push_back(Rectangle);
			}
		}
	}
	InitRectanglesHit();
	cout << "Rectangles: " << Rectangles.size() << endl;
}

void Blocks::InitRectanglesHit()
{
	RectanglesHitCount = 0;
	RectanglesHit.clear();
	RectanglesHit.resize(Rectangles.size(), false);
}

bool Blocks::AllRectanglesHit() const
{
	return RectanglesHitCount == Rectangles.size();
}

void Blocks::MarkRectangleHit(int Index)
{
	RectanglesHit[Index] = true;
}

bool Blocks::IsRectangleHit(int Index) const
{
	return RectanglesHit[Index];
}

void Blocks::IncrementRectanglesHit()
{
	RectanglesHitCount++;
}

void Blocks::DrawBlocks(RenderWindow& window)
{
	for (auto& rectangle : Rectangles)
		window.draw(rectangle);
}