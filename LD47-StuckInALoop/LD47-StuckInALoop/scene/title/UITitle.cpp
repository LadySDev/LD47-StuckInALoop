#include "UITitle.h"
#include <iostream>

UITitle::UITitle(SceneTitle* sceneTitle)
{
	m_sceneTitle = sceneTitle;

  
	m_buttonNewGame = m_sceneTitle->getResource()->getButton();
	m_buttonNewGame.setText("NEW GAME");
	m_buttonNewGame.setTextPosition(sf::Vector2f(m_buttonNewGame.getPosition().x + m_buttonNewGame.getSize().x / 2 - m_buttonNewGame.getTextSize().x / 2, m_buttonNewGame.getPosition().y + m_buttonNewGame.getSize().y / 2 - m_buttonNewGame.getTextSize().y / 2));
	m_buttonNewGame.setPosition(sf::Vector2f(sf::Vector2i(m_sceneTitle->getSize().x / 2 - m_buttonNewGame.getSize().x / 2, m_sceneTitle->getSize().y - m_buttonNewGame.getSize().y * 3 - 30)));

	m_buttonLevels = m_sceneTitle->getResource()->getButton();
	m_buttonLevels.setText("LEVELS");
	m_buttonLevels.setTextPosition(sf::Vector2f(m_buttonLevels.getPosition().x + m_buttonLevels.getSize().x / 2 - m_buttonLevels.getTextSize().x / 2, m_buttonLevels.getPosition().y + m_buttonLevels.getSize().y / 2 - m_buttonLevels.getTextSize().y / 2));
	m_buttonLevels.setPosition(sf::Vector2f(sf::Vector2i(m_sceneTitle->getSize().x / 2 - m_buttonLevels.getSize().x / 2, m_sceneTitle->getSize().y - m_buttonLevels.getSize().y * 2 - 20)));

	m_buttonQuit = m_sceneTitle->getResource()->getButton();
	m_buttonQuit.setText("QUIT");
	m_buttonQuit.setTextPosition(sf::Vector2f(m_buttonQuit.getPosition().x + m_buttonQuit.getSize().x / 2 - m_buttonQuit.getTextSize().x / 2, m_buttonQuit.getPosition().y + m_buttonQuit.getSize().y / 2 - m_buttonQuit.getTextSize().y / 2));
	m_buttonQuit.setPosition(sf::Vector2f(sf::Vector2i(m_sceneTitle->getSize().x / 2 - m_buttonQuit.getSize().x / 2, m_sceneTitle->getSize().y - m_buttonQuit.getSize().y - 10)));

    for (int i = 0; i < 3;i++) {
        Button* button;
        if (i == 0) {
            button = &m_buttonNewGame;
        }
        else if (i == 1) {
            button = &m_buttonLevels;
        }
        else if (i == 2) {
            button = &m_buttonQuit;
        }
        button->setOver = [this, button] {
            if (button->getIsOver() == false)
            {
                button->setRectangleShapeColor(sf::Color::Red);
            }
            button->setIsOver(true);
        };
        button->setOut = [this, button] {
            if (button->getIsOver() == true)
            {
                button->setRectangleShapeColor(sf::Color::White);
            }
            button->setIsOver(false);
        };
        button->setPressed = [this, button] {
            if (button->getIspressed() == false)
            {
                button->setRectangleShapeColor(sf::Color::Green);
                button->setTextCharacterSize(button->getTextCharacterSize() - 2);
            }
            button->setIsOver(false);
            button->setIsPressed(true);
        };
        button->setReleased = [this, button] {
            button->setIsOver(true);

            button->setTextCharacterSize(button->getTextCharacterSize() + 2);

            button->setIsPressed(false);
        };
    }

    m_currentButton = &m_buttonNewGame;
    m_buttonNewGame.setOver();
}

bool UITitle::processEvent(sf::Event event)
{
            if (event.key.code == sf::Keyboard::Z)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (m_currentButton == &m_buttonQuit) {
                        m_currentButton = &m_buttonLevels;
                        m_buttonQuit.setOut();
                        m_buttonLevels.setOver();
                    }
                    else if (m_currentButton == &m_buttonLevels) {
                        m_currentButton = &m_buttonNewGame;
                        m_buttonLevels.setOut();
                        m_buttonNewGame.setOver();
                    }
                }
            }
            if (event.key.code == sf::Keyboard::S)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (m_currentButton == &m_buttonNewGame) {
                        m_currentButton = &m_buttonLevels;
                        m_buttonNewGame.setOut();
                        m_buttonLevels.setOver();
                    }
                    else if (m_currentButton == &m_buttonLevels) {
                        m_currentButton = &m_buttonQuit;
                        m_buttonLevels.setOut();
                        m_buttonQuit.setOver();
                    }
                }
                
            }

            if (event.key.code == sf::Keyboard::Enter)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    if (m_currentButton == &m_buttonNewGame) {
                        m_sceneTitle->launchScene("title", "game", 1);
                        m_buttonNewGame.setPressed();
                    }
                    else if (m_currentButton == &m_buttonLevels) {
                        m_buttonLevels.setPressed();
                    }
                    else if (m_currentButton == &m_buttonQuit) {
                        m_buttonQuit.setPressed();
                        m_sceneTitle->quit();
                    }
                }

            }

	return false;
}

void UITitle::update(float deltaTime)
{
}

void UITitle::render(sf::RenderWindow* window)
{
	m_buttonNewGame.draw(window);
	m_buttonLevels.draw(window);
	m_buttonQuit.draw(window);
}
