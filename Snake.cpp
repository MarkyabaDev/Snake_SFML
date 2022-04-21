//
// Created by Markus Baars on 21.04.2022.
//

#include "Snake.h"

Snake::Snake(int l_blockSize)
{
    m_size = l_blockSize;
    m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
    Reset();
}

Snake::~Snake() {}

void Snake::Reset()
{
    m_snakeBody.clear();

    m_snakeBody.push_back(SnakeSegment(5, 7));
    m_snakeBody.push_back(SnakeSegment(5, 6));
    m_snakeBody.push_back(SnakeSegment(5, 5));

    SetDirection(Direction::NONE); // Start off still
    m_speed = 15;
    m_speed = 3;
    m_speed = 0;
    m_lost = false;
}

void Snake::SetDirection(Direction dir) { m_dir = dir; }
Direction Snake::GetDirection() { return m_dir; }
int Snake::GetSpeed() { return m_speed; }
int Snake::GetLives() { return m_lives; }
int Snake::GetScore() { return m_score; }
void Snake::IncreaseScore() { m_score += 10; }
bool Snake::HasLost() { return m_lost; }
void Snake::Lose() { m_lost = true; }
void Snake::ToggleLost() { m_lost = !m_lost; }

sf::Vector2i Snake::GetPosition()
{
    return (!m_snakeBody.empty() ? m_snakeBody.front().Position : sf::Vector2i(1, 1));
}

void Snake::Extend()
{
    if (m_snakeBody.empty()) { return; }
    SnakeSegment &tailHead = m_snakeBody[m_snakeBody.size() - 1];

    if (m_snakeBody.size() > 1)
    {
        SnakeSegment &tailBone = m_snakeBody[m_snakeBody.size() - 2];
        if (tailHead.Position.x == tailBone.Position.x)
        {
            if (tailHead.Position.y > tailBone.Position.y)
            {
                m_snakeBody.push_back(SnakeSegment(tailHead.Position.x, tailBone.Position.y + 1));
            }
            else
            {
                m_snakeBody.push_back(SnakeSegment(tailHead.Position.x, tailBone.Position.y - 1));
            }
        }
        else if (tailHead.Position.y == tailBone.Position.y)
        {
            if (tailHead.Position.x > tailBone.Position.x)
            {
                m_snakeBody.push_back(SnakeSegment(tailHead.Position.x + 1, tailBone.Position.y));
            }
            else
            {
                m_snakeBody.push_back(SnakeSegment(tailHead.Position.x - 1, tailBone.Position.y));
            }
        }
    }
    else
    {
        switch (m_dir)
        {
            case Direction::UP:
                m_snakeBody.push_back(SnakeSegment(tailHead.Position.x, tailHead.Position.y + 1));
                break;
            case Direction::DOWN:
                m_snakeBody.push_back(SnakeSegment(tailHead.Position.x, tailHead.Position.y - 1));
                break;
            case Direction::LEFT:
                m_snakeBody.push_back(SnakeSegment(tailHead.Position.x + 1, tailHead.Position.y));
                break;
            case Direction::RIGHT:
                m_snakeBody.push_back(SnakeSegment(tailHead.Position.x - 1, tailHead.Position.y + 1));
                break;
        }
    }
}

void Snake::Tick()
{
    if (m_snakeBody.empty() || m_dir == Direction::NONE) { return; }
    Move();
    CheckCollision();
}

void Snake::Move()
{
    for (int i = m_snakeBody.size() - 1; i > 0; i--)
    {
        m_snakeBody[i].Position = m_snakeBody[i - 1].Position;
    }

    switch (m_dir)
    {
        case Direction::LEFT:
            --m_snakeBody[0].Position.x;
            break;
        case Direction::RIGHT:
            ++m_snakeBody[0].Position.x;
            break;
        case Direction::UP:
            --m_snakeBody[0].Position.y;
            break;
        case Direction::DOWN:
            ++m_snakeBody[0].Position.y;
            break;
    }
}

void Snake::CheckCollision()
{
    if (m_snakeBody.size() < 5) { return; }
    SnakeSegment &head = m_snakeBody.front();
    for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
    {
        if (itr->Position == head.Position)
        {
            int segments = m_snakeBody.end() - itr;
            Cut(segments);
            break;
        }
    }
}

void Snake::Cut(int l_segments)
{
    for (int i = 0; i < l_segments; ++i)
    {
        m_snakeBody.pop_back();
    }
    --m_lives;
    if (!m_lives)
    {
        Lose();
    }
}

void Snake::Render(sf::RenderWindow &l_window)
{
    if (m_snakeBody.empty()) { return; }

    auto head = m_snakeBody.begin();
    m_bodyRect.setFillColor(sf::Color::Yellow);
    m_bodyRect.setPosition(head->Position.x * m_size, head->Position.y * m_size);
    l_window.draw(m_bodyRect);

    m_bodyRect.setFillColor(sf::Color::Green);
    for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
    {
        m_bodyRect.setPosition(itr->Position.x * m_size, itr->Position.y * m_size);
        l_window.draw(m_bodyRect);
    }
}

