#pragma once
#include "../../ui/UI.h"
#include "SceneGame.h"
class SceneGame;

class UIGame : public UI
{
public:
	UIGame(SceneGame* sceneGame);

	virtual bool processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow* window);

	void validateTrigger(int number);
private:
	SceneGame* m_sceneGame;
	sf::RectangleShape m_shapeLevel;
	sf::Text m_textLevel;
	sf::RectangleShape m_shapeStep;
	sf::Text m_textStep;
	std::vector<sf::CircleShape> m_shapeTriggers;
	sf::RectangleShape m_shapeTimerTitle;
	sf::Text m_textTimerTitle;
	sf::Text m_textTimer;
};
