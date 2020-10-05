#pragma once
#include "SceneGame.h"
class SceneGame;

class MapGame
{
public:
	MapGame(SceneGame* sceneGame);
	virtual bool processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow* window);

	void revealStep(int level, int step);

	std::vector<std::vector<int>>* getCurrentLevel();
	std::vector<sf::Sprite>* getMap();
private:
	SceneGame* m_sceneGame;

	std::vector<sf::Sprite> m_tiles;

	sf::Vector2f m_startPosition;

	std::vector<std::vector<int>> m_currentLevel;
	std::vector<sf::Sprite> m_sprites;
};