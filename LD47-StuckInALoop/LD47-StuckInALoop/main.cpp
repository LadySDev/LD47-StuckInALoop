#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>

//std::vector<sf::Sprite> m_spritesheet;
//std::vector<std::vector<int>> m_level1;
//std::vector<sf::Vector2i> m_level1step1;
//std::vector<sf::Vector2i> m_level1step2;
//std::vector<sf::Vector2i> m_level1step3;
//std::vector<sf::Vector2i> m_level1step4;
//sf::Vector2i startPos;
//int m_currentStep;
//std::vector<std::vector<int>> m_currentLevel;
//std::vector<sf::Sprite> m_map1;
//bool m_isPlayerFreezed;
//sf::RectangleShape m_stepTextShape;
//sf::Text m_stepText;
//std::vector<sf::CircleShape> m_stepCircleShapes;
////sf::Clock m_clock;
//float m_timer;
////sf::Clock m_animClock;
//float m_animTimer;
//std::vector<sf::IntRect> m_animMoveDown;
//std::vector<sf::IntRect> m_animMoveLeft;
//std::vector<sf::IntRect> m_animMoveRight;
//std::vector<sf::IntRect> m_animMoveUp;
//std::vector<sf::IntRect> m_animFall;
//std::vector<sf::IntRect> m_currentAnim;
//int m_currentAnimFrame;
//bool m_isAnimationPlayed;




