#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
	Button();

	virtual void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();

	virtual void setRectangleShape(sf::RectangleShape image);
	void setRectangleShapeColor(sf::Color color);
	void setFont(const sf::Font& font);
	void setText(std::string text);
	void setTextPosition(sf::Vector2f position);
	void setTextFillColor(sf::Color color);
	void setTextCharacterSize(int size);

	sf::Vector2f getSize();
	sf::Vector2f getTextSize();
	int getTextCharacterSize();

	void draw(sf::RenderWindow* window);

	std::function<void()> onClick;

	std::function<void()> setOver;
	std::function<void()> setOut;
	std::function<void()> setPressed;
	std::function<void()> setReleased;

	bool getIsOver();
	void setIsOver(bool isOver);
	bool getIspressed();
	void setIsPressed(bool isPressed);
protected:
	sf::RectangleShape m_image;
	sf::Text m_text;

	bool m_isOver;
	bool m_isPressed;
};