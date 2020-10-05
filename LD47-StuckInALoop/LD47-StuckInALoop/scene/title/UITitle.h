#pragma once
#include "../../ui/UI.h"
#include "SceneTitle.h"
class SceneTitle;


class UITitle: public UI
{
public:
	UITitle(SceneTitle* sceneTitle);
	virtual bool processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow* window);
private:
	SceneTitle* m_sceneTitle;
	Button m_buttonNewGame;
	Button m_buttonLevels;
	Button m_buttonQuit;
	Button* m_currentButton;
};
