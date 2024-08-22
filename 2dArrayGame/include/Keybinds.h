#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#pragma once

using namespace sf;

struct Keybinds
{
	Keyboard::Key MoveLeft = Keyboard::A;
	Keyboard::Key MoveRight = Keyboard::D;
	Keyboard::Key MoveUp = Keyboard::W;
	Keyboard::Key MoveDown = Keyboard::S;
	Keyboard::Key MoveLeftArrow = Keyboard::Left;
	Keyboard::Key MoveRightArrow = Keyboard::Right;
	Keyboard::Key MoveUpArrow = Keyboard::Up;
	Keyboard::Key MoveDownArrow = Keyboard::Down;
	Keyboard::Key PressEnter = Keyboard::Enter;
};

