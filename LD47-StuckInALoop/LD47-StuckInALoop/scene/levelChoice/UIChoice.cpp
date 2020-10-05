#include "UIChoice.h"
#include <iostream>

UIChoice::UIChoice(SceneChoice* sceneChoice)
{
	m_sceneChoice = sceneChoice;

    m_shapeTitle.setSize(sf::Vector2f(32 * 19, 50));
    m_shapeTitle.setPosition(sf::Vector2f(m_sceneChoice->getSize().x / 2 - m_shapeTitle.getSize().x / 2, 10));

    m_textTitle.setFont(*m_sceneChoice->getResource()->getFont());
    m_textTitle.setCharacterSize(40);
    m_textTitle.setFillColor(sf::Color::Black);
    m_textTitle.setString("LEVELS");
    m_textTitle.setPosition(sf::Vector2f(m_sceneChoice->getSize().x / 2 - m_textTitle.getGlobalBounds().width / 2, 15));

    m_cols = 5;
    m_rows = 2;
    for (int row = 0; row < m_rows; row++) {
        m_buttonLevels.push_back(std::vector<Button>());
        for (int col = 0; col < m_cols; col++) {
            Button button = m_sceneChoice->getResource()->getButton();
            button.setPosition(sf::Vector2f(sf::Vector2i(209 + (10 + button.getSize().x) * col, 190 + (10 + button.getSize().y) * row)));
            int number = col + row * m_cols + 1;
            button.setText("LEVEL "+std::to_string(number));
            button.setTextPosition(sf::Vector2f(button.getPosition().x + button.getSize().x / 2 - button.getTextSize().x / 2, button.getPosition().y + button.getSize().y / 2 - button.getTextSize().y / 2));
        
            m_buttonLevels[row].push_back(button);
        }
    }

	m_buttonBack = m_sceneChoice->getResource()->getButton();	
	m_buttonBack.setPosition(sf::Vector2f(sf::Vector2i(m_sceneChoice->getSize().x / 2 - m_buttonBack.getSize().x / 2, m_sceneChoice->getSize().y - m_buttonBack.getSize().y - 10)));
    m_buttonBack.setText("BACK");
    m_buttonBack.setTextPosition(sf::Vector2f(m_buttonBack.getPosition().x + m_buttonBack.getSize().x / 2 - m_buttonBack.getTextSize().x / 2, m_buttonBack.getPosition().y + m_buttonBack.getSize().y / 2 - m_buttonBack.getTextSize().y / 2));

    int size = m_rows * m_cols;   
    for (int i = 0; i < size + 1; i++) {        
        Button* button;
        if (i == size) {
            button = &m_buttonBack;
        }
        else {
            int row = i / m_cols;
            int col = i - (i / m_cols) * m_cols;
            button = &m_buttonLevels[row][col];
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

    m_currentButton = &m_buttonLevels[0][0];
    m_currentButton->setOver();
}

bool UIChoice::processEvent(sf::Event event)
{
    if (event.key.code == sf::Keyboard::Z)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (m_currentButton != &m_buttonBack) {
                std::string name = m_currentButton->getText();
                int pos = name.find(" ");
                std::string level = name.substr(0, pos);
                name.erase(0, pos + 1);
                int number = std::stoi(name) - 1;
                int newNumber = number - m_cols;
                if (newNumber > -1) {
                    int row = newNumber / m_cols;
                    int col = newNumber - (newNumber / m_cols) * m_cols;
                    m_currentButton->setOut();
                    m_currentButton = &m_buttonLevels[row][col];
                    m_currentButton->setOver();
                }
            }
            else if (m_currentButton == &m_buttonBack) {                
                m_currentButton->setOut();
                m_currentButton = &m_buttonLevels[m_rows - 1][m_cols / 2];
                m_currentButton->setOver();
            }
        }
    }
    if (event.key.code == sf::Keyboard::S)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (m_currentButton != &m_buttonBack) {
                std::string name = m_currentButton->getText();
                int pos = name.find(" ");
                std::string level = name.substr(0, pos);
                name.erase(0, pos + 1);
                int number = std::stoi(name) - 1;
                int newNumber = number + m_cols;
                if (newNumber < m_rows * m_cols) {
                    int row = newNumber / m_cols;
                    int col = newNumber - (newNumber / m_cols) * m_cols;
                    m_currentButton->setOut();
                    m_currentButton = &m_buttonLevels[row][col];
                    m_currentButton->setOver();
                }
                else {
                    m_currentButton->setOut();
                    m_currentButton = &m_buttonBack;
                    m_currentButton->setOver();
                }
            }            
        }

    }

    if (event.key.code == sf::Keyboard::Q)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (m_currentButton != &m_buttonBack) {
                std::string name = m_currentButton->getText();
                int pos = name.find(" ");
                std::string level = name.substr(0, pos);
                name.erase(0, pos + 1);
                int number = std::stoi(name) - 1;
                int newNumber = number - 1;
                if (newNumber > -1) {
                    int row = newNumber / m_cols;
                    int col = newNumber - (newNumber / m_cols) * m_cols;
                    m_currentButton->setOut();
                    m_currentButton = &m_buttonLevels[row][col];
                    m_currentButton->setOver();
                }
            }
        }
    }

    if (event.key.code == sf::Keyboard::D)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (m_currentButton != &m_buttonBack) {
                std::string name = m_currentButton->getText();
                int pos = name.find(" ");
                std::string level = name.substr(0, pos);
                name.erase(0, pos + 1);
                int number = std::stoi(name) - 1;
                int newNumber = number + 1;
                if (newNumber < m_rows * m_cols) {
                    int row = newNumber / m_cols;
                    int col = newNumber - (newNumber / m_cols) * m_cols;
                    m_currentButton->setOut();
                    m_currentButton = &m_buttonLevels[row][col];
                    m_currentButton->setOver();
                }
            }
        }
    }

    if (event.key.code == sf::Keyboard::Enter)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (m_currentButton == &m_buttonBack) {
                m_buttonBack.setPressed();
                m_buttonBack.setReleased();
                m_sceneChoice->launchScene("choice", "title", NULL);                
            }   
            else if (m_currentButton == &m_buttonLevels[0][0]) {
                m_currentButton->setPressed();
                m_currentButton->setReleased();
                m_sceneChoice->launchScene("choice", "game", 1);
            }
        }

    }

	return false;
}

void UIChoice::update(float deltaTime)
{
}

void UIChoice::render(sf::RenderWindow* window)
{
    window->draw(m_shapeTitle);
    window->draw(m_textTitle);

    for (int row = 0; row < m_rows; row++) {  
        for (int col = 0; col < m_cols; col++) {
            m_buttonLevels[row][col].draw(window);
        }
    }

	m_buttonBack.draw(window);
}
