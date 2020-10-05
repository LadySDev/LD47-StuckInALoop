#include "Resource.h"
#include <iostream>

Resource::Resource()
{
    //TEXTURES
    sf::Texture m_tilesheet;
    if (!m_tilesheet.loadFromFile("resource/tilesheet.png")) {
        exit(0);
    }
    m_textures.insert(std::pair<std::string, sf::Texture>("tilesheet", m_tilesheet));

    sf::Texture m_playersheet;
    if (!m_playersheet.loadFromFile("resource/playersheet.png")) {
        exit(0);
    }
    m_textures.insert(std::pair<std::string, sf::Texture>("playersheet", m_playersheet));

    //FONT
    if (!m_font.loadFromFile("resource/Eternity Time.ttf")) {
        exit(0);
    }

    //TEXTURE RECTS
    for (int i = 0; i < m_tilesheet.getSize().x / 32; i++) {
        m_textureRects.insert(std::pair<std::string, sf::IntRect>("tile" + i, sf::IntRect(i * 32, 0, 32, 32)));
    }

    for (int i = 0; i < 4; i++) {
        m_textureRects.insert(std::pair<std::string, sf::IntRect>("playerMoveDown" + i, sf::IntRect(i * 32, 0 * 32, 32, 32)));
        m_textureRects.insert(std::pair<std::string, sf::IntRect>("playerMoveLeft" + i, sf::IntRect(i * 32, 1 * 32, 32, 32)));
        m_textureRects.insert(std::pair<std::string, sf::IntRect>("playerMoveRight" + i, sf::IntRect(i * 32, 2 * 32, 32, 32)));
        m_textureRects.insert(std::pair<std::string, sf::IntRect>("playerMoveUp" + i, sf::IntRect(i * 32, 3 * 32, 32, 32)));
        m_textureRects.insert(std::pair<std::string, sf::IntRect>("playerFall" + i, sf::IntRect(i * 32, 4 * 32, 32, 32)));
    }

    //RECTANGLE SHAPES
    sf::RectangleShape titleBg;
    titleBg.setSize(sf::Vector2f(1280, 720));
    titleBg.setPosition(0, 0);
    titleBg.setFillColor(sf::Color(128,128,128,255));
    m_rectangleShapes.insert(std::pair<std::string, sf::RectangleShape>("titleBg", titleBg));

    sf::RectangleShape choiceBg;
    choiceBg.setSize(sf::Vector2f(1280, 720));
    choiceBg.setPosition(0, 0);
    choiceBg.setFillColor(sf::Color(128, 128, 128, 255));
    m_rectangleShapes.insert(std::pair<std::string, sf::RectangleShape>("choiceBg", choiceBg));

    sf::RectangleShape gameBg;
    gameBg.setSize(sf::Vector2f(1280, 720));
    gameBg.setPosition(0, 0);
    gameBg.setFillColor(sf::Color(128, 128, 128, 255));
    m_rectangleShapes.insert(std::pair<std::string, sf::RectangleShape>("gameBg", gameBg));

    sf::RectangleShape gameMenuBg;
    gameMenuBg.setSize(sf::Vector2f(1280, 720));
    gameMenuBg.setPosition(0, 0);
    gameMenuBg.setFillColor(sf::Color(128, 128, 128, 255));
    m_rectangleShapes.insert(std::pair<std::string, sf::RectangleShape>("gameMenuBg", gameMenuBg));

    //BUTTON
    m_button.setFont(m_font);
}

sf::Font* Resource::getFont()
{
	return &m_font;
}

sf::Texture* Resource::getTexture(std::string name)
{
	return &m_textures[name];
}

sf::IntRect Resource::getIntRect(std::string name)
{
	return m_textureRects[name];
}

sf::RectangleShape Resource::getRectangleShape(std::string name)
{
    return m_rectangleShapes[name];
}

Button Resource::getButton()
{
    return m_button;
}
