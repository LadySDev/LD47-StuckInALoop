#pragma once
#include <SFML/Graphics.hpp>
#include "resource/Resource.h"
#include "scene/title/SceneTitle.h"
class SceneTitle;
#include "scene/game/SceneGame.h"
class SceneGame;
#include "scene/levelChoice/SceneChoice.h"
class SceneChoice;

class Game
{
public:
	Game();

	void processEvent(sf::Event event);
	void update(float deltaTime);
	void render();

	sf::Vector2i getSize();
	Resource* getResource();

	void quit();
	void launchScene(std::string from, std::string to, int level);
private:
	sf::RenderWindow m_window;
	Resource* m_resource;
	sf::Clock m_clock;
	
	SceneTitle* m_sceneTitle;
	SceneGame* m_sceneGame;
	SceneChoice* m_sceneChoice;
};