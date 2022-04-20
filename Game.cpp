//
// Created by Markus Baars on 20.04.2022.
//

#include "Game.h"

Game::Game(float l_frameTime) : m_window("Snake", sf::Vector2u(2560, 1440))
{
    m_frameTime = 1.0f / l_frameTime;
    std::cout << m_frameTime << std::endl;
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

void Game::RestartClock()
{
    m_elapsed = m_clock.restart();
}

sf::Time Game::GetElapsedTime()
{
    return m_elapsed;
}
