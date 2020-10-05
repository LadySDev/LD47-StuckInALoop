#include "UIGame.h"

UIGame::UIGame(SceneGame* sceneGame)
{
	m_sceneGame = sceneGame;	

	m_shapeLevel.setSize(sf::Vector2f(32*19, 50));
	m_shapeLevel.setPosition(sf::Vector2f(m_sceneGame->getSize().x /2 - m_shapeLevel.getSize().x /2, 10));

	m_textLevel.setFont(*m_sceneGame->getResource()->getFont());
	m_textLevel.setCharacterSize(40);
	m_textLevel.setFillColor(sf::Color::Black);
	m_textLevel.setString("LEVEL " + std::to_string(m_sceneGame->getLevel()));
	m_textLevel.setPosition(sf::Vector2f(m_sceneGame->getSize().x / 2 - m_textLevel.getGlobalBounds().width / 2, 15));

	m_shapeStep.setSize(sf::Vector2f(316, 50));
	m_shapeStep.setPosition(sf::Vector2f(336 + (32 * 19) + 10, 100 + 32 * 6));

	m_textStep.setFont(*m_sceneGame->getResource()->getFont());
	m_textStep.setCharacterSize(40);
	m_textStep.setFillColor(sf::Color::Black);
	m_textStep.setString("STEP " + std::to_string(m_sceneGame->getStep()));
	m_textStep.setPosition(sf::Vector2f(m_shapeStep.getPosition().x + m_shapeStep.getSize().x / 2 - m_textStep.getGlobalBounds().width / 2, m_shapeStep.getPosition().y + 5));

	m_shapeTimerTitle.setSize(sf::Vector2f(316, 50));
	m_shapeTimerTitle.setPosition(sf::Vector2f(10, 100 + 32 * 6));

	m_textTimerTitle.setFont(*m_sceneGame->getResource()->getFont());
	m_textTimerTitle.setCharacterSize(40);
	m_textTimerTitle.setFillColor(sf::Color::Black);
	m_textTimerTitle.setString("COUNTDOWN");
	m_textTimerTitle.setPosition(sf::Vector2f(m_shapeTimerTitle.getPosition().x + m_shapeTimerTitle.getSize().x / 2 - m_textTimerTitle.getGlobalBounds().width / 2, m_shapeTimerTitle.getPosition().y + 5));

	int triggers = m_sceneGame->getTrigger();
	int diameter = 32;
	sf::Vector2f center = sf::Vector2f(m_shapeStep.getPosition().x + m_shapeStep.getGlobalBounds().width / 2, m_shapeStep.getPosition().y + m_shapeStep.getGlobalBounds().height + 10 + 2);
	sf::Vector2f pos = sf::Vector2f(center.x - (diameter * (triggers) / 2) - (10 * triggers / 2), center.y);
	for (int i = 0; i < triggers;i++) {
		sf::CircleShape circle;
		circle.setRadius(16);
		circle.setFillColor(sf::Color::Red);
		circle.setOutlineColor(sf::Color::White);
		circle.setOutlineThickness(2);
		circle.setPosition(pos.x + (circle.getGlobalBounds().width + 10) * i, pos.y);

		m_shapeTriggers.push_back(circle);
	}

	float timer = m_sceneGame->getTimer();
	int min = timer / 60;
	int sec = timer - (min * 60);
	m_textTimer.setFont(*m_sceneGame->getResource()->getFont());
	m_textTimer.setCharacterSize(40);
	m_textTimer.setFillColor(sf::Color::White);
	m_textTimer.setString(std::to_string(min) + ":" + std::to_string(sec));
	m_textTimer.setPosition(sf::Vector2f(m_shapeTimerTitle.getPosition().x + m_shapeTimerTitle.getSize().x / 2 - m_textTimer.getGlobalBounds().width / 2, m_shapeTimerTitle.getPosition().y + m_shapeTimerTitle.getSize().y + 5));
}

bool UIGame::processEvent(sf::Event event)
{
	return false;
}

void UIGame::update(float deltaTime)
{
	float timer = m_sceneGame->getTimer();
	int min = timer / 60;
	int sec = timer - (min * 60);
	m_textTimer.setString(std::to_string(min) + ":" + std::to_string(sec));
	m_textTimer.setPosition(sf::Vector2f(m_shapeTimerTitle.getPosition().x + m_shapeTimerTitle.getSize().x / 2 - m_textTimer.getGlobalBounds().width / 2, m_shapeTimerTitle.getPosition().y + m_shapeTimerTitle.getSize().y + 5));

	if (m_textStep.getString() != "STEP " + std::to_string(m_sceneGame->getStep())) {
		m_textStep.setString("STEP " + std::to_string(m_sceneGame->getStep()));
		m_textStep.setPosition(sf::Vector2f(m_shapeStep.getPosition().x + m_shapeStep.getSize().x / 2 - m_textStep.getGlobalBounds().width / 2, m_shapeStep.getPosition().y + 5));
	
		int triggers = m_sceneGame->getTrigger();
		int diameter = 32;
		sf::Vector2f center = sf::Vector2f(m_shapeStep.getPosition().x + m_shapeStep.getGlobalBounds().width / 2, m_shapeStep.getPosition().y + m_shapeStep.getGlobalBounds().height + 10 + 2);
		sf::Vector2f pos = sf::Vector2f(center.x - (diameter * (triggers) / 2) - (10 * triggers / 2), center.y);

		m_shapeTriggers = std::vector<sf::CircleShape>();
		for (int i = 0; i < triggers; i++) {
			sf::CircleShape circle;
			circle.setRadius(16);
			circle.setFillColor(sf::Color::Red);
			circle.setOutlineColor(sf::Color::White);
			circle.setOutlineThickness(2);
			circle.setPosition(pos.x + (circle.getGlobalBounds().width + 10) * i, pos.y);

			m_shapeTriggers.push_back(circle);
		}
	}
}

void UIGame::render(sf::RenderWindow* window)
{
	window->draw(m_shapeLevel);
	window->draw(m_textLevel);
	window->draw(m_shapeStep);
	window->draw(m_textStep);
	window->draw(m_shapeTimerTitle);
	window->draw(m_textTimerTitle);
	for (int i = 0; i < m_shapeTriggers.size();i++) {
		window->draw(m_shapeTriggers[i]);
	}
	window->draw(m_textTimer);
}

void UIGame::validateTrigger(int number)
{
	m_shapeTriggers[number].setFillColor(sf::Color::Green);
}
