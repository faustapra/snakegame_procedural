
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Defines.h"
#include "Objects.h"

using namespace sf;
using namespace std;

int game = 0;
int NUMBER = 3;
int DIRECTION = 1;


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
        NUMBER+=2;              //GYVATE PAILGEJA PALIETUS OBUOLI
        f.x = rand() % SIZE;
        f.y = rand() % SIZE;
    }

   //GYVATEI ISEJUS IS KRASTU 
   if (s[0].x > SKAICIUS) s[0].x = 0; if (s[0].x < 0) s[0].x = SKAICIUS;
   if (s[0].y > SKAICIUS) s[0].y = 0; if (s[0].y < 0) s[0].y = SKAICIUS;
  
   //JEI GYVATE SAVE PALIECIA
   for (int i = 1; i < NUMBER; i++)
   {
       if (s[0].x == s[i].x && s[0].y == s[i].y) { game = 1; }
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
       
        //JEI GYVATE SAVE PALIECIA
        if (game == 1) {
            app.close();
            system("pause");
            
        }


        app.display();

        
     }
    }
