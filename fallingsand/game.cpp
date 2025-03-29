#include <iostream>
#include <SFML/Graphics.hpp>
#include "fs.h"
using namespace std;

void game(int **xy)
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Falling Sand");

    sf::RectangleShape sand(sf::Vector2f(cell, cell));
    sf::RectangleShape water(sf::Vector2f(cell, cell));
    sf::RectangleShape wall(sf::Vector2f(cell, cell));

    sand.setFillColor(sf::Color::Yellow);
    water.setFillColor(sf::Color::Blue);
    wall.setFillColor(sf::Color::Magenta);

    int item;

    sf::Clock clock;
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::Q)
                {
                    cout << "Sand\n";
                    item = Sand.num;
                }
                if (event.key.code == sf::Keyboard::W)
                {
                    cout << "Water\n";
                    item = Water.num;
                }
                if (event.key.code == sf::Keyboard::E)
                {
                    cout << "Wall\n";
                    item = Wall.num;
                }
                if (event.key.code == sf::Keyboard::R)
                {
                    cout << "Erase\n";
                    item = 0;
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int posx = mousePos.x / cell;
                int posy = mousePos.y / cell;
                if (posx >= 0 && posx <= gridx && posy >= 0 && posy <= gridy)
                {
                    if (item == Wall.num)
                    {
                        int t = 3; // Wall size, 3x3
                        for (int i = -t; i <= t; i++)
                        {
                            for (int j = -t; j <= t; j++)
                            {
                                int wallX = posx + i;
                                int wallY = posy + j;
                                xy[wallX][wallY] = item;
                            }
                        }
                    }
                    else
                    {
                        xy[posx][posy] = item;
                    }
                }
            }
        }

        syncMaterials(xy);
        window.clear();
        for (int i = 0; i < gridx; i++)
        {
            for (int j = 0; j < gridy; j++)
            {
                if (xy[i][j] == Sand.num)
                {
                    sand.setPosition(i * cell, j * cell);
                    window.draw(sand);
                }
                else if (xy[i][j] == Water.num)
                {
                    water.setPosition(i * cell, j * cell);
                    window.draw(water);
                }
                else if (xy[i][j] == Wall.num)
                {
                    wall.setPosition(i * cell, j * cell);
                    window.draw(wall);
                }
            }
        }
        window.display();
    }
}
