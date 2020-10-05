#include "SceneGame.h"
#include <iostream>

SceneGame::SceneGame(Game* game, int level)
{
	m_game = game;

    m_shapeBackGround = m_game->getResource()->getRectangleShape("gameBg");

    m_startPosition = sf::Vector2f(336, 100);

    //LEVEL 1//
    dataLvl1 = {
    { 13, 13, 13, 16,  0,  0,  0,  0,  0, 17, 13, 13, 16,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0,  0},
    {  0,  0,  0, 18, 15, 15, 15, 15, 15, 19,  0,  0, 14,  0,  0,  4, 15, 15, 20},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    {  0,  0,  0,  5,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    {  0,  0,  0, 21, 15, 15, 22, 15, 15, 23, 15, 15, 24, 15, 15,  2,  0,  0, 10},
    {  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    {  0,  0,  0,  3,  0,  0,  3,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0, 25, 26},
    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0, 14,  0},
    {  0,  0,  0,  5,  0,  0,  5,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0, 14,  0},
    { 15, 15, 15, 19,  0,  0, 18, 15, 15, 27,  0,  0, 18, 15,  2,  0,  0, 14,  0},
    {  0,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0,  0,  0,  0, 14,  0},
    {  0,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0,  0,  0,  0, 14,  0},
    {  0,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0,  5,  0,  0,  0,  0, 14,  0},
    {  0,  0,  0, 18, 15, 15, 22, 15, 15, 19,  0,  0, 21, 15, 15, 15, 15, 23, 20},
    {  0,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    {  0,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10}
    };
    spawnLvl1 = sf::Vector2i(9, 9);
    stepsLvl1 = {
        {
            sf::Vector2i(7, 9)
        },
        {
            sf::Vector2i(5, 10),
            sf::Vector2i(10, 13)
        },
        {
            sf::Vector2i(4, 13),
            sf::Vector2i(14, 4),
            sf::Vector2i(14, 13)
        },
        {
            sf::Vector2i(10, 18),
            sf::Vector2i(14, 2),
            sf::Vector2i(17, 8),
            sf::Vector2i(18, 15)
        }
    };
    zonesLvl1 = {
        { std::pair<int, int>(7, 12) },
        { std::pair<int, int>(5, 14) },
        { std::pair<int, int>(3, 16) },
        { std::pair<int, int>(0, 19) },
    };
    timerLvl1 = 80;
	/////////////////////
	

	m_level = 1;
	m_step = 1;
	m_trigger = stepsLvl1[m_step - 1].size();
    for (int i = 0; i < m_trigger;i++) {
        m_triggerValidate.push_back(false);
    }
	m_timer = timerLvl1;

    m_animMoveDown.push_back(sf::IntRect(32 * 0, 32 * 0, 32, 32));
    m_animMoveDown.push_back(sf::IntRect(32 * 1, 32 * 0, 32, 32));
    m_animMoveDown.push_back(sf::IntRect(32 * 2, 32 * 0, 32, 32));
    m_animMoveDown.push_back(sf::IntRect(32 * 3, 32 * 0, 32, 32));

    m_animMoveLeft.push_back(sf::IntRect(32 * 0, 32 * 1, 32, 32));
    m_animMoveLeft.push_back(sf::IntRect(32 * 1, 32 * 1, 32, 32));
    m_animMoveLeft.push_back(sf::IntRect(32 * 2, 32 * 1, 32, 32));
    m_animMoveLeft.push_back(sf::IntRect(32 * 3, 32 * 1, 32, 32));

    m_animMoveRight.push_back(sf::IntRect(32 * 0, 32 * 2, 32, 32));
    m_animMoveRight.push_back(sf::IntRect(32 * 1, 32 * 2, 32, 32));
    m_animMoveRight.push_back(sf::IntRect(32 * 2, 32 * 2, 32, 32));
    m_animMoveRight.push_back(sf::IntRect(32 * 3, 32 * 2, 32, 32));

    m_animMoveUp.push_back(sf::IntRect(32 * 0, 32 * 3, 32, 32));
    m_animMoveUp.push_back(sf::IntRect(32 * 1, 32 * 3, 32, 32));
    m_animMoveUp.push_back(sf::IntRect(32 * 2, 32 * 3, 32, 32));
    m_animMoveUp.push_back(sf::IntRect(32 * 3, 32 * 3, 32, 32));

    m_animFall.push_back(sf::IntRect(32 * 0, 32 * 4, 32, 32));
    m_animFall.push_back(sf::IntRect(32 * 1, 32 * 4, 32, 32));
    m_animFall.push_back(sf::IntRect(32 * 2, 32 * 4, 32, 32));
    m_animFall.push_back(sf::IntRect(32 * 3, 32 * 4, 32, 32));

    m_currentAnim = m_animMoveDown;
    m_currentAnimFrame = 0;
    m_isAnimationPlayed = false;
    m_animTimer = 0;

    sf::Texture* playersheet = m_game->getResource()->getTexture("playersheet");

    m_playerSprite;
    m_playerSprite.setTexture(*playersheet);
    m_playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	m_uigame = new UIGame(this);
    m_mapgame = new MapGame(this);
    m_uigamemenu = new UIGameMenu(this);

    m_isMenuDisplay = false;

    m_mapgame->revealStep(m_level, m_step);    

    m_playerSprite.setPosition(m_startPosition.x + spawnLvl1.x * 32, m_startPosition.y + spawnLvl1.y * 32);
   
    m_moveUp = false;
    m_moveDown = false;
    m_moveLeft = false;
    m_moveRight = false;
    m_playerSpeed = 3;
    m_isPlayerFreezed = false;

    m_gameOver = false;
    m_win = false;
    m_stateTimer = 0;
}

void SceneGame::processEvent(sf::Event event)
{
	m_uigame->processEvent(event);

    m_mapgame->processEvent(event);


    if (m_isMenuDisplay == false) {
        if (m_isPlayerFreezed == true && (m_moveUp == true || m_moveDown == true || m_moveLeft == true || m_moveRight == true)) {
            m_moveUp = false;
            m_moveDown = false;
            m_moveLeft = false;
            m_moveRight = false;
        }

        if (event.key.code == sf::Keyboard::Z)
        {
            if (event.type == sf::Event::KeyPressed && m_moveUp == false && m_moveDown == false && m_isPlayerFreezed == false)
            {
                m_currentAnim = m_animMoveUp;
                m_currentAnimFrame = 0;
                m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
                m_isAnimationPlayed = true;
                m_moveUp = true;
            }
            if (event.type == sf::Event::KeyReleased && m_moveUp == true)
            {
                m_isAnimationPlayed = false;
                m_moveUp = false;
            }
        }
        if (event.key.code == sf::Keyboard::S)
        {
            if (event.type == sf::Event::KeyPressed && m_moveUp == false && m_moveDown == false && m_isPlayerFreezed == false)
            {
                m_currentAnim = m_animMoveDown;
                m_currentAnimFrame = 0;
                m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
                m_isAnimationPlayed = true;
                m_moveDown = true;
            }
            if (event.type == sf::Event::KeyReleased && m_moveDown == true)
            {
                m_isAnimationPlayed = false;
                m_moveDown = false;
            }
        }

        if (event.key.code == sf::Keyboard::Q)
        {
            if (event.type == sf::Event::KeyPressed && m_moveLeft == false && m_moveRight == false && m_isPlayerFreezed == false)
            {
                m_currentAnim = m_animMoveLeft;
                m_currentAnimFrame = 0;
                m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
                m_isAnimationPlayed = true;
                m_moveLeft = true;
            }
            if (event.type == sf::Event::KeyReleased && m_moveLeft == true)
            {
                m_isAnimationPlayed = false;
                m_moveLeft = false;
            }
        }

        if (event.key.code == sf::Keyboard::D)
        {
            if (event.type == sf::Event::KeyPressed && m_moveLeft == false && m_moveRight == false && m_isPlayerFreezed == false)
            {
                m_currentAnim = m_animMoveRight;
                m_currentAnimFrame = 0;
                m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
                m_isAnimationPlayed = true;
                m_moveRight = true;
            }
            if (event.type == sf::Event::KeyReleased && m_moveRight == true)
            {
                m_isAnimationPlayed = false;
                m_moveRight = false;
            }
        }

        if (event.key.code == sf::Keyboard::P)
        {
            if (event.type == sf::Event::KeyPressed)
            {
                setMenuDisplay(true, "pause");
            }       
        }
    }
    else if (m_isMenuDisplay == true) {
        m_uigamemenu->processEvent(event);
    }
}

void SceneGame::update(float deltaTime)
{
    if (m_isMenuDisplay == false) {

        if (m_gameOver == true || m_win ==true) {
            m_stateTimer = m_stateTimer + deltaTime / 1000;
            if (m_stateTimer >= 1) {
                if (m_gameOver == true) {
                    setMenuDisplay(true, "lose");
                }
                else if (m_win == true)
                {
                    setMenuDisplay(true, "win");
                }
                
            }
        }
      
        if (m_timer > 0 && m_isPlayerFreezed == false) {
            m_timer = m_timer - deltaTime / 1000;
        }
        else if (m_timer <= 0 && m_isPlayerFreezed == false) {
            m_gameOver = true;
            m_isPlayerFreezed = true;
        }

        std::vector<sf::Sprite>* map = m_mapgame->getMap();
        std::vector<std::vector<int>>* currentLevel = m_mapgame->getCurrentLevel();

        if (m_moveUp == true) {
            m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y - m_playerSpeed);
            if ((*map)[0].getPosition().y - m_playerSprite.getGlobalBounds().height / 2 > m_playerSprite.getPosition().y) {
                m_playerSprite.setPosition(m_playerSprite.getPosition().x, (*map)[(*map).size() - 1].getPosition().y + m_playerSprite.getGlobalBounds().height / 2);
            }

            for (int i = 0; i < (*map).size(); i++) {
                if (m_playerSprite.getPosition().x + 16 >= (*map)[i].getPosition().x && m_playerSprite.getPosition().x + 16 <= (*map)[i].getPosition().x + 32
                    && m_playerSprite.getPosition().y >= (*map)[i].getPosition().y && m_playerSprite.getPosition().y <= (*map)[i].getPosition().y + 10) {
                    int indexX = ((*map)[i].getPosition().x - m_startPosition.x) / 32;
                    int indexY = ((*map)[i].getPosition().y - m_startPosition.y) / 32;

                    int subStep = 0;
                    if (m_step == 1) {
                        subStep = 7;
                    }
                    else if (m_step == 2) {
                        subStep = 5;
                    }
                    else if (m_step == 3) {
                        subStep = 3;
                    }

                    int value = (*currentLevel)[indexY - subStep][indexX - subStep];
                    if (value != 0) {
                        m_isPlayerFreezed = true;
                        m_currentAnim = m_animFall;
                        m_currentAnimFrame = 0;
                        m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
                        m_gameOver = true;
                        break;
                    }
                }
            }
        }
        if (m_moveDown == true) {
            m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y + m_playerSpeed);
            if ((*map)[(*map).size() - 1].getPosition().y + m_playerSprite.getGlobalBounds().height / 2 < m_playerSprite.getPosition().y) {
                m_playerSprite.setPosition(m_playerSprite.getPosition().x, (*map)[0].getPosition().y - m_playerSprite.getGlobalBounds().height / 2);
            }
            for (int i = 0; i < (*map).size(); i++) {
                if (m_playerSprite.getPosition().x + 16 >= (*map)[i].getPosition().x && m_playerSprite.getPosition().x + 16 <= (*map)[i].getPosition().x + 32
                    && m_playerSprite.getPosition().y + 32 >= (*map)[i].getPosition().y + 22 && m_playerSprite.getPosition().y + 32 <= (*map)[i].getPosition().y + 32) {
                    int indexX = ((*map)[i].getPosition().x - m_startPosition.x) / 32;
                    int indexY = ((*map)[i].getPosition().y - m_startPosition.y) / 32;

                    int subStep = 0;
                    if (m_step == 1) {
                        subStep = 7;
                    }
                    else if (m_step == 2) {
                        subStep = 5;
                    }
                    else if (m_step == 3) {
                        subStep = 3;
                    }

                    int value = (*currentLevel)[indexY - subStep][indexX - subStep];
                    if (value != 0) {
                        m_isPlayerFreezed = true;
                        m_currentAnim = m_animFall;
                        m_currentAnimFrame = 0;
                        m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
                        m_gameOver = true;
                        break;
                    }
                }
            }
        }
        if (m_moveLeft == true) {
            m_playerSprite.setPosition(m_playerSprite.getPosition().x - m_playerSpeed, m_playerSprite.getPosition().y);
            if ((*map)[0].getPosition().x - m_playerSprite.getGlobalBounds().height / 2 > m_playerSprite.getPosition().x) {
                m_playerSprite.setPosition((*map)[(*map).size() - 1].getPosition().x + m_playerSprite.getGlobalBounds().width / 2, m_playerSprite.getPosition().y);
            }
            for (int i = 0; i < (*map).size(); i++) {
                if (m_playerSprite.getPosition().x >= (*map)[i].getPosition().x && m_playerSprite.getPosition().x <= (*map)[i].getPosition().x + 10
                    && m_playerSprite.getPosition().y + 16 >= (*map)[i].getPosition().y && m_playerSprite.getPosition().y + 16 <= (*map)[i].getPosition().y + 32) {
                    int indexX = ((*map)[i].getPosition().x - m_startPosition.x) / 32;
                    int indexY = ((*map)[i].getPosition().y - m_startPosition.y) / 32;

                    int subStep = 0;
                    if (m_step == 1) {
                        subStep = 7;
                    }
                    else if (m_step == 2) {
                        subStep = 5;
                    }
                    else if (m_step == 3) {
                        subStep = 3;
                    }

                    int value = (*currentLevel)[indexY - subStep][indexX - subStep];
                    if (value != 0) {
                        m_isPlayerFreezed = true;
                        m_currentAnim = m_animFall;
                        m_currentAnimFrame = 0;
                        m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
                        m_gameOver = true;
                        break;
                    }
                }
            }
        }
        if (m_moveRight == true) {
            m_playerSprite.setPosition(m_playerSprite.getPosition().x + m_playerSpeed, m_playerSprite.getPosition().y);
            if ((*map)[(*map).size() - 1].getPosition().x + m_playerSprite.getGlobalBounds().width / 2 < m_playerSprite.getPosition().x) {
                m_playerSprite.setPosition((*map)[0].getPosition().x - m_playerSprite.getGlobalBounds().height / 2, m_playerSprite.getPosition().y);
            }
            for (int i = 0; i < (*map).size(); i++) {
                if (m_playerSprite.getPosition().x + 32 >= (*map)[i].getPosition().x + 22 && m_playerSprite.getPosition().x + 32 <= (*map)[i].getPosition().x + 32
                    && m_playerSprite.getPosition().y + 16 >= (*map)[i].getPosition().y && m_playerSprite.getPosition().y + 16 <= (*map)[i].getPosition().y + 32) {
                    int indexX = ((*map)[i].getPosition().x - m_startPosition.x) / 32;
                    int indexY = ((*map)[i].getPosition().y - m_startPosition.y) / 32;

                    int subStep = 0;
                    if (m_step == 1) {
                        subStep = 7;
                    }
                    else if (m_step == 2) {
                        subStep = 5;
                    }
                    else if (m_step == 3) {
                        subStep = 3;
                    }

                    int value = (*currentLevel)[indexY - subStep][indexX - subStep];
                    if (value != 0) {
                        m_isPlayerFreezed = true;
                        m_currentAnim = m_animFall;
                        m_currentAnimFrame = 0;
                        m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
                        m_gameOver = true;
                        break;
                    }
                }
            }
        }

        if (m_step == 1) {
            for (int i = 0; i < stepsLvl1[m_step - 1].size(); i++) {
                int indexY = stepsLvl1[m_step - 1][i].x - zonesLvl1[m_step - 1].first;
                int indexX = stepsLvl1[m_step - 1][i].y - zonesLvl1[m_step - 1].first;

                if (m_playerSprite.getPosition().x <= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().x + m_playerSprite.getGlobalBounds().width / 2
                    && m_playerSprite.getPosition().x >= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().x - m_playerSprite.getGlobalBounds().width / 2
                    && m_playerSprite.getPosition().y <= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().y + m_playerSprite.getGlobalBounds().height / 2
                    && m_playerSprite.getPosition().y >= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().y - m_playerSprite.getGlobalBounds().height / 2
                    && m_isPlayerFreezed == false) {
                    m_isPlayerFreezed = true;

                    (*map)[indexX + indexY * (*currentLevel).size()].setTextureRect(sf::IntRect(32 * 29, 0, 32, 32));
                    m_uigame->validateTrigger(i);
                    if (m_triggerValidate[i] == false) {
                        m_triggerValidate[i] = true;
                    }

                    //function//
                    bool validate = true;
                    for (int t = 0; t < m_triggerValidate.size(); t++) {
                        if (m_triggerValidate[t] == false) {
                            validate = false;
                            break;
                        }
                    }

                    if (validate == true) {
                        m_step = 2;
                        m_trigger = stepsLvl1[m_step - 1].size();
                        m_triggerValidate = std::vector<bool>();
                        for (int t = 0; t < m_trigger; t++) {

                            m_triggerValidate.push_back(false);
                        }
                        m_mapgame->revealStep(m_level, m_step);
                    }

                    m_isPlayerFreezed = false;
                }
            }
        }
        else if (m_step == 2) {
            for (int i = 0; i < stepsLvl1[m_step - 1].size(); i++) {
                int indexY = stepsLvl1[m_step - 1][i].x - zonesLvl1[m_step - 1].first;
                int indexX = stepsLvl1[m_step - 1][i].y - zonesLvl1[m_step - 1].first;

                if (m_playerSprite.getPosition().x <= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().x + m_playerSprite.getGlobalBounds().width / 2
                    && m_playerSprite.getPosition().x >= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().x - m_playerSprite.getGlobalBounds().width / 2
                    && m_playerSprite.getPosition().y <= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().y + m_playerSprite.getGlobalBounds().height / 2
                    && m_playerSprite.getPosition().y >= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().y - m_playerSprite.getGlobalBounds().height / 2
                    && m_isPlayerFreezed == false) {
                    m_isPlayerFreezed = true;
                    (*map)[indexX + indexY * (*currentLevel).size()].setTextureRect(sf::IntRect(32 * 29, 0, 32, 32));
                    m_uigame->validateTrigger(i);

                    if (m_triggerValidate[i] == false) {
                        m_triggerValidate[i] = true;
                    }

                    //function//
                    bool validate = true;
                    for (int t = 0; t < m_triggerValidate.size(); t++) {
                        if (m_triggerValidate[t] == false) {
                            validate = false;
                            break;
                        }
                    }

                    if (validate == true) {
                        m_step = 3;
                        m_trigger = stepsLvl1[m_step - 1].size();
                        m_triggerValidate = std::vector<bool>();
                        for (int t = 0; t < m_trigger; t++) {
                            m_triggerValidate.push_back(false);
                        }
                        m_mapgame->revealStep(m_level, m_step);
                    }
                    m_isPlayerFreezed = false;
                }
            }
        }
        else if (m_step == 3) {
            for (int i = 0; i < stepsLvl1[m_step - 1].size(); i++) {
                int indexY = stepsLvl1[m_step - 1][i].x - 3;
                int indexX = stepsLvl1[m_step - 1][i].y - 3;

                if (m_playerSprite.getPosition().x <= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().x + m_playerSprite.getGlobalBounds().width / 2
                    && m_playerSprite.getPosition().x >= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().x - m_playerSprite.getGlobalBounds().width / 2
                    && m_playerSprite.getPosition().y <= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().y + m_playerSprite.getGlobalBounds().height / 2
                    && m_playerSprite.getPosition().y >= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().y - m_playerSprite.getGlobalBounds().height / 2
                    && m_isPlayerFreezed == false) {
                    m_isPlayerFreezed = true;
                    (*map)[indexX + indexY * (*currentLevel).size()].setTextureRect(sf::IntRect(32 * 29, 0, 32, 32));
                    m_uigame->validateTrigger(i);

                    if (m_triggerValidate[i] == false) {
                        m_triggerValidate[i] = true;
                    }

                    //function//
                    bool validate = true;
                    for (int t = 0; t < m_triggerValidate.size(); t++) {
                        if (m_triggerValidate[t] == false) {
                            validate = false;
                            break;
                        }
                    }

                    if (validate == true) {
                        m_step = 4;
                        m_trigger = stepsLvl1[m_step - 1].size();
                        m_triggerValidate = std::vector<bool>();
                        for (int t = 0; t < m_trigger; t++) {
                            m_triggerValidate.push_back(false);
                        }
                        m_mapgame->revealStep(m_level, m_step);
                    }
                    m_isPlayerFreezed = false;
                }
            }
        }
        else if (m_step == 4) {
            for (int i = 0; i < stepsLvl1[m_step - 1].size(); i++) {
                int indexY = stepsLvl1[m_step - 1][i].x;
                int indexX = stepsLvl1[m_step - 1][i].y;

                if (m_playerSprite.getPosition().x <= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().x + m_playerSprite.getGlobalBounds().width / 2
                    && m_playerSprite.getPosition().x >= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().x - m_playerSprite.getGlobalBounds().width / 2
                    && m_playerSprite.getPosition().y <= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().y + m_playerSprite.getGlobalBounds().height / 2
                    && m_playerSprite.getPosition().y >= (*map)[indexX + indexY * (*currentLevel).size()].getPosition().y - m_playerSprite.getGlobalBounds().height / 2
                    && m_isPlayerFreezed == false) {
                    m_isPlayerFreezed = true;
                    (*map)[indexX + indexY * (*currentLevel).size()].setTextureRect(sf::IntRect(32 * 29, 0, 32, 32));
                    m_uigame->validateTrigger(i);

                    if (m_triggerValidate[i] == false) {
                        m_triggerValidate[i] = true;
                    }

                    //function//
                    bool validate = true;
                    for (int t = 0; t < m_triggerValidate.size(); t++) {
                        if (m_triggerValidate[t] == false) {
                            validate = false;
                            break;
                        }
                    }

                    if (validate == true) {
                        m_win = true;
                    }   
                    m_isPlayerFreezed = false;
                }
            }
        }

        if (m_isAnimationPlayed == true) {

            m_animTimer = m_animTimer + deltaTime;

            if (m_animTimer >= 250) {
                m_currentAnimFrame = m_currentAnimFrame + 1;

                if (m_currentAnim != m_animFall || (m_currentAnim == m_animFall && m_currentAnim.size() != m_currentAnimFrame)) {
                    if (m_currentAnim.size() == m_currentAnimFrame) {
                        m_currentAnimFrame = 0;
                    }
                    m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
                    m_animTimer = 0;
                }
                else if (m_currentAnim == m_animFall && m_currentAnim.size() == m_currentAnimFrame) {
                    m_isAnimationPlayed = false;
                    m_animTimer = 0;
                }

            }
        }
        else if (m_isAnimationPlayed == false && m_animTimer != 0) {
            m_animTimer = 0;
        }

        m_uigame->update(deltaTime);
        m_mapgame->update(deltaTime);
    }
    else if (m_isMenuDisplay == true) {
        m_uigamemenu->update(deltaTime);
    }
}

