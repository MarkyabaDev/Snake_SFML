//
// Created by Markus Baars on 22.04.2022.
//

#ifndef SNAKE_WORLD_H
#define SNAKE_WORLD_H

#include "Snake.h"
#include "SFML/Graphics.hpp"
#include "Textbox.h"

class World
{
public:
    World(sf::Vector2u l_windSize, Textbox *l_textbox = nullptr);
    ~World();

    int GetBlockSize();

    void RespawnApple();

    void Update(Snake &l_player);
    void Render(sf::RenderWindow &l_window);

private:
    void AddMessageToTextBox(std::string l_message);
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int m_blockSize;

    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];

    Textbox *m_textbox;
};


#endif //SNAKE_WORLD_H
