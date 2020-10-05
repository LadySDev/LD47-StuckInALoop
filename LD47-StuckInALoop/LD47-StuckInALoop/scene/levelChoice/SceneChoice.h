#pragma once
#include "../Scene.h"
#include "../../Game.h"
class Game;
#include "UIChoice.h"
class UIChoice;

class SceneChoice
{
public:
	SceneChoice(Game* game);

	virtual void processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow* window);

	Resource* getResource();
	sf::Vector2i getSize();

	void launchScene(std::string from, std::string to, int level);
private:
	Game* m_game;
	sf::RectangleShape m_shapeBackGround;
	UIChoice* m_uichoice;
};