void SceneGame::render(sf::RenderWindow* window)
{
    window->draw(m_shapeBackGround);
    m_mapgame->render(window);    
    m_uigame->render(window);
    window->draw(m_playerSprite);
    if (m_isMenuDisplay == true) {
        m_uigamemenu->render(window);
    }    
}

Resource* SceneGame::getResource()
{
	return m_game->getResource();
}

sf::Vector2i SceneGame::getSize()
{
	return m_game->getSize();
}

void SceneGame::launchScene(std::string from, std::string to, int level)
{
	m_game->launchScene(from, to, level);
}

int SceneGame::getLevel()
{
	return m_level;
}

int SceneGame::getStep()
{
	return m_step;
}

int SceneGame::getTrigger()
{
	return m_trigger;
}

float SceneGame::getTimer()
{
	return m_timer;
}

std::vector<std::vector<int>> SceneGame::getData(int level)
{
    if (level == 1) {
        return dataLvl1;
    }
    else {
        return std::vector<std::vector<int>>();
    }
}

sf::Vector2i SceneGame::getSpawn(int level)
{
    if (level == 1) {
        return spawnLvl1;
    }
    else {
        return sf::Vector2i();
    }
}

std::vector<std::vector<sf::Vector2i>> SceneGame::getSteps(int level)
{
    if (level == 1) {
        return stepsLvl1;
    }
    else {
        return std::vector<std::vector<sf::Vector2i>>();
    }
}

std::vector<std::pair<int, int>> SceneGame::getZones(int level)
{
    if (level == 1) {
        return zonesLvl1;
    }
    else {
        return std::vector<std::pair<int, int>>();
    }
}

void SceneGame::setMenuDisplay(bool display, std::string state)
{
    if (display == true) {
        m_uigamemenu->setState(state);
        m_isMenuDisplay = true;
        m_isPlayerFreezed = true;
    }
    else if (display == false) {
        //m_uigamemenu->resetButtons();
        m_isMenuDisplay = false;
        m_isPlayerFreezed = false;
    }
   
}

void SceneGame::quit()
{
    m_game->quit();
}
