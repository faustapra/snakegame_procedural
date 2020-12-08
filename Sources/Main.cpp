#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

const int SIZE = 30;
int WIDTH = SIZE * SIZE;
int HEIGHT = SIZE * SIZE;




int main()
{


    RenderWindow app(VideoMode(WIDTH, HEIGHT), "SnakeGame", Style::Titlebar);
    app.setFramerateLimit(60);

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
        app.clear();


        app.display();
    }
    }
