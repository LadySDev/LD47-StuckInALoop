#include "Button.h"
#include <iostream>

Button::Button()
{
	m_image.setPosition(sf::Vector2f(0, 0));
	m_image.setSize(sf::Vector2f(150, 40));

	m_text.setPosition(sf::Vector2f(0, 0));
	m_text.setString("Button");
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(20);

	m_isOver = false;
	m_isPressed = false;
}

void Button::setPosition(sf::Vector2f position)
{
	float x = m_image.getPosition().x - position.x;
	float y = m_image.getPosition().y - position.y;

	float distanceX = abs(x);
	float distanceY = abs(y);

	int orientationX;
	float textPosX;
	if (x == 0)
	{
		orientationX = 0;
		textPosX = m_text.getPosition().x;
	}
	else
	{
		orientationX = x > 0 ? -1 : 1;
		if (orientationX == -1)
		{
			textPosX = m_text.getPosition().x - distanceX;
		}
		else
		{
			textPosX = m_text.getPosition().x + distanceX;
		}
	}

	int orientationY;
	float textPosY;
	if (y == 0)
	{
		orientationY = 0;
		textPosY = m_text.getPosition().y;
	}
	else
	{
		orientationY = y > 0 ? -1 : 1;
		if (orientationX == -1)
		{
			textPosY = m_text.getPosition().y - distanceY;
		}
		else
		{
			textPosY = m_text.getPosition().y + distanceY;
		}
	}

	m_image.setPosition(position);
	m_text.setPosition(sf::Vector2f(textPosX, textPosY));
}

sf::Vector2f Button::getPosition()
{
	return m_image.getPosition();
}

void Button::setRectangleShape(sf::RectangleShape image)
{
	sf::Vector2f position = m_image.getPosition();
	sf::Vector2f origin = m_image.getOrigin();
	m_image = image;
	m_image.setPosition(position);
	m_image.setOrigin(origin);
}

void Button::setRectangleShapeColor(sf::Color color)
{
	m_image.setFillColor(color);
}

void Button::setFont(const sf::Font& font)
{
	m_text.setFont(font);
}

void Button::setText(std::string text)
{
	m_text.setString(text);
}

void Button::setTextPosition(sf::Vector2f position)
{
	m_text.setPosition(position);
}

void Button::setTextFillColor(sf::Color color)
{
	m_text.setFillColor(color);
}

void Button::setTextCharacterSize(int size)
{
	m_text.setCharacterSize(size);
}

sf::Vector2f Button::getSize()
{
	return m_image.getSize();
}

sf::Vector2f Button::getTextSize()
{
	return sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height);
}

int Button::getTextCharacterSize()
{
	return m_text.getCharacterSize();
}

std::string Button::getText()
{
	return m_text.getString();
}

void Button::draw(sf::RenderWindow* window)
{
	window->draw(m_image);

	window->draw(m_text);
}

bool Button::getIsOver()
{
	return m_isOver;
}

void Button::setIsOver(bool isOver)
{
	m_isOver = isOver;
}

bool Button::getIspressed()
{
	return m_isPressed;
}

void Button::setIsPressed(bool isPressed)
{
	m_isPressed = isPressed;
}
