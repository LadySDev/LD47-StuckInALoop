#include "SceneChoice.h"

SceneChoice::SceneChoice(Game* game)
{
	m_game = game;
	m_shapeBackGround = m_game->getResource()->getRectangleShape("choiceBg");

	m_uichoice = new UIChoice(this);
}

void SceneChoice::processEvent(sf::Event event)
{
	m_uichoice->processEvent(event);
}

void SceneChoice::update(float deltaTime)
{
	m_uichoice->update(deltaTime);
}

void SceneChoice::render(sf::RenderWindow* window)
{
	window->draw(m_shapeBackGround);
	m_uichoice->render(window);
}

Resource* SceneChoice::getResource()
{
	return m_game->getResource();
}

sf::Vector2i SceneChoice::getSize()
{
	return m_game->getSize();
}

void SceneChoice::launchScene(std::string from, std::string to, int level)
{
	m_game->launchScene(from, to, level);
}
