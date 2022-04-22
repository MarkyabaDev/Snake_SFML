//
// Created by Markus Baars on 20.04.2022.
//

#include "Game.h"

Game::Game(float l_frameTime) : m_window("Snake", sf::Vector2u(800, 600)), m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600))
{
    m_frameTime = 1.0f / l_frameTime;
}

Game::~Game() {}

void Game::HandleInput() {}

void Game::Update()
{
    m_window.Update();
}

void Game::Render()
{
    m_window.BeginDraw();
    // m_window.Draw();
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
