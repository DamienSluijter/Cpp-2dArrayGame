#include <iostream>
#include "../include/Levels.h"

void Levels::OverwriteLevel()
{
	if (Count < LevelsTotal && Count + 1 < Max_Levels)
	{
		for (int i = 0; i < LevelRow; i++)
		{
			for (int j = 0; j < LevelColumn; j++)
			{
				Level[Count][i][j] = Level[Count + 1][i][j];
			}
		}
		Count++;
	}
}