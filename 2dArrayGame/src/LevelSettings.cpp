#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../include/LevelSettings.h"
#include "../include/Levels.h"

 void LevelSettings::InitializeLevel(Levels& levels)
{
	 StoneSprites.clear();
	 x = 40;
	 y = 40;
	 Column = levels.LevelColumn;
	 Row = levels.LevelRow;

	TextureStone.loadFromFile("images/StoneGrey.png");
	
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			if (levels.Level[levels.Count][i][j] == 0)
			{
				SpriteStone.setTexture(TextureStone);
				SpriteStone.setPosition(j * x, i * y);
				StoneSprites.push_back(SpriteStone);
			}
		}
	}
	cout << "Walls: " << StoneSprites.size() << endl;
}

 void LevelSettings::DrawLevel(RenderWindow& window)
 {
	 for (auto& sprite : StoneSprites)
		 window.draw(sprite);
 }
