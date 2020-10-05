#include "UIGameMenu.h"

UIGameMenu::UIGameMenu(SceneGame* sceneGame)
{
	m_sceneGame = sceneGame;

    m_shapeBackground = m_sceneGame->getResource()->getRectangleShape("gameMenuBg");

    m_state = "pause";

	m_buttonResume = m_sceneGame->getResource()->getButton();	
	m_buttonResume.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonResume.getSize().x / 2, m_sceneGame->getSize().y / 2 - m_buttonResume.getSize().y - m_buttonResume.getSize().y / 2 - 15)));
    m_buttonResume.setText("RESUME");
    m_buttonResume.setTextPosition(sf::Vector2f(m_buttonResume.getPosition().x + m_buttonResume.getSize().x / 2 - m_buttonResume.getTextSize().x / 2, m_buttonResume.getPosition().y + m_buttonResume.getSize().y / 2 - m_buttonResume.getTextSize().y / 2));

    m_buttonRestart = m_sceneGame->getResource()->getButton();    
    m_buttonRestart.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonRestart.getSize().x / 2, m_sceneGame->getSize().y / 2 - m_buttonRestart.getSize().y / 2 - 5)));
    m_buttonRestart.setText("RESTART");
    m_buttonRestart.setTextPosition(sf::Vector2f(m_buttonRestart.getPosition().x + m_buttonRestart.getSize().x / 2 - m_buttonRestart.getTextSize().x / 2, m_buttonRestart.getPosition().y + m_buttonRestart.getSize().y / 2 - m_buttonRestart.getTextSize().y / 2));

    m_buttonTitle = m_sceneGame->getResource()->getButton();    
    m_buttonTitle.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonTitle.getSize().x / 2, m_sceneGame->getSize().y / 2 + m_buttonTitle.getSize().y / 2 + 5)));
    m_buttonTitle.setText("TITLE");
    m_buttonTitle.setTextPosition(sf::Vector2f(m_buttonTitle.getPosition().x + m_buttonTitle.getSize().x / 2 - m_buttonTitle.getTextSize().x / 2, m_buttonTitle.getPosition().y + m_buttonTitle.getSize().y / 2 - m_buttonTitle.getTextSize().y / 2));

    m_buttonQuit = m_sceneGame->getResource()->getButton();    
    m_buttonQuit.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonQuit.getSize().x / 2, m_sceneGame->getSize().y / 2 + m_buttonQuit.getSize().y + m_buttonQuit.getSize().y / 2 + 15)));
    m_buttonQuit.setText("QUIT");
    m_buttonQuit.setTextPosition(sf::Vector2f(m_buttonQuit.getPosition().x + m_buttonQuit.getSize().x / 2 - m_buttonQuit.getTextSize().x / 2, m_buttonQuit.getPosition().y + m_buttonQuit.getSize().y / 2 - m_buttonQuit.getTextSize().y / 2));

    m_textState.setFont(*m_sceneGame->getResource()->getFont());
    m_textState.setCharacterSize(40);
    m_textState.setFillColor(sf::Color::Black);
    m_textState.setString("PAUSE");
    m_textState.setPosition(sf::Vector2f(m_sceneGame->getSize().x / 2 - m_buttonResume.getSize().x / 2 - m_textState.getGlobalBounds().width / 2 - 20, m_buttonResume.getPosition().y - 80));
    m_textState.setRotation(-20);

    for (int i = 0; i < 4; i++) {
        Button* button;
        if (i == 0) {
            button = &m_buttonResume;
        }
        else if (i == 1) {
            button = &m_buttonRestart;
        }
        else if (i == 2) {
            button = &m_buttonTitle;
        }
        else if (i == 3) {
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
            button->setOver();

            button->setTextCharacterSize(button->getTextCharacterSize() + 2);

            button->setIsPressed(false);
        };
    }

    m_currentButton = &m_buttonResume;
    m_buttonResume.setOver();
}

