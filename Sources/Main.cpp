#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
//#include "defines.h"


using namespace sf;
using namespace std;

const int SIZE = 20;
const int WIDTH = 500;
const int HEIGHT = 500;
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


static void MOVING()
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
        s[0].y += 1;
    }

    if (DIRECTION == 3)
    {
        s[0].x -= 1;
    }

   if (s[0].x == f.x && s[0].y == f.y)
    {
        NUMBER++;
        f.x = rand() % SIZE;
        f.y = rand() % SIZE;
    }
   //GYVATEI ISEJUS IS KRASTU 
   if (s[0].x < 0) s[0].x = 25;     
   
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

    f.x = rand() % SIZE;
    f.y = rand() % SIZE;




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


        for (int i = 0; i < NUMBER; i++)
        {
            box.setPosition(s[i].x * SIZE, s[i].y * SIZE);
            app.draw(box);
        }
        apple.setPosition(f.x * SIZE, f.y * SIZE);
        app.draw(apple);
       
        app.display();
     }
    }
