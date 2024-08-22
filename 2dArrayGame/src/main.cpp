#include <SFML/Graphics.hpp>
#include "../include/LevelSettings.h"
#include "../include/Player.h"
#include "../include/Blocks.h"
#include "../include/Levels.h"
#include "../include/Collision.h"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(680, 800), "2DArrayGame");
    window.setVerticalSyncEnabled(true);

    Levels level;

    Blocks blocks;
    blocks.InitializeBlocks(level);

    LevelSettings levelSettings;
    levelSettings.InitializeLevel(level);

    Player player;
    player.InitializePlayer();
    player.InitializeLine();

    Collision collision(player, levelSettings, blocks, level);


    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear(Color{ 61,118,173 });

        blocks.DrawBlocks(window);
        levelSettings.DrawLevel(window);
        collision.UpdateCollision();
        player.DrawLine(window);
        player.DrawPlayer(window);
        window.display();
    }

    return 0;
}