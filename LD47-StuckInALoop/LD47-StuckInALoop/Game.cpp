#include "Game.h"

Game::Game()
{
	m_window.create(sf::VideoMode(1280, 720), "LD47 Stuck in a loop");
	m_window.setFramerateLimit(30);

	m_resource = new Resource();
	//launchScene("game", 1);
	//m_sceneGame = new SceneGame(this, 1);
	m_sceneTitle = new SceneTitle(this);

	while (m_window.isOpen())
	{
		float deltaTime = m_clock.restart().asMilliseconds();

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();

			processEvent(event);
		}

		update(deltaTime);
		m_window.clear();

		render();
		m_window.display();
	}
}

void Game::processEvent(sf::Event event)
{
	if (m_sceneTitle != NULL) {
		m_sceneTitle->processEvent(event);
	}
	else if (m_sceneGame != NULL) {
		m_sceneGame->processEvent(event);
	}
}

void Game::update(float deltaTime)
{
	if (m_sceneTitle != NULL) {
		m_sceneTitle->update(deltaTime);
	}
	else if (m_sceneGame != NULL) {
		m_sceneGame->update(deltaTime);
	}
}

void Game::render()
{
	if (m_sceneTitle != NULL) {
		m_sceneTitle->render(&m_window);
	}
	else if (m_sceneGame != NULL) {
		m_sceneGame->render(&m_window);
	}
}

sf::Vector2i Game::getSize()
{
	return sf::Vector2i(m_window.getSize());
}

Resource* Game::getResource()
{
	return m_resource;
}

void Game::quit()
{
	m_window.close();
}

void Game::launchScene(std::string from, std::string to, int level)
{
	if (from == "title") {
		m_sceneTitle = NULL;
	}
	else if (from == "game") {
		m_sceneGame = NULL;
	}

	if (to == "title") {
		m_sceneTitle = new SceneTitle(this);
	}
	else if (to == "game") {
		m_sceneGame = new SceneGame(this, level);
	}
}