bool UIGameMenu::processEvent(sf::Event event)
{
    if (event.key.code == sf::Keyboard::Z)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (m_currentButton == &m_buttonQuit) {
                m_currentButton = &m_buttonTitle;
                m_buttonQuit.setOut();
                m_buttonTitle.setOver();
            }
            else if (m_currentButton == &m_buttonTitle) {
                m_currentButton = &m_buttonRestart;
                m_buttonTitle.setOut();
                m_buttonRestart.setOver();
            }
            else if (m_currentButton == &m_buttonRestart && m_state != "lose") {
                m_currentButton = &m_buttonResume;
                m_buttonRestart.setOut();
                m_buttonResume.setOver();
            }
        }
    }
    if (event.key.code == sf::Keyboard::S)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (m_currentButton == &m_buttonResume && m_state != "lose") {
                m_currentButton = &m_buttonRestart;
                m_buttonResume.setOut();
                m_buttonRestart.setOver();
            }
            else if (m_currentButton == &m_buttonRestart) {
                m_currentButton = &m_buttonTitle;
                m_buttonRestart.setOut();
                m_buttonTitle.setOver();
            }
            else if (m_currentButton == &m_buttonTitle) {
                m_currentButton = &m_buttonQuit;
                m_buttonTitle.setOut();
                m_buttonQuit.setOver();
            }
        }

    }

    if (event.key.code == sf::Keyboard::Enter)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (m_currentButton == &m_buttonResume) {                
                m_buttonResume.setPressed();
                m_buttonResume.setReleased();
                if (m_state == "pause") {
                    m_sceneGame->setMenuDisplay(false, "pause");
                } 
            }
            else if (m_currentButton == &m_buttonRestart) {
                m_sceneGame->launchScene("game", "game", 1);
                m_buttonRestart.setPressed();
            }
            else if (m_currentButton == &m_buttonTitle) {
                m_sceneGame->launchScene("game", "title", NULL);
                m_buttonTitle.setPressed();
            }
            else if (m_currentButton == &m_buttonQuit) {
                m_buttonQuit.setPressed();
                m_sceneGame->quit();
            }
        }

    }

	return false;
}

