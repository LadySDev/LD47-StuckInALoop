#pragma once
#include <SFML/Graphics.hpp>
#include "../ui/Button.h"

class Resource
{
public:
	Resource();
	sf::Font* getFont();
	sf::Texture* getTexture(std::string name);
	sf::IntRect getIntRect(std::string name);
	sf::RectangleShape getRectangleShape(std::string name);
	Button getButton();
private:
	sf::Font m_font;
	std::map<std::string, sf::Texture> m_textures;
	std::map<std::string, sf::IntRect> m_textureRects;
	std::map<std::string, sf::RectangleShape> m_rectangleShapes;
	Button m_button;
};