//void revealStepOne() {
//    m_currentLevel = std::vector<std::vector<int>>();
//    m_map1 = std::vector<sf::Sprite>();
//
//    for (int i = 7; i < 12; i++) {
//        m_currentLevel.push_back(std::vector<int>());
//        for (int j = 7; j < 12; j++) {
//            m_currentLevel[i - 7].push_back(m_level1[i][j]);
//            int index = m_level1[i][j];
//            sf::Sprite sprite = m_spritesheet[index];
//            sprite.setPosition(startPos.x + j * 32, startPos.y + i * 32);
//            m_map1.push_back(sprite);
//        }
//    }
//
//    for (int i = 0; i < m_level1step1.size(); i++) {
//        sf::Sprite sprite = m_spritesheet[28];
//        sprite.setPosition(startPos.x + m_level1step1[i].x * 32, startPos.y + m_level1step1[i].y * 32);
//        int indexX = m_level1step1[i].x - 7;
//        int indexY = m_level1step1[i].y - 7;
//        m_map1[indexX + indexY * m_currentLevel.size()] = sprite;
//    }
//
//    m_stepCircleShapes = std::vector<sf::CircleShape>();
//
//    sf::CircleShape circleShape;
//    circleShape.setRadius(16);
//    circleShape.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 - circleShape.getGlobalBounds().width / 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape.setFillColor(sf::Color::Red);
//    circleShape.setOutlineColor(sf::Color::White);
//    circleShape.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape);
//}
//
//void revealStepTwo() {
//    m_currentLevel = std::vector<std::vector<int>>();
//    m_map1 = std::vector<sf::Sprite>();
//
//    for (int i = 5; i < 14; i++) {
//        m_currentLevel.push_back(std::vector<int>());
//        for (int j = 5; j < 14; j++) {
//            m_currentLevel[i - 5].push_back(m_level1[i][j]);
//            int index = m_level1[i][j];
//            sf::Sprite sprite = m_spritesheet[index];
//            sprite.setPosition(startPos.x + j * 32, startPos.y + i * 32);
//            m_map1.push_back(sprite);
//        }
//    }
//
//    for (int i = 0; i < m_level1step2.size(); i++) {
//        sf::Sprite sprite = m_spritesheet[28];
//        sprite.setPosition(startPos.x + m_level1step2[i].x * 32, startPos.y + m_level1step2[i].y * 32);
//        int indexX = m_level1step2[i].x - 5;
//        int indexY = m_level1step2[i].y - 5;
//        m_map1[indexX + indexY * m_currentLevel.size()] = sprite;
//    }
//
//    m_currentStep = 2;
//    m_stepText.setString("STEP " + std::to_string(m_currentStep));
//
//    m_stepCircleShapes = std::vector<sf::CircleShape>();
//
//    sf::CircleShape circleShape1;
//    circleShape1.setRadius(16);
//    circleShape1.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 - circleShape1.getGlobalBounds().width - 5 - 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape1.setFillColor(sf::Color::Red);
//    circleShape1.setOutlineColor(sf::Color::White);
//    circleShape1.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape1);
//
//    sf::CircleShape circleShape2;
//    circleShape2.setRadius(16);
//    circleShape2.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 + 5 + 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape2.setFillColor(sf::Color::Red);
//    circleShape2.setOutlineColor(sf::Color::White);
//    circleShape2.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape2);
//
//    m_clock.restart();
//}
//
//void revealStepThree() {
//    m_currentLevel = std::vector<std::vector<int>>();
//    m_map1 = std::vector<sf::Sprite>();
//
//    for (int i = 3; i < 16; i++) {
//        m_currentLevel.push_back(std::vector<int>());
//        for (int j = 3; j < 16; j++) {
//            m_currentLevel[i - 3].push_back(m_level1[i][j]);
//            int index = m_level1[i][j];
//            sf::Sprite sprite = m_spritesheet[index];
//            sprite.setPosition(startPos.x + j * 32, startPos.y + i * 32);
//            m_map1.push_back(sprite);
//        }
//    }
//    
//    for (int i = 0; i < m_level1step3.size(); i++) {
//        sf::Sprite sprite = m_spritesheet[28];
//        sprite.setPosition(startPos.x + m_level1step3[i].x * 32, startPos.y + m_level1step3[i].y * 32);
//        int indexX = m_level1step3[i].x - 3;
//        int indexY = m_level1step3[i].y - 3;
//        int index = indexX + indexY * m_currentLevel.size();
//        m_map1[indexX + indexY * m_currentLevel.size()] = sprite;
//    }
//    
//    m_currentStep = 3;
//    m_stepText.setString("STEP " + std::to_string(m_currentStep));
//
//    m_stepCircleShapes = std::vector<sf::CircleShape>();
//
//    sf::CircleShape circleShape1;
//    circleShape1.setRadius(16);
//    circleShape1.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 - circleShape1.getGlobalBounds().width - circleShape1.getGlobalBounds().width / 2 - 10 - 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape1.setFillColor(sf::Color::Red);
//    circleShape1.setOutlineColor(sf::Color::White);
//    circleShape1.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape1);
//
//    sf::CircleShape circleShape2;
//    circleShape2.setRadius(16);
//    circleShape2.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 - circleShape2.getGlobalBounds().width / 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape2.setFillColor(sf::Color::Red);
//    circleShape2.setOutlineColor(sf::Color::White);
//    circleShape2.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape2);
//
//    sf::CircleShape circleShape3;
//    circleShape3.setRadius(16);
//    circleShape3.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 - circleShape3.getGlobalBounds().width / 2 + circleShape3.getGlobalBounds().width + 10 + 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape3.setFillColor(sf::Color::Red);
//    circleShape3.setOutlineColor(sf::Color::White);
//    circleShape3.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape3);
//}
//
//void revealStepFour() {
//    m_currentLevel = std::vector<std::vector<int>>();
//    m_map1 = std::vector<sf::Sprite>();
//
//    int c = 0;
//    for (int i = 0; i < 19; i++) {
//        m_currentLevel.push_back(std::vector<int>());
//        for (int j = 0; j < 19; j++) {
//            m_currentLevel[i].push_back(m_level1[i][j]);
//            int index = m_level1[i][j];
//            sf::Sprite sprite = m_spritesheet[index];
//            sprite.setPosition(startPos.x + j * 32, startPos.y + i * 32);
//            m_map1.push_back(sprite);
//        }
//    }
//    
//    for (int i = 0; i < m_level1step4.size(); i++) {
//        sf::Sprite sprite = m_spritesheet[28];
//        sprite.setPosition(startPos.x + m_level1step4[i].x * 32, startPos.y + m_level1step4[i].y * 32);
//        int indexX = m_level1step4[i].x;
//        int indexY = m_level1step4[i].y;
//        m_map1[indexX + indexY * m_currentLevel.size()] = sprite;
//    }
//    
//    m_currentStep = 4;
//    m_stepText.setString("STEP " + std::to_string(m_currentStep));
//
//    m_stepCircleShapes = std::vector<sf::CircleShape>();
//
//    sf::CircleShape circleShape1;
//    circleShape1.setRadius(16);
//    circleShape1.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 - circleShape1.getGlobalBounds().width * 2 - 20 - 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape1.setFillColor(sf::Color::Red);
//    circleShape1.setOutlineColor(sf::Color::White);
//    circleShape1.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape1);
//
//    sf::CircleShape circleShape2;
//    circleShape2.setRadius(16);
//    circleShape2.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 - circleShape2.getGlobalBounds().width - 5 - 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape2.setFillColor(sf::Color::Red);
//    circleShape2.setOutlineColor(sf::Color::White);
//    circleShape2.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape2);
//
//    sf::CircleShape circleShape3;
//    circleShape3.setRadius(16);
//    circleShape3.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 + 5 + 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape3.setFillColor(sf::Color::Red);
//    circleShape3.setOutlineColor(sf::Color::White);
//    circleShape3.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape3);
//
//    sf::CircleShape circleShape4;
//    circleShape4.setRadius(16);
//    circleShape4.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 + circleShape4.getGlobalBounds().width + 20 + 2, m_stepTextShape.getPosition().y + m_stepTextShape.getGlobalBounds().height + 10 + 2);
//    circleShape4.setFillColor(sf::Color::Red);
//    circleShape4.setOutlineColor(sf::Color::White);
//    circleShape4.setOutlineThickness(2);
//
//    m_stepCircleShapes.push_back(circleShape4);
//}