void UIGameMenu::update(float deltaTime)
{
    if (m_state == "pause" && m_textState.getString() != "PAUSE") {
        m_textState.setString("PAUSE");
        m_textState.setPosition(sf::Vector2f(m_sceneGame->getSize().x / 2 - m_buttonResume.getSize().x / 2 - m_textState.getGlobalBounds().width / 2 - 20, m_buttonResume.getPosition().y - 80));

        
        m_buttonResume.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonResume.getSize().x / 2, m_sceneGame->getSize().y / 2 - m_buttonResume.getSize().y - m_buttonResume.getSize().y / 2 - 15)));
        m_buttonResume.setText("RESUME");
        m_buttonResume.setTextPosition(sf::Vector2f(m_buttonResume.getPosition().x + m_buttonResume.getSize().x / 2 - m_buttonResume.getTextSize().x / 2, m_buttonResume.getPosition().y + m_buttonResume.getSize().y / 2 - m_buttonResume.getTextSize().y / 2));

        m_buttonRestart.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonRestart.getSize().x / 2, m_sceneGame->getSize().y / 2 - m_buttonRestart.getSize().y / 2 - 5)));

        m_buttonTitle.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonTitle.getSize().x / 2, m_sceneGame->getSize().y / 2 + m_buttonTitle.getSize().y / 2 + 5)));
    
        m_buttonQuit.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonQuit.getSize().x / 2, m_sceneGame->getSize().y / 2 + m_buttonQuit.getSize().y + m_buttonQuit.getSize().y / 2 + 15)));
    }
    else if (m_state == "win" && m_textState.getString() != "WIN") {
        m_textState.setString("WIN");
        m_textState.setPosition(sf::Vector2f(m_sceneGame->getSize().x / 2 - m_buttonResume.getSize().x / 2 - m_textState.getGlobalBounds().width / 2 - 20, m_buttonResume.getPosition().y - 80));

        m_buttonResume.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonResume.getSize().x / 2, m_sceneGame->getSize().y / 2 - m_buttonResume.getSize().y - m_buttonResume.getSize().y / 2 - 15)));
        m_buttonResume.setText("NEXT");
        m_buttonResume.setTextPosition(sf::Vector2f(m_buttonResume.getPosition().x + m_buttonResume.getSize().x / 2 - m_buttonResume.getTextSize().x / 2, m_buttonResume.getPosition().y + m_buttonResume.getSize().y / 2 - m_buttonResume.getTextSize().y / 2));

        m_buttonRestart.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonRestart.getSize().x / 2, m_sceneGame->getSize().y / 2 - m_buttonRestart.getSize().y / 2 - 5)));

        m_buttonTitle.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonTitle.getSize().x / 2, m_sceneGame->getSize().y / 2 + m_buttonTitle.getSize().y / 2 + 5)));

        m_buttonQuit.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonQuit.getSize().x / 2, m_sceneGame->getSize().y / 2 + m_buttonQuit.getSize().y + m_buttonQuit.getSize().y / 2 + 15)));
    }
    else if (m_state == "lose" && m_textState.getString() != "LOSE") {
        resetButtons();
        m_buttonRestart.setOver();
        m_currentButton = &m_buttonRestart;

        m_textState.setString("LOSE");
        m_textState.setPosition(sf::Vector2f(m_sceneGame->getSize().x / 2 - m_buttonResume.getSize().x / 2 - m_textState.getGlobalBounds().width / 2 - 20, m_buttonResume.getPosition().y - 80));
                
        m_buttonResume.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonResume.getSize().x / 2, m_sceneGame->getSize().y / 2 - m_buttonResume.getSize().y - m_buttonResume.getSize().y / 2 - 15 - m_buttonResume.getTextSize().y / 2)));
        m_buttonResume.setTextPosition(sf::Vector2f(m_buttonResume.getPosition().x + m_buttonResume.getSize().x / 2 - m_buttonResume.getTextSize().x / 2, m_buttonResume.getPosition().y + m_buttonResume.getSize().y / 2 - m_buttonResume.getTextSize().y / 2));

        m_buttonRestart.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonRestart.getSize().x / 2, m_sceneGame->getSize().y / 2 - m_buttonRestart.getSize().y / 2 - 5 - m_buttonRestart.getTextSize().y / 2)));
        m_buttonRestart.setTextPosition(sf::Vector2f(m_buttonRestart.getPosition().x + m_buttonRestart.getSize().x / 2 - m_buttonRestart.getTextSize().x / 2, m_buttonRestart.getPosition().y + m_buttonRestart.getSize().y / 2 - m_buttonRestart.getTextSize().y / 2));

        m_buttonTitle.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonTitle.getSize().x / 2, m_sceneGame->getSize().y / 2 + m_buttonTitle.getSize().y / 2 + 5 - m_buttonTitle.getTextSize().y / 2)));
        m_buttonTitle.setTextPosition(sf::Vector2f(m_buttonTitle.getPosition().x + m_buttonTitle.getSize().x / 2 - m_buttonTitle.getTextSize().x / 2, m_buttonTitle.getPosition().y + m_buttonTitle.getSize().y / 2 - m_buttonTitle.getTextSize().y / 2));

        m_buttonQuit.setPosition(sf::Vector2f(sf::Vector2i(m_sceneGame->getSize().x / 2 - m_buttonQuit.getSize().x / 2, m_sceneGame->getSize().y / 2 + m_buttonQuit.getSize().y + m_buttonQuit.getSize().y / 2 + 15 - m_buttonQuit.getTextSize().y / 2)));
        m_buttonQuit.setTextPosition(sf::Vector2f(m_buttonQuit.getPosition().x + m_buttonQuit.getSize().x / 2 - m_buttonQuit.getTextSize().x / 2, m_buttonQuit.getPosition().y + m_buttonQuit.getSize().y / 2 - m_buttonQuit.getTextSize().y / 2));
    }
}

void UIGameMenu::render(sf::RenderWindow* window)
{
    window->draw(m_shapeBackground);
    window->draw(m_textState);

    if (m_state != "lose") {
        m_buttonResume.draw(window);
    }
    
    m_buttonRestart.draw(window);
    m_buttonTitle.draw(window);
    m_buttonQuit.draw(window);
}

void UIGameMenu::setState(std::string state)
{
    m_state = state;
}

void UIGameMenu::resetButtons()
{
    m_buttonResume.setOver();
    m_buttonRestart.setOut();
    m_buttonTitle.setOut();
    m_buttonQuit.setOut();
}

