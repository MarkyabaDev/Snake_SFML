//
// Created by Markus Baars on 20.04.2022.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "Window.h"
#include "World.h"
#include "Snake.h"
#include "Textbox.h"

class Game
{
public:
    Game(float l_frameTime = 60.0f);
    ~Game();

    void HandleInput();
    void Update();
    void Render();

    Window *GetWindow();

    sf::Time GetElapsedTimeFixed();
    sf::Time GetElapsedTime();

    void RestartClockFixed();
    void RestartClock();


private:
    Window m_window;
    Textbox m_textbox;

    sf::Clock m_clock;
    sf::Time m_elapsedFixed;
    sf::Time m_elapsed;

    float m_frameTime;

    World m_world;
    Snake m_snake;
};


#endif //SNAKE_GAME_H
