//
// Created by Markus Baars on 21.04.2022.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "SFML/Graphics.hpp"

struct SnakeSegment
{
    SnakeSegment(int x, int y): Position(x, y) {}
    sf::Vector2i Position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction{ NONE, UP, DOWN, LEFT, RIGHT };

class Snake
{
public:
    Snake(int l_blockSize);
    ~Snake();

    // Helper methods
    void SetDirection(Direction dir);
    Direction GetDirection();
    int GetSpeed();
    sf::Vector2i GetPosition();
    int GetLives();
    int GetScore();
    void IncreaseScore();
    bool HasLost();

    void Lose();    // Handles losing.
    void ToggleLost();

    void Extend();  // Grows the snake after eating an apple
    void Reset();   // Reset to starting position

    void Move();    // Movement method
    void Tick();    // Update the snake.
    void Cut(int l_segments);   // Cut the snake.
    void Render(sf::RenderWindow &l_window);
private:
    void CheckCollision();  // Check for collision
    SnakeContainer m_snakeBody;
    int m_size;
    Direction m_dir;
    int m_speed;
    int m_score;
    int m_lives;
    bool m_lost;
    sf::RectangleShape m_bodyRect;
};


#endif //SNAKE_SNAKE_H
