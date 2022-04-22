//
// Created by Markus Baars on 20.04.2022.
//

#include "Game.h"

Game::Game(float l_frameTime) : m_window("Snake", sf::Vector2u(800, 600)), m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600))
{
    m_frameTime = 1.0f / l_frameTime;
}

Game::~Game() {}

void Game::HandleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_snake.GetPhysicalDirection() != Direction::DOWN)
    {
        m_snake.SetDirection(Direction::UP);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_snake.GetPhysicalDirection() != Direction::UP)
    {
        m_snake.SetDirection(Direction::DOWN);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_snake.GetPhysicalDirection() != Direction::LEFT)
    {
        m_snake.SetDirection(Direction::RIGHT);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_snake.GetPhysicalDirection() != Direction::RIGHT)
    {
        m_snake.SetDirection(Direction::LEFT);
    }
}

void Game::Update()
{
    m_window.Update();

    float timeStep =  1.0f / m_snake.GetSpeed();
    if (m_elapsedFixed.asSeconds() >= timeStep) {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsedFixed -= sf::seconds(timeStep);
        if (m_snake.HasLost()) {
            m_snake.Reset();
        }
    }
}

void Game::Render()
{
    m_window.BeginDraw();
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}

Window *Game::GetWindow()
{
    return &m_window;
}

void Game::RestartClockFixed()
{
    m_elapsedFixed += m_clock.restart();
}

void Game::RestartClock()
{
    m_elapsed = m_clock.restart();
}

sf::Time Game::GetElapsedTimeFixed()
{
    return m_elapsedFixed;
}

sf::Time Game::GetElapsedTime()
{
    return m_elapsed;
}
