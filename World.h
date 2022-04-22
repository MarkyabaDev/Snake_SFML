//
// Created by Markus Baars on 22.04.2022.
//

#ifndef SNAKE_WORLD_H
#define SNAKE_WORLD_H

#include "Snake.h"
#include "SFML/Graphics.hpp"

class World
{
public:
    World(sf::Vector2u l_windSize);
    ~World();

    int GetBlockSize();

    void RespawnApple();

    void Update(Snake &l_player);
    void Render(sf::RenderWindow &l_window);

private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int m_blockSize;

    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];
};


#endif //SNAKE_WORLD_H
