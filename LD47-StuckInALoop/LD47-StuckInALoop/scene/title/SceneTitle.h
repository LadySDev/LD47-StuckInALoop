#pragma once
#include "../Scene.h"
#include "../../Game.h"
class Game;
#include "UITitle.h"
class UITitle;

class SceneTitle : public Scene
{
public:
	SceneTitle(Game* game);

	virtual void processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow* window);

	Resource* getResource();
	sf::Vector2i getSize();
	void quit();
	void launchScene(std::string from, std::string to, int level);
private:
	Game* m_game;
	sf::RectangleShape m_backGround;
	UITitle* m_uiTitle;
};