#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>


using namespace sf;
using namespace std;

int SIZE = 25;
int WIDTH = SIZE * SIZE;
int HEIGHT = SIZE * SIZE;
int NUMBER = 3;
int DIRECTION = 1;

struct SNAKE {
    int x;
    int y;
} s[100];



struct FRUIT {
    int x;
    int y;
} f;


void MOVING()
{

    for (int i = NUMBER; i > 0; i--)
    {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }
    if (DIRECTION == 0)
    {
        s[0].y -= 1;
    }

    if (DIRECTION == 1)
    {
        s[0].x += 1;
    }

    if (DIRECTION == 2)
    {
        s[0].y -= 1;
    }

    if (DIRECTION == 3)
    {
        s[0].x -= 1;
    }


}





int main()
{


    RenderWindow app(VideoMode(WIDTH, HEIGHT), "SnakeGame", Style::Titlebar);
    app.setFramerateLimit(60);

    RectangleShape box(Vector2f(SIZE, SIZE));
    box.setFillColor(Color::Red);

    RectangleShape apple(Vector2f(SIZE, SIZE));
    apple.setFillColor(Color::Green);
   


    Clock timer;


    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyReleased:
                if (event.key.code == Keyboard::Escape)
                    app.close();
                break;
            }
        }

        if (timer.getElapsedTime().asMilliseconds() > 200)
        {
            MOVING();
            timer.restart();
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) DIRECTION = 0;
        if (Keyboard::isKeyPressed(Keyboard::Right)) DIRECTION = 1;
        if (Keyboard::isKeyPressed(Keyboard::Down)) DIRECTION = 2;
        if (Keyboard::isKeyPressed(Keyboard::Left)) DIRECTION = 3;


        app.clear();





        app.display();
    }
    }
