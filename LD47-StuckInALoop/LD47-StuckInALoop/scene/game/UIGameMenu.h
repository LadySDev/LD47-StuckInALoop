#pragma once
#include "../../ui/UI.h"
#include "SceneGame.h"
class SceneGame;

class UIGameMenu : public UI
{
public:
	UIGameMenu(SceneGame* sceneGame);

	virtual bool processEvent(sf::Event event);
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow* window);

	void setState(std::string state);

	void resetButtons();
private:
	SceneGame* m_sceneGame;
	sf::RectangleShape m_shapeBackground;
	sf::Text m_textState;
	Button m_buttonResume;
	Button m_buttonRestart;
	Button m_buttonTitle;
	Button m_buttonQuit;
	Button* m_currentButton;

	std::string m_state;
};