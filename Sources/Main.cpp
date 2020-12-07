#include <SFML/Graphics.hpp>
#include <ctime>
#include "Defines.h"
#include "Objects.h"
#include "Utils.h"

using namespace sf;

static void UpdatePositions(Player &player, Plate plates[], float &dy)
{
    const float dx = 3.5f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.x -= dx;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.x += dx;

    if (player.x + PLAYER_WIDTH / 2 > WINDOW_WIDTH)
        player.x = -PLAYER_WIDTH / 2;

    if (player.x + PLAYER_WIDTH / 2 < 0)
        player.x = WINDOW_WIDTH - PLAYER_WIDTH / 2;

    dy += 0.2f;

    player.y += dy;

    if (player.y > WINDOW_HEIGHT)
        dy = JUMP_VELOCITY;

    if (player.y < MAX_PLAYER_Y)
    {
        player.y = MAX_PLAYER_Y;

        for (int i = 0; i < PLATES_AMOUNT; ++i)
        {
            plates[i].y -= dy;
        
            if (plates[i].y > WINDOW_HEIGHT)
            {
                plates[i].y = float(rand() % 10);
                plates[i].x = float(rand() % (WINDOW_WIDTH - PLATE_WIDTH));
            }
        }
    }

    for (int i = 0; i < PLATES_AMOUNT; ++i)
    {
        if (nmUtils::IsOnPlate(player, plates[i]) && dy > 0)
            dy = JUMP_VELOCITY;
    }
}

int main()
{
    srand((unsigned int)time(nullptr));
    RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Doodle jump");
    app.setFramerateLimit(60);

    Texture tBackground, tPlatform, tPlayer1, tPlayer2;
    tBackground.loadFromFile("Resources/background.png");
    tPlatform.loadFromFile("Resources/platform.png");
    tPlayer1.loadFromFile("Resources/doodle1.png");
    tPlayer2.loadFromFile("Resources/doodle2.png");

    Sprite sprBackground(tBackground);
    Sprite sprPlatform(tPlatform);
    Sprite sprPlayer(tPlayer1);

    Plate plates[PLATES_AMOUNT];
    for (int i = 0; i < PLATES_AMOUNT; ++i)
    {
        plates[i].x = float(rand() % (WINDOW_WIDTH - PLATE_WIDTH));
        plates[i].y = (float)WINDOW_HEIGHT / PLATES_AMOUNT * i;
    }

    Player player(WINDOW_WIDTH / 2, 100);

    float dy = 0;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
            sprPlayer.setTexture(tPlayer1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
            sprPlayer.setTexture(tPlayer2);

        ::UpdatePositions(player, plates, dy);

        app.draw(sprBackground);

        for (int i = 0; i < PLATES_AMOUNT; ++i)
        {
            sprPlatform.setPosition(plates[i].x, plates[i].y);
            app.draw(sprPlatform);
        }

        sprPlayer.setPosition(player.x, player.y);
        app.draw(sprPlayer);

        app.display();
    }

    return 0;
}