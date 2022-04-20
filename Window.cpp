//
// Created by Markus Baars on 20.04.2022.
//

#include "Window.h"

Window::Window()
{
    Setup("Window", sf::Vector2u(680, 420));
}

Window::Window(const std::string &l_windowTitle, const sf::Vector2u &l_windowSize)
{
    Setup(l_windowTitle, l_windowSize);
}

Window::~Window()
{
    Destroy();
}

void Window::Setup(const std::string &l_windowTitle, const sf::Vector2u &l_windowSize)
{
    m_windowSize = l_windowSize;
    m_windowTitle = l_windowTitle;
    m_isDone = false;
    m_isFullScreen = false;
    Create();
}

void Window::Create()
{
    sf::Uint32 style = (m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_windowSize.x, m_windowSize.y}, m_windowTitle, style);
}

void Window::Destroy()
{
    m_window.close();
}

void Window::Update()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if ((event.type == sf::Event::Closed) ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            m_isDone = true;
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
        {
            ToggleFullscreen();
        }
    }
}

void Window::ToggleFullscreen()
{
    m_isFullScreen = !m_isFullScreen;
    Destroy();
    Create();
}

void Window::BeginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::Draw(sf::Drawable &l_drawable) {
    m_window.draw(l_drawable);
}

void Window::EndDraw() {
    m_window.display();
}

bool Window::IsDone() const {
    return m_isDone;
}

bool Window::IsFullscreen() const {
    return m_isFullScreen;
}

sf::Vector2u Window::GetWindowSize() const {
    return m_windowSize;
}