#pragma once
#include "../../Game.h"
class Game;
#include "UIGame.h"
class UIGame;
#include "MapGame.h"
class MapGame;
#include "UIGameMenu.h"
class UIGameMenu;

class SceneGame
{
public:
	SceneGame(Game* game, int level);

	virtual void processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow* window);

	Resource* getResource();
	sf::Vector2i getSize();
	
	int getLevel();
	int getStep();
	int getTrigger();
	float getTimer();

	std::vector<std::vector<int>> getData(int level);
	sf::Vector2i getSpawn(int level);
	std::vector<std::vector<sf::Vector2i>> getSteps(int level);
	std::vector<std::pair<int, int>> getZones(int level);

	void setMenuDisplay(bool display, std::string state);
	void quit();
	void launchScene(std::string from, std::string to, int level);
private:
	Game* m_game;
	sf::RectangleShape m_shapeBackGround;

	UIGame* m_uigame;
	MapGame* m_mapgame;
	UIGameMenu* m_uigamemenu;
	bool m_isMenuDisplay;

	sf::Vector2f m_startPosition;

	//LEVEL1//
	std::vector<std::vector<int>> dataLvl1;
	sf::Vector2i spawnLvl1;
	std::vector<std::vector<sf::Vector2i>> stepsLvl1;
	std::vector<std::pair<int, int>> zonesLvl1;
	float timerLvl1;

	int m_level;
	int m_step;
	int m_trigger;
	std::vector<bool> m_triggerValidate;
	float m_timer;

	std::vector<sf::IntRect> m_animMoveDown;
	std::vector<sf::IntRect> m_animMoveLeft;
	std::vector<sf::IntRect> m_animMoveRight;
	std::vector<sf::IntRect> m_animMoveUp;
	std::vector<sf::IntRect> m_animFall;
	std::vector<sf::IntRect> m_currentAnim;
	int m_currentAnimFrame;
	bool m_isAnimationPlayed;
	float m_animTimer;

	sf::Sprite m_playerSprite;

	bool m_moveUp;
	bool m_moveDown;
	bool m_moveLeft;
	bool m_moveRight;
	double m_playerSpeed;
	bool m_isPlayerFreezed;

	bool m_gameOver;
	bool m_win;
	float m_stateTimer;
};