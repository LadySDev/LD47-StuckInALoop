#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:
	Scene();

	virtual void processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow& window);
};