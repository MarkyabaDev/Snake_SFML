#ifndef SNAKE_WINDOW_H
#define SNAKE_WINDOW_H

#include <iostream>
#include "SFML/Graphics.hpp"

class Window
{
public:
    Window();
    Window(const std::string &l_windowTitle, const sf::Vector2u &l_windowSize);
    ~Window();

    void BeginDraw();
    void EndDraw();

    void Update();
    void ToggleFullscreen();

    bool IsDone() const;
    bool IsFullscreen() const;
    sf::Vector2u GetWindowSize() const;

    void Draw(sf::Drawable &l_drawable);

private:
    bool m_isDone;
    bool m_isFullScreen;

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;

    void Setup(const std::string &l_windowTitle, const sf::Vector2u &l_windowSize);
    void Create();
    void Destroy();
};


#endif //SNAKE_WINDOW_H
