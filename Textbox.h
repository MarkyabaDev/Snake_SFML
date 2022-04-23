//
// Created by Markus Baars on 23.04.2022.
//

#ifndef SNAKE_TEXTBOX_H
#define SNAKE_TEXTBOX_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using MessageContainer = std::vector<std::string>;

class Textbox
{
public:
    Textbox();
    Textbox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
    ~Textbox();

    void Setup(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
    void Add(std::string l_message);
    void Clear();

    void Render(sf::RenderWindow &l_window);

private:
    MessageContainer m_messages;
    int m_numVisible;
    sf::RectangleShape m_backdrop;
    sf::Font m_font;
    sf::Text m_content;
};


#endif //SNAKE_TEXTBOX_H
