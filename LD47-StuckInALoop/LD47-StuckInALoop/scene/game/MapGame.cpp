#include "MapGame.h"
#include <iostream>

MapGame::MapGame(SceneGame* sceneGame)
{
	m_sceneGame = sceneGame;

    sf::Texture* tilesheet = m_sceneGame->getResource()->getTexture("tilesheet");
    int size = tilesheet->getSize().x;
    for (int i = 0; i < size;i++) {
        sf::Sprite sprite;
        sprite.setTexture(*tilesheet);
        sprite.setTextureRect(sf::IntRect(i * 32, 0, 32, 32));
        m_tiles.push_back(sprite);
    }

    m_startPosition = sf::Vector2f(336, 100);
}

bool MapGame::processEvent(sf::Event event)
{
	return false;
}

void MapGame::update(float deltaTime)
{
    
}

void MapGame::render(sf::RenderWindow* window)
{
    for (int i = 0; i < m_sprites.size();i++) {
           window->draw(m_sprites[i]);
    }
}

void MapGame::revealStep(int level, int step)
{
    m_currentLevel = std::vector<std::vector<int>>();
    m_sprites = std::vector<sf::Sprite>();

	std::vector<std::vector<int>> data = m_sceneGame->getData(level);
    std::vector<std::vector<sf::Vector2i>> steps = m_sceneGame->getSteps(level);
	std::vector<std::pair<int, int>> zones = m_sceneGame->getZones(level);
 
    int stepIndex = step - 1;
           
	for (int i = zones[stepIndex].first; i < zones[stepIndex].second; i++) {
        m_currentLevel.push_back(std::vector<int>());
        for (int j = zones[stepIndex].first; j < zones[stepIndex].second; j++) {
            m_currentLevel[i - zones[stepIndex].first].push_back(data[i][j]);
            

            bool founded = false;
            sf::Sprite sprite;
            for (int k = 0; k < steps[stepIndex].size();k++) {
                if (i == steps[stepIndex][k].x && j == steps[stepIndex][k].y) {
                    sprite = m_tiles[28];
                    founded = true;
                    break;
                }
            }

            if (founded == false) {
                int index = data[i][j];
                sprite = m_tiles[index];
            }
           
            sprite.setPosition(m_startPosition.x + j * 32, m_startPosition.y + i * 32);
            m_sprites.push_back(sprite);
        }
    }
}

std::vector<std::vector<int>>* MapGame::getCurrentLevel()
{
    return &m_currentLevel;
}

std::vector<sf::Sprite>* MapGame::getMap()
{
    return &m_sprites;
}
