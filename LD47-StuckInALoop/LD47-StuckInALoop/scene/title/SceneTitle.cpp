#include "SceneTitle.h"

SceneTitle::SceneTitle(Game* game)
{
	m_game = game;
	m_backGround = m_game->getResource()->getRectangleShape("titleBg");
	m_uiTitle = new UITitle(this);
}

void SceneTitle::processEvent(sf::Event event)
{
	bool eventFounded = m_uiTitle->processEvent(event);
}

void SceneTitle::update(float deltaTime)
{
	m_uiTitle->update(deltaTime);
}

void SceneTitle::render(sf::RenderWindow* window)
{
	window->draw(m_backGround);

	m_uiTitle->render(window);
}

Resource* SceneTitle::getResource()
{
	return m_game->getResource();
}

sf::Vector2i SceneTitle::getSize()
{
	return m_game->getSize();
}

void SceneTitle::quit()
{
	m_game->quit();
}

void SceneTitle::launchScene(std::string from, std::string to, int level)
{
	m_game->launchScene(from, to, level);
}
