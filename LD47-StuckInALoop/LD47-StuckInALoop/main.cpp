#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "LD47 Suck in a loop");

    //init
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    //data
    std::vector<std::vector<int>> m_level1 = {
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

    sf::Vector2i m_level1Spawn = sf::Vector2i(9, 9);

    std::vector<sf::Vector2i> m_level1step1 = {
        sf::Vector2i(9, 7)
        //sf::Vector2i(2, 0)
    };

    //texture
    sf::Texture m_tilesheet;
    if (!m_tilesheet.loadFromFile("resource/tilesheet.png")) {
        exit(0);
    }

    sf::Texture m_playerTexture;
    if (!m_playerTexture.loadFromFile("resource/player.png")) {
        exit(0);
    }

    //sprite
    std::vector<sf::Sprite> m_spritesheet;
    for (int i = 0; i < m_tilesheet.getSize().x / 32; i++) {
        sf::Sprite sprite;
        sprite.setTexture(m_tilesheet);
        sprite.setTextureRect(sf::IntRect(i * 32, 0, 32, 32));
        m_spritesheet.push_back(sprite);
    }

    sf::Sprite m_playerSprite;
    m_playerSprite.setTexture(m_playerTexture);
    m_playerSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    //level1 map
    std::vector<sf::Sprite> m_map1;
    for (int i = 0; i < m_level1.size();i++) {
        for (int j = 0;j< m_level1[i].size(); j++) {
            int index = m_level1[i][j];
            sf::Sprite sprite = m_spritesheet[index];
            sprite.setPosition(336 + j*32, 56 + i*32);
            m_map1.push_back(sprite);
        }
    }

    /*for (int i = 7; i < 11; i++) {
        for (int j = 7; j < 11; j++) {
            int index = m_level1[i][j];
            sf::Sprite sprite = m_spritesheet[index];
            sprite.setPosition(336 + j * 32, 56 + i * 32);
            m_map1.push_back(sprite);
        }
    }*/

    for (int i = 0; i < m_level1step1.size();i++) {
        sf::Sprite sprite = m_spritesheet[28];
        sprite.setPosition(336 + m_level1step1[i].x * 32, 56 + m_level1step1[i].y * 32);
        m_map1[m_level1step1[i].x + m_level1step1[i].y * m_level1.size()] = sprite;
    }

    m_playerSprite.setPosition(336 + m_level1Spawn.x * 32, 56 + m_level1Spawn.y * 32);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //event
        }

        //update

        window.clear();

        //render
        //window.draw(shape);
        for (int i = 0; i < m_map1.size();i++) {
            window.draw(m_map1[i]);
        }
        window.draw(m_playerSprite);

        window.display();
    }

    return 0;
}