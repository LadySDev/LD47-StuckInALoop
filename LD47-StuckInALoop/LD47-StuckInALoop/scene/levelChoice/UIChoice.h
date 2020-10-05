#pragma once
#include "../../ui/UI.h"
#include "SceneChoice.h"
class SceneChoice;

class UIChoice
{
public:
	UIChoice(SceneChoice* sceneChoice);
	virtual bool processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow* window);
private:
	SceneChoice* m_sceneChoice;
	sf::RectangleShape m_shapeTitle;
	sf::Text m_textTitle;

	int m_rows;
	int m_cols;

	std::vector<std::vector<Button>> m_buttonLevels;
	Button m_buttonBack;
	Button* m_currentButton;
};