#pragma once
#include "Player.h"
#include "LevelSettings.h"
#include "Blocks.h"
#include "Levels.h"
#include "Keybinds.h"

class Collision
{
public:
	Collision(Player& pl, LevelSettings& ls, Blocks& bl, Levels& lv);
	void CheckCollisionStone();
	void CheckCollisionBlocks();
	void UpdateCollision();

private:
	Player& player;
	LevelSettings& levelsettings;
	Blocks& blocks;
	Levels& levels;

	Keybinds keybinds;
	bool event_Completed = false;
};