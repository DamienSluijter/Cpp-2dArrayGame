#pragma once
#include <SFML/Graphics.hpp>
#include "Levels.h"

using namespace sf;
using namespace std;

class LevelSettings
{
public:
	void InitializeLevel(Levels& levels);
	void DrawLevel(RenderWindow& window);

	vector<Sprite> StoneSprites;

private:
	float x = 0, y = 0;
	int Column = 0, Row = 0;

	Texture TextureStone;
	Sprite SpriteStone;
};

