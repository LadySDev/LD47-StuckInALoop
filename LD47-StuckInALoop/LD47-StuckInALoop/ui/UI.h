#pragma once
#include <SFML/Graphics.hpp>
#include "../../ui/Button.h"

class UI
{
public:
	UI();
	virtual bool processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow& window);
};