#include <iostream>
#include "../include/Player.h"
#include "../include/keybinds.h"

using namespace sf;
using namespace std;

void Player::InitializePlayer()
{
    std::srand(std::time(nullptr));

    RandNumPlayer = std::rand() % 3 + 1;

    if (RandNumPlayer == 1)
    {
        PlayerTexture.loadFromFile("images/Player.png");
        PlayerSprite.setTexture(PlayerTexture);
        Position = Vector2f(40, 40);
        Velocity = Vector2f(0, 0);
        PlayerSprite.setPosition(Position);
    }
    if (RandNumPlayer == 2)
    {
        PlayerTexture.loadFromFile("images/Player2.png");
        PlayerSprite.setTexture(PlayerTexture);
        Position = Vector2f(40, 40);
        Velocity = Vector2f(0, 0);
        PlayerSprite.setPosition(Position);
    }
    if (RandNumPlayer == 3)
    {
        PlayerTexture.loadFromFile("images/Player3.png");
        PlayerSprite.setTexture(PlayerTexture);
        Position = Vector2f(40, 40);
        Velocity = Vector2f(0, 0);
        PlayerSprite.setPosition(Position);
    }
}

void Player::InitializeLine()
{
    line.setPrimitiveType(LineStrip);
}

void Player::HandleInput()
{
    if (KeyPressed == true)
    {
        if (Keyboard::isKeyPressed(keybinds.MoveLeft) || Keyboard::isKeyPressed(keybinds.MoveLeftArrow))
        {
            Velocity.x -= 80;
            Velocity.y = 0;
            LeftKeyPressed = true;
            KeyPressed = false;
        }
    
        else if (Keyboard::isKeyPressed(keybinds.MoveRight) || Keyboard::isKeyPressed(keybinds.MoveRightArrow))
        {
            Velocity.x = 80;
            Velocity.y = 0;
            RightKeyPressed = true;
            KeyPressed = false;
        }
    
        else if (Keyboard::isKeyPressed(keybinds.MoveUp) || Keyboard::isKeyPressed(keybinds.MoveUpArrow))
        {
            Velocity.y -= 80;
            Velocity.x = 0;
            UpKeyPressed = true;
            KeyPressed = false;
        }

        else if (Keyboard::isKeyPressed(keybinds.MoveDown) || Keyboard::isKeyPressed(keybinds.MoveDownArrow))
        {
            Velocity.y = 80;
            Velocity.x = 0;
            DownKeyPressed = true;
            KeyPressed = false;
        }
    }
    if (LeftKeyPressed)
        Velocity.x -= Acceleration;
    if (RightKeyPressed)
        Velocity.x += Acceleration;
    if (UpKeyPressed)
        Velocity.y -= Acceleration;
    if (DownKeyPressed)
        Velocity.y += Acceleration;
}


void Player::DrawPlayer(RenderWindow& window)
{
	window.draw(PlayerSprite);
}

void Player::DrawLine(RenderWindow& window)
{
    int PlayerPosX = Position.x + 20;
    int PlayerPosY = Position.y + 20;

    Vector2f PlayerPosition(PlayerPosX, PlayerPosY);

    line.append(PlayerPosition);

    if (line.getVertexCount() > 12)
    {
        // Create a new vertex array to hold the shifted vertices
        sf::VertexArray newLine(LineStrip);

        // Copy the vertices from the old array to the new one, shifted down by one position
        for (std::size_t i = 1; i < line.getVertexCount(); ++i)
        {
            newLine.append(line[i]);
        }

        line = std::move(newLine);
    }

    if (RandNumPlayer == 1)
    {
        for (int i = 0; i < line.getVertexCount(); ++i)
            line[i].color = Color{ 250, 139, 84 };
    }
    if (RandNumPlayer == 2)
    {
        for (int i = 0; i < line.getVertexCount(); ++i)
            line[i].color = Color{ 169, 214, 27 };
    }
    if (RandNumPlayer == 3)
    {
        for (int i = 0; i < line.getVertexCount(); ++i)
            line[i].color = Color{ 247, 247, 247 };
    }

    window.draw(line);
}