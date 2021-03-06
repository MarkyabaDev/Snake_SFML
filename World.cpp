//
// Created by Markus Baars on 22.04.2022.
//

#include "World.h"

World::World(sf::Vector2u l_windSize, Textbox *l_textbox)
{
    m_blockSize = 16;
    m_textbox = l_textbox;

    m_windowSize = l_windSize;
    RespawnApple();
    m_appleShape.setFillColor(sf::Color::Red);
    m_appleShape.setRadius(m_blockSize * 0.5f);

    for (int i = 0; i < 4; i++)
    {
        m_bounds[i].setFillColor(sf::Color(150, 0, 0));
        if (!((i + 1) % 2))
        {
            m_bounds[i].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
        }
        else
        {
            m_bounds[i].setSize(sf::Vector2f(m_blockSize, m_windowSize.y));
        }

        if (i < 2)
        {
            // SFML has the origin on the top left corner by default.
            m_bounds[i].setPosition(0, 0);
        }
        else
        {
            // Set the origin to the bottom right corner.
            m_bounds[i].setOrigin(m_bounds[i].getSize());
            m_bounds[i].setPosition(sf::Vector2f(m_windowSize));
        }
    }
}

void World::RespawnApple()
{
    int maxX = (m_windowSize.x / m_blockSize) - 2;
    int maxY = (m_windowSize.y / m_blockSize) - 2;

    m_item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
    m_appleShape.setPosition(m_item.x * m_blockSize, m_item.y * m_blockSize);
}

void World::Update(Snake &l_player)
{
    if (l_player.GetPosition() == m_item)
    {
        l_player.Extend();
        l_player.IncreaseScore();

        AddMessageToTextBox("Player ate an apple.");
        AddMessageToTextBox("Score: " + std::to_string(l_player.GetScore()));
        AddMessageToTextBox("Snake length: " + std::to_string(l_player.GetSnakeLength()));

        RespawnApple();
    }

    int gridSizeX = m_windowSize.x / m_blockSize;
    int gridSizeY = m_windowSize.y / m_blockSize;

    if (l_player.GetPosition().x <= 0
        || l_player.GetPosition().y <= 0
        || l_player.GetPosition().x >= gridSizeX - 1
        || l_player.GetPosition().y >= gridSizeY - 1)
    {
        l_player.Lose();
        AddMessageToTextBox("Player ran into wall and lost.");
    }
}

void World::Render(sf::RenderWindow &l_window)
{
    for (int i = 0; i < 4; ++i)
    {
        l_window.draw(m_bounds[i]);
    }
    l_window.draw(m_appleShape);
}

int World::GetBlockSize()
{
    return m_blockSize;
}

void World::AddMessageToTextBox(std::string l_message)
{
    if (m_textbox != nullptr)
    {
        m_textbox->Add(l_message);
    }
}

World::~World() = default;