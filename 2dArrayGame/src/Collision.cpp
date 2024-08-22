#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Collision.h"
#include "../include/Player.h"
#include "../include/LevelSettings.h"
#include "../include/Blocks.h"
#include "../include/Levels.h" 
#include "../include/Keybinds.h"

Collision::Collision(Player& pl, LevelSettings& ls, Blocks& bl, Levels& lv) : player(pl), levelsettings(ls), blocks(bl), levels(lv) {}

void Collision::CheckCollisionStone()
{
    FloatRect playerBounds = player.PlayerSprite.getGlobalBounds();

    for (auto& sprite : levelsettings.StoneSprites)
    {
        FloatRect stoneBounds = sprite.getGlobalBounds();
        if (playerBounds.intersects(stoneBounds))
        {
            // calculate overlap between player and stone sprites
            float overlapLeft = playerBounds.left + playerBounds.width - stoneBounds.left;
            float overlapRight = stoneBounds.left + stoneBounds.width - playerBounds.left;
            float overlapTop = playerBounds.top + playerBounds.height - stoneBounds.top;
            float overlapBottom = stoneBounds.top + stoneBounds.height - playerBounds.top;

            // find the smallest overlap
            float minOverlap = std::min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

            // adjust player position to resolve collision
            if (minOverlap == overlapLeft)
            {
                player.Position.x -= overlapLeft;
                player.Velocity.x = 0;
                if (!blocks.AllRectanglesHit())
                    player.KeyPressed = true;
                    player.RightKeyPressed = false;
            }
            else if (minOverlap == overlapRight)
            {
                player.Position.x += overlapRight;
                player.Velocity.x = 0;
                if (!blocks.AllRectanglesHit())
                    player.KeyPressed = true;
                    player.LeftKeyPressed = false;
            }
            else if (minOverlap == overlapTop)
            {
                player.Position.y -= overlapTop;
                player.Velocity.y = 0;
                if (!blocks.AllRectanglesHit())
                    player.KeyPressed = true;
                    player.DownKeyPressed = false;
            }
            else if (minOverlap == overlapBottom)
            {
                player.Position.y += overlapBottom;
                player.Velocity.y = 0;
                if (!blocks.AllRectanglesHit())
                    player.KeyPressed = true;
                    player.UpKeyPressed = false;
            }
        }
    }
}
void Collision::CheckCollisionBlocks()
{
    FloatRect playerBounds = player.PlayerSprite.getGlobalBounds();

    for (int i = 0; i < blocks.Rectangles.size(); i++)
    {
        FloatRect RectangleBounds = blocks.Rectangles[i].getGlobalBounds();

        //Create a smaller FloatRect based on RectangleBounds and place it in the middle and shrink it and then check collisions on that FloatRect
        FloatRect smallRect(RectangleBounds.left + RectangleBounds.width / 4,
            RectangleBounds.top + RectangleBounds.height / 4,
            RectangleBounds.width / 2,
            RectangleBounds.height / 2);

        if (playerBounds.intersects(smallRect))
        {
            if (!blocks.IsRectangleHit(i))
            {
                 if (player.RandNumPlayer == 1)
                     blocks.Rectangles[i].setFillColor(Color{ 125, 70, 40 });
                 if (player.RandNumPlayer == 2)
                     blocks.Rectangles[i].setFillColor(Color{ 83, 105, 13 });
                 if (player.RandNumPlayer == 3)
                     blocks.Rectangles[i].setFillColor(Color{ 130, 130, 130 });
              
                 blocks.MarkRectangleHit(i);
                 blocks.IncrementRectanglesHit();
            }
        }
    }
   
    if (blocks.AllRectanglesHit())
    {
        if (!event_Completed)
        {
            cout << "All rectangles have been hit!" << endl;
            cout << "Press enter to continue!" << endl;
            player.KeyPressed = false;
            event_Completed = true;
        }

        if (Keyboard::isKeyPressed(keybinds.PressEnter))
        {
            player.Velocity.x = 0;
            player.Velocity.y = 0;
            player.KeyPressed = true;
            player.InitializePlayer();
            levels.OverwriteLevel();

            if (levels.Count == 4)
                player.Position = Vector2f(200, 200);
            if (levels.Count == 5)
                player.Position = Vector2f(240, 80);
            if (levels.Count == 6)
                player.Position = Vector2f(40, 160);
            if (levels.Count == 7)
                player.Position = Vector2f(40, 120);
            player.PlayerSprite.setPosition(player.Position);

            blocks.InitializeBlocks(levels);
            levelsettings.InitializeLevel(levels);
            player.line.clear();
            event_Completed = false;
        }
    }
}

 void Collision::UpdateCollision()
{
    float deltatime = player.DeltaClock.restart().asSeconds();

    player.HandleInput();

    player.Position += player.Velocity * deltatime;

    player.PlayerSprite.setPosition(player.Position);

    CheckCollisionStone();
    CheckCollisionBlocks();
}