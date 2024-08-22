#pragma once
#include <SFML/Graphics.hpp>
#include "Keybinds.h"

using namespace sf;
using namespace std;

class Player
{
public:
	void InitializePlayer();
	void InitializeLine();
	void HandleInput();
	void DrawPlayer(RenderWindow& window);
	void DrawLine(RenderWindow& window);

	Sprite PlayerSprite;
	Vector2f Velocity;
	Vector2f Position;
	Clock DeltaClock;
	
	VertexArray line;

	bool LeftKeyPressed = false;
	bool RightKeyPressed = false;
	bool UpKeyPressed = false;
	bool DownKeyPressed = false;
	bool KeyPressed = true;
	
	int RandNumPlayer;

private:

	const float Acceleration = 70.0f;
	
	Texture PlayerTexture;
	Keybinds keybinds;
};