int main()
{
    

    Game* game = new Game();

    ////init
    ////data
    //m_level1 = {
    //    { 13, 13, 13, 16,  0,  0,  0,  0,  0, 17, 13, 13, 16,  0,  0,  0,  0,  0,  0},
    //    {  0,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0,  0},
    //    {  0,  0,  0, 18, 15, 15, 15, 15, 15, 19,  0,  0, 14,  0,  0,  4, 15, 15, 20},
    //    {  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    //    {  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    //    {  0,  0,  0,  5,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    //    {  0,  0,  0, 21, 15, 15, 22, 15, 15, 23, 15, 15, 24, 15, 15,  2,  0,  0, 10},
    //    {  0,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    //    {  0,  0,  0,  3,  0,  0,  3,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    //    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0, 25, 26},
    //    {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0, 14,  0},
    //    {  0,  0,  0,  5,  0,  0,  5,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0, 14,  0},
    //    { 15, 15, 15, 19,  0,  0, 18, 15, 15, 27,  0,  0, 18, 15,  2,  0,  0, 14,  0},
    //    {  0,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0,  0,  0,  0, 14,  0},
    //    {  0,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0,  0,  0,  0,  0,  0, 14,  0},
    //    {  0,  0,  0, 14,  0,  0,  0,  0,  0, 14,  0,  0,  5,  0,  0,  0,  0, 14,  0},
    //    {  0,  0,  0, 18, 15, 15, 22, 15, 15, 19,  0,  0, 21, 15, 15, 15, 15, 23, 20},
    //    {  0,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10},
    //    {  0,  0,  0,  0,  0,  0, 14,  0,  0, 14,  0,  0, 14,  0,  0,  0,  0,  0, 10}
    //};

    //sf::Vector2i m_level1Spawn = sf::Vector2i(9, 9);

    //m_level1step1 = {
    //    sf::Vector2i(9, 7)
    //};

    //m_level1step2 = {
    //    sf::Vector2i(10, 5),
    //    sf::Vector2i(13, 10)
    //};

    //m_level1step3 = {
    //    sf::Vector2i(13, 4),
    //    sf::Vector2i(4, 14),
    //    sf::Vector2i(13, 14)
    //};

    //m_level1step4 = {
    //    sf::Vector2i(18, 10),
    //    sf::Vector2i(2, 14),
    //    sf::Vector2i(8, 17),
    //    sf::Vector2i(15, 18)
    //};

    // startPos = sf::Vector2i(336, 100);
    // m_currentStep = 1;

    ////texture
    //sf::Texture m_tilesheet;
    //if (!m_tilesheet.loadFromFile("resource/tilesheet.png")) {
    //    exit(0);
    //}

    //sf::Texture m_playerTexture;
    //if (!m_playerTexture.loadFromFile("resource/player.png")) {
    //    exit(0);
    //}

    //sf::Texture m_playersheet;
    //if (!m_playersheet.loadFromFile("resource/playersheet.png")) {
    //    exit(0);
    //}

    ////font
    //sf::Font m_eternity;
    //if (!m_eternity.loadFromFile("resource/Eternity Time.ttf")) {
    //    exit(0);
    //}

    ////sprite
    //
    //for (int i = 0; i < m_tilesheet.getSize().x / 32; i++) {
    //    sf::Sprite sprite;
    //    sprite.setTexture(m_tilesheet);
    //    sprite.setTextureRect(sf::IntRect(i * 32, 0, 32, 32));
    //    m_spritesheet.push_back(sprite);
    //}

    ////player animations
    //m_animMoveDown.push_back(sf::IntRect(32 * 0, 32 * 0, 32, 32));
    //m_animMoveDown.push_back(sf::IntRect(32 * 1, 32 * 0, 32, 32));
    //m_animMoveDown.push_back(sf::IntRect(32 * 2, 32 * 0, 32, 32));
    //m_animMoveDown.push_back(sf::IntRect(32 * 3, 32 * 0, 32, 32));

    //m_animMoveLeft.push_back(sf::IntRect(32 * 0, 32 * 1, 32, 32));
    //m_animMoveLeft.push_back(sf::IntRect(32 * 1, 32 * 1, 32, 32));
    //m_animMoveLeft.push_back(sf::IntRect(32 * 2, 32 * 1, 32, 32));
    //m_animMoveLeft.push_back(sf::IntRect(32 * 3, 32 * 1, 32, 32));

    //m_animMoveRight.push_back(sf::IntRect(32 * 0, 32 * 2, 32, 32));
    //m_animMoveRight.push_back(sf::IntRect(32 * 1, 32 * 2, 32, 32));
    //m_animMoveRight.push_back(sf::IntRect(32 * 2, 32 * 2, 32, 32));
    //m_animMoveRight.push_back(sf::IntRect(32 * 3, 32 * 2, 32, 32));

    //m_animMoveUp.push_back(sf::IntRect(32 * 0, 32 * 3, 32, 32));
    //m_animMoveUp.push_back(sf::IntRect(32 * 1, 32 * 3, 32, 32));
    //m_animMoveUp.push_back(sf::IntRect(32 * 2, 32 * 3, 32, 32));
    //m_animMoveUp.push_back(sf::IntRect(32 * 3, 32 * 3, 32, 32));

    //m_animFall.push_back(sf::IntRect(32 * 0, 32 * 4, 32, 32));
    //m_animFall.push_back(sf::IntRect(32 * 1, 32 * 4, 32, 32));
    //m_animFall.push_back(sf::IntRect(32 * 2, 32 * 4, 32, 32));
    //m_animFall.push_back(sf::IntRect(32 * 3, 32 * 4, 32, 32));

    //m_currentAnim = m_animMoveDown;
    //m_currentAnimFrame = 0;
    //m_isAnimationPlayed = false;
    //m_animTimer = 0;

    //sf::Sprite m_playerSprite;
    ////m_playerSprite.setTexture(m_playerTexture);
    //m_playerSprite.setTexture(m_playersheet);
    //m_playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    ////shape
    //sf::RectangleShape m_background;
    //m_background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    //m_background.setPosition(0, 0);
    //m_background.setFillColor(sf::Color(128,128,128,255));

    //sf::RectangleShape m_levelTextShape;
    //m_levelTextShape.setSize(sf::Vector2f(32*19, 50));
    //m_levelTextShape.setPosition(window.getSize().x / 2 - (32 * 19 / 2), 10);
    //m_levelTextShape.setFillColor(sf::Color::White);

    //
    //m_stepTextShape.setSize(sf::Vector2f(316, 50));
    //m_stepTextShape.setPosition(336 + (32 * 19) + 10, startPos.y + 32 * 6);
    //m_stepTextShape.setFillColor(sf::Color::White);

    //

    //sf::RectangleShape m_timerTextShape;
    //m_timerTextShape.setSize(sf::Vector2f(316, 50));
    //m_timerTextShape.setPosition(10, startPos.y + 32 * 6);
    //m_timerTextShape.setFillColor(sf::Color::White);

    ////text
    //sf::Text m_levelText;
    //m_levelText.setFont(m_eternity);
    //m_levelText.setCharacterSize(40);
    //m_levelText.setFillColor(sf::Color::Black);
    //m_levelText.setString("LEVEL 1");
    //m_levelText.setPosition(window.getSize().x / 2 - m_levelText.getGlobalBounds().width / 2, 15);
    //   
    //m_stepText.setFont(m_eternity);
    //m_stepText.setCharacterSize(40);
    //m_stepText.setFillColor(sf::Color::Black);
    //m_stepText.setString("STEP " + std::to_string(m_currentStep));
    //m_stepText.setPosition(m_stepTextShape.getPosition().x + m_stepTextShape.getGlobalBounds().width / 2 - m_stepText.getGlobalBounds().width / 2, m_stepTextShape.getPosition().y + 5);

    //sf::Text m_timerTitleText;
    //m_timerTitleText.setFont(m_eternity);
    //m_timerTitleText.setCharacterSize(40);
    //m_timerTitleText.setFillColor(sf::Color::Black);
    //m_timerTitleText.setString("COUNTDOWN");
    //m_timerTitleText.setPosition(m_timerTextShape.getPosition().x + m_timerTextShape.getGlobalBounds().width / 2 - m_timerTitleText.getGlobalBounds().width / 2, m_timerTextShape.getPosition().y + 5);

    //m_timer = 80;
    //int min = m_timer / 60;
    //int sec = m_timer - (min * 60);

    //sf::Text m_timerText;
    //m_timerText.setFont(m_eternity);
    //m_timerText.setCharacterSize(40);
    //m_timerText.setFillColor(sf::Color::White);
    //m_timerText.setString(std::to_string(min) + ":" + std::to_string(sec));
    //m_timerText.setPosition(m_timerTextShape.getPosition().x + m_timerTextShape.getGlobalBounds().width / 2 - m_timerText.getGlobalBounds().width / 2, m_timerTextShape.getPosition().y + m_timerTextShape.getGlobalBounds().height + 5);

    //////level1 map
    /////*for (int i = 0; i < m_level1.size();i++) {
    ////    for (int j = 0;j< m_level1[i].size(); j++) {
    ////        int index = m_level1[i][j];
    ////        sf::Sprite sprite = m_spritesheet[index];
    ////        sprite.setPosition(startPos.x + j*32, startPos.y + i*32);
    ////        m_map1.push_back(sprite);
    ////    }
    ////}*/

    //revealStepOne();

    //m_playerSprite.setPosition(startPos.x + m_level1Spawn.x * 32, startPos.y + m_level1Spawn.y * 32);

    //bool m_moveUp = false;
    //bool m_moveDown = false;
    //bool m_moveLeft = false;
    //bool m_moveRight = false;
    //double m_playerSpeed = 3;
    //bool m_isPlayerFreezed = false;

   

            ////event
            //if (m_isPlayerFreezed == true && (m_moveUp == true || m_moveDown == true || m_moveLeft == true || m_moveRight == true)) {
            //    m_moveUp = false;
            //    m_moveDown = false;
            //    m_moveLeft = false;
            //    m_moveRight = false;
            //}

            //if (event.key.code == sf::Keyboard::Z)
            //{
            //    if (event.type == sf::Event::KeyPressed && m_moveUp == false && m_moveDown == false && m_isPlayerFreezed == false)
            //    {
            //        m_currentAnim = m_animMoveUp;
            //        m_currentAnimFrame = 0;
            //        m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
            //        m_isAnimationPlayed = true;
            //        m_moveUp = true;
            //    }
            //    if (event.type == sf::Event::KeyReleased && m_moveUp == true)
            //    {
            //        m_isAnimationPlayed = false;
            //        m_moveUp = false;
            //    }
            //}
            //if (event.key.code == sf::Keyboard::S)
            //{
            //    if (event.type == sf::Event::KeyPressed && m_moveUp == false && m_moveDown == false && m_isPlayerFreezed == false)
            //    {
            //        m_currentAnim = m_animMoveDown;
            //        m_currentAnimFrame = 0;
            //        m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
            //        m_isAnimationPlayed = true;
            //        m_moveDown = true;
            //    }
            //    if (event.type == sf::Event::KeyReleased && m_moveDown == true)
            //    {
            //        m_isAnimationPlayed = false;
            //        m_moveDown = false;
            //    }
            //}

            //if (event.key.code == sf::Keyboard::Q)
            //{
            //    if (event.type == sf::Event::KeyPressed &&  m_moveLeft == false && m_moveRight == false &&  m_isPlayerFreezed == false)
            //    {
            //        m_currentAnim = m_animMoveLeft;
            //        m_currentAnimFrame = 0;
            //        m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
            //        m_isAnimationPlayed = true;
            //        m_moveLeft = true;
            //    }
            //    if (event.type == sf::Event::KeyReleased && m_moveLeft == true)
            //    {
            //        m_isAnimationPlayed = false;
            //        m_moveLeft = false;
            //    }
            //}
            //
            //if (event.key.code == sf::Keyboard::D)
            //{
            //    if (event.type == sf::Event::KeyPressed &&  m_moveLeft == false && m_moveRight == false &&  m_isPlayerFreezed == false)
            //    {
            //        m_currentAnim = m_animMoveRight;
            //        m_currentAnimFrame = 0;
            //        m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
            //        m_isAnimationPlayed = true;
            //        m_moveRight = true;
            //    }
            //    if (event.type == sf::Event::KeyReleased && m_moveRight == true)
            //    {
            //        m_isAnimationPlayed = false;
            //        m_moveRight = false;
            //    }
            //}
       
        ////update
        //if (m_timer > 0 && m_isPlayerFreezed == false) {
        //    m_timer = m_timer - m_clock.restart().asSeconds();
        //    int min = m_timer / 60;
        //    int sec = m_timer - (min * 60);
        //    m_timerText.setString(std::to_string(min) + ":" + std::to_string(sec));
        //}

        //if (m_moveUp == true) {
        //    m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y - m_playerSpeed);
        //    if (m_map1[0].getPosition().y - m_playerSprite.getGlobalBounds().height / 2 > m_playerSprite.getPosition().y) {
        //        m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_map1[m_map1.size()-1].getPosition().y + m_playerSprite.getGlobalBounds().height / 2);
        //    }

        //    for (int i = 0; i < m_map1.size();i++) {
        //        if (m_playerSprite.getPosition().x + 16 >= m_map1[i].getPosition().x && m_playerSprite.getPosition().x + 16 <= m_map1[i].getPosition().x + 32
        //            && m_playerSprite.getPosition().y >= m_map1[i].getPosition().y && m_playerSprite.getPosition().y <= m_map1[i].getPosition().y + 10) {
        //            int indexX = (m_map1[i].getPosition().x - startPos.x) / 32;
        //            int indexY = (m_map1[i].getPosition().y - startPos.y) / 32;

        //            int subStep = 0;
        //            if (m_currentStep == 1) {
        //                subStep = 7;
        //            }
        //            else if (m_currentStep == 2) {
        //                subStep = 5;
        //            }
        //            else if (m_currentStep == 3) {
        //                subStep = 3;
        //            }

        //            int value = m_currentLevel[indexY - subStep][indexX - subStep];
        //            if (value != 0) {
        //                m_isPlayerFreezed = true;
        //                m_currentAnim = m_animFall;
        //                m_currentAnimFrame = 0;
        //                m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
        //                break;
        //            }
        //        }
        //    }
        //}
        //if (m_moveDown == true) {
        //    m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y + m_playerSpeed);
        //    if (m_map1[m_map1.size() - 1].getPosition().y + m_playerSprite.getGlobalBounds().height / 2 < m_playerSprite.getPosition().y) {
        //        m_playerSprite.setPosition(m_playerSprite.getPosition().x, m_map1[0].getPosition().y - m_playerSprite.getGlobalBounds().height / 2);
        //    }
        //    for (int i = 0; i < m_map1.size(); i++) {
        //        if (m_playerSprite.getPosition().x + 16 >= m_map1[i].getPosition().x && m_playerSprite.getPosition().x + 16 <= m_map1[i].getPosition().x + 32
        //            && m_playerSprite.getPosition().y + 32 >= m_map1[i].getPosition().y + 22 && m_playerSprite.getPosition().y + 32 <= m_map1[i].getPosition().y + 32) {
        //            int indexX = (m_map1[i].getPosition().x - startPos.x) / 32;
        //            int indexY = (m_map1[i].getPosition().y - startPos.y) / 32;

        //            int subStep = 0;
        //            if (m_currentStep == 1) {
        //                subStep = 7;
        //            }
        //            else if (m_currentStep == 2) {
        //                subStep = 5;
        //            }
        //            else if (m_currentStep == 3) {
        //                subStep = 3;
        //            }

        //            int value = m_currentLevel[indexY - subStep][indexX - subStep];
        //            std::cout << "cell x " << indexX - subStep << std::endl;
        //            std::cout << "cell y " << indexY - subStep << std::endl;
        //            std::cout << "value " << value << std::endl;
        //            if (value != 0) {
        //                m_isPlayerFreezed = true;
        //                m_currentAnim = m_animFall;
        //                m_currentAnimFrame = 0;
        //                m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
        //                break;
        //            }
        //        }
        //    }
        //}
        //if (m_moveLeft == true) {
        //    m_playerSprite.setPosition(m_playerSprite.getPosition().x - m_playerSpeed, m_playerSprite.getPosition().y);
        //    if (m_map1[0].getPosition().x - m_playerSprite.getGlobalBounds().height / 2 > m_playerSprite.getPosition().x) {
        //        m_playerSprite.setPosition(m_map1[m_map1.size() - 1].getPosition().x + m_playerSprite.getGlobalBounds().width / 2, m_playerSprite.getPosition().y);
        //    }
        //    for (int i = 0; i < m_map1.size(); i++) {
        //        if (m_playerSprite.getPosition().x >= m_map1[i].getPosition().x && m_playerSprite.getPosition().x <= m_map1[i].getPosition().x + 10
        //            && m_playerSprite.getPosition().y + 16 >= m_map1[i].getPosition().y && m_playerSprite.getPosition().y + 16 <= m_map1[i].getPosition().y + 32) {
        //            int indexX = (m_map1[i].getPosition().x - startPos.x) / 32;
        //            int indexY = (m_map1[i].getPosition().y - startPos.y) / 32;

        //            int subStep = 0;
        //            if (m_currentStep == 1) {
        //                subStep = 7;
        //            }
        //            else if (m_currentStep == 2) {
        //                subStep = 5;
        //            }
        //            else if (m_currentStep == 3) {
        //                subStep = 3;
        //            }

        //            int value = m_currentLevel[indexY - subStep][indexX - subStep];
        //            if (value != 0) {
        //                m_isPlayerFreezed = true;
        //                m_currentAnim = m_animFall;
        //                m_currentAnimFrame = 0;
        //                m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
        //                break;
        //            }
        //        }
        //    }
        //}
        //if (m_moveRight == true) {
        //    m_playerSprite.setPosition(m_playerSprite.getPosition().x + m_playerSpeed, m_playerSprite.getPosition().y);
        //    if (m_map1[m_map1.size() - 1].getPosition().x + m_playerSprite.getGlobalBounds().width / 2 < m_playerSprite.getPosition().x) {
        //        m_playerSprite.setPosition(m_map1[0].getPosition().x - m_playerSprite.getGlobalBounds().height / 2, m_playerSprite.getPosition().y);
        //    }
        //    for (int i = 0; i < m_map1.size(); i++) {
        //        if (m_playerSprite.getPosition().x + 32 >= m_map1[i].getPosition().x + 22 && m_playerSprite.getPosition().x + 32 <= m_map1[i].getPosition().x + 32
        //            && m_playerSprite.getPosition().y + 16 >= m_map1[i].getPosition().y && m_playerSprite.getPosition().y + 16 <= m_map1[i].getPosition().y + 32) {
        //            int indexX = (m_map1[i].getPosition().x - startPos.x) / 32;
        //            int indexY = (m_map1[i].getPosition().y - startPos.y) / 32;

        //            int subStep = 0;
        //            if (m_currentStep == 1) {
        //                subStep = 7;
        //            }
        //            else if (m_currentStep == 2) {
        //                subStep = 5;
        //            }
        //            else if (m_currentStep == 3) {
        //                subStep = 3;
        //            }

        //            int value = m_currentLevel[indexY - subStep][indexX - subStep];
        //            if (value != 0) {
        //                m_isPlayerFreezed = true;
        //                m_currentAnim = m_animFall;
        //                m_currentAnimFrame = 0;
        //                m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
        //                break;
        //            }
        //        }
        //    }
        //}

        //if (m_currentStep == 1) {
        //    for (int i = 0; i < m_level1step1.size(); i++) {
        //        int indexX = m_level1step1[i].x - 7;
        //        int indexY = m_level1step1[i].y - 7;
        //       
        //        if (m_playerSprite.getPosition().x <= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().x + m_playerSprite.getGlobalBounds().width / 2
        //            && m_playerSprite.getPosition().x >= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().x - m_playerSprite.getGlobalBounds().width / 2
        //            && m_playerSprite.getPosition().y <= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().y + m_playerSprite.getGlobalBounds().height / 2
        //            && m_playerSprite.getPosition().y >= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().y - m_playerSprite.getGlobalBounds().height / 2
        //            && m_isPlayerFreezed == false) {
        //            m_isPlayerFreezed = true;
        //           
        //            m_map1[indexX + indexY * m_currentLevel.size()].setTextureRect(sf::IntRect(32*29, 0, 32, 32));
        //            m_stepCircleShapes[i].setFillColor(sf::Color::Green);
        //            
        //            
        //            revealStepTwo();
        //            
        //            m_isPlayerFreezed = false;
        //        }
        //    }
        //}
        //else if (m_currentStep == 2) {
        //    for (int i = 0; i < m_level1step2.size(); i++) {
        //        int indexX = m_level1step2[i].x - 5;
        //        int indexY = m_level1step2[i].y - 5;
        //        
        //        if (m_playerSprite.getPosition().x <= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().x + m_playerSprite.getGlobalBounds().width / 2
        //            && m_playerSprite.getPosition().x >= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().x - m_playerSprite.getGlobalBounds().width / 2
        //            && m_playerSprite.getPosition().y <= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().y + m_playerSprite.getGlobalBounds().height / 2
        //            && m_playerSprite.getPosition().y >= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().y - m_playerSprite.getGlobalBounds().height / 2
        //            && m_isPlayerFreezed == false) {
        //            
        //            m_map1[indexX + indexY * m_currentLevel.size()].setTextureRect(sf::IntRect(32 * 29, 0, 32, 32));
        //            m_stepCircleShapes[i].setFillColor(sf::Color::Green);
        //        }
        //    }
        //    int counter = 0;
        //    for (int i = 0; i < m_stepCircleShapes.size();i++) {
        //        if (m_stepCircleShapes[i].getFillColor() == sf::Color::Green) {
        //            counter = counter + 1;
        //        }
        //    }
        //    if (counter == m_stepCircleShapes.size()) {
        //        m_isPlayerFreezed = true;
        //        revealStepThree();
        //        m_isPlayerFreezed = false;
        //    }
        //}
        //else if (m_currentStep == 3) {
        //    for (int i = 0; i < m_level1step3.size(); i++) {
        //        int indexX = m_level1step3[i].x - 3;
        //        int indexY = m_level1step3[i].y - 3;

        //        if (m_playerSprite.getPosition().x <= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().x + m_playerSprite.getGlobalBounds().width / 2
        //            && m_playerSprite.getPosition().x >= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().x - m_playerSprite.getGlobalBounds().width / 2
        //            && m_playerSprite.getPosition().y <= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().y + m_playerSprite.getGlobalBounds().height / 2
        //            && m_playerSprite.getPosition().y >= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().y - m_playerSprite.getGlobalBounds().height / 2
        //            && m_isPlayerFreezed == false) {

        //            m_map1[indexX + indexY * m_currentLevel.size()].setTextureRect(sf::IntRect(32 * 29, 0, 32, 32));
        //            m_stepCircleShapes[i].setFillColor(sf::Color::Green);
        //        }
        //    }
        //    int counter = 0;
        //    for (int i = 0; i < m_stepCircleShapes.size(); i++) {
        //        if (m_stepCircleShapes[i].getFillColor() == sf::Color::Green) {
        //            counter = counter + 1;
        //        }
        //    }
        //    if (counter == m_stepCircleShapes.size()) {
        //        m_isPlayerFreezed = true;
        //        revealStepFour();
        //        m_isPlayerFreezed = false;
        //    }
        //}
        //else if (m_currentStep == 4) {
        //    for (int i = 0; i < m_level1step4.size(); i++) {
        //        int indexX = m_level1step4[i].x;
        //        int indexY = m_level1step4[i].y;

        //        if (m_playerSprite.getPosition().x <= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().x + m_playerSprite.getGlobalBounds().width / 2
        //            && m_playerSprite.getPosition().x >= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().x - m_playerSprite.getGlobalBounds().width / 2
        //            && m_playerSprite.getPosition().y <= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().y + m_playerSprite.getGlobalBounds().height / 2
        //            && m_playerSprite.getPosition().y >= m_map1[indexX + indexY * m_currentLevel.size()].getPosition().y - m_playerSprite.getGlobalBounds().height / 2
        //            && m_isPlayerFreezed == false) {

        //            m_map1[indexX + indexY * m_currentLevel.size()].setTextureRect(sf::IntRect(32 * 29, 0, 32, 32));
        //            m_stepCircleShapes[i].setFillColor(sf::Color::Green);
        //        }
        //    }
        //    int counter = 0;
        //    for (int i = 0; i < m_stepCircleShapes.size(); i++) {
        //        if (m_stepCircleShapes[i].getFillColor() == sf::Color::Green) {
        //            counter = counter + 1;
        //        }
        //    }
        //    if (counter == m_stepCircleShapes.size()) {
        //        m_isPlayerFreezed = true;
        //        
        //       
        //    }
        //}

        //if (m_isAnimationPlayed == true) {
        //    std::cout << "play an anim" << std::endl;
        //    m_animTimer = m_animTimer + deltaTime;
        //    
        //    if (m_animTimer >= 250) {
        //        m_currentAnimFrame = m_currentAnimFrame + 1;
        //        
        //        if (m_currentAnim != m_animFall || (m_currentAnim == m_animFall && m_currentAnim.size() != m_currentAnimFrame)) {
        //            if (m_currentAnim.size() == m_currentAnimFrame) {
        //                m_currentAnimFrame = 0;
        //            }
        //            m_playerSprite.setTextureRect(m_currentAnim[m_currentAnimFrame]);
        //            m_animTimer = 0;
        //        }
        //        else if (m_currentAnim == m_animFall && m_currentAnim.size() == m_currentAnimFrame) {
        //            m_isAnimationPlayed = false;
        //            m_animTimer = 0;
        //        }
        //       
        //    }
        //}
        //else if (m_isAnimationPlayed == false && m_animTimer != 0) {
        //    m_animTimer = 0;
        //}

       
        ////render
        //window.draw(m_background);

        ////window.draw(shape);
        //for (int i = 0; i < m_map1.size();i++) {
        //    window.draw(m_map1[i]);
        //}
        //window.draw(m_playerSprite);

        ////ui
        //window.draw(m_levelTextShape);
        //window.draw(m_levelText);
        //window.draw(m_stepTextShape);
        //window.draw(m_stepText);
        //for (int i = 0; i < m_stepCircleShapes.size(); i++) {
        //    window.draw(m_stepCircleShapes[i]);
        //}
        //window.draw(m_timerTextShape);
        //window.draw(m_timerTitleText);
        //window.draw(m_timerText);

    

    return 0;
}