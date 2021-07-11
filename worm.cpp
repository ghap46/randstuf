#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <chrono>
int randomSignedInt()
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ ((std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() + (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> distrib(-2147483648, 2147483647);
    return distrib(gen);    
}
short int randomState()
{
    return abs(randomSignedInt() % 3) - 1;
}
unsigned int xyToNum(unsigned int x, unsigned int y, unsigned int W)
{
    if((x + 1) % W == 0)
    {
        return ((y + 1) * (x + 1)) - 1;
    }
    else
    {
        return (y * W + (x + 1)) - 1;
    }
}
int main()
{
    const unsigned int W = 300;
    const unsigned int H = 400;
    unsigned int randVar = abs(randomSignedInt()) % 2;
    unsigned int xCoord = W / 2;
    unsigned int yCoord = H / 2;
    short int dx = randomState();
    short int dy = randomState();
    if(dx == 0 || dy == 0)
    {
        while(dx == 0 || dy == 0)
        {
            dx = randomState();
            dy = randomState();            
        }
    }
    sf::Texture texture;
    if (!texture.loadFromFile("oddie.png"))
    {
        return -1;
    }
    unsigned int faustoW = texture.getSize().x;
    unsigned int faustoH = texture.getSize().y;
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("ovo.wav"))
    {
        return -1;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sf::VertexArray dot(sf::Points, 1);
    dot[0].color = sf::Color::Black;
    dot[0].position = sf::Vector2f(xCoord, yCoord);
    sf::RenderWindow win(sf::VideoMode(W, H), "Worm", sf::Style::Close);
    win.setFramerateLimit(200);
    win.clear(sf::Color::White);
    while(win.isOpen())
    {
        sf::Event event;
        while(win.pollEvent(event))
        {
            if(event.type == sf::Event::EventType::Closed)
            {
                win.close();
            }
        }
        win.clear(sf::Color::White);
        win.draw(sprite);
        win.display();
        if(dot[0].position.x == (W - 1) - (faustoW / 2) || dot[0].position.x == (faustoW / 2))
        {
            dx = -dx;
            if(randVar == 0)
            {
                buffer.loadFromFile("ovo.wav");
            }
            if(randVar == 1)
            {
                buffer.loadFromFile("errou.wav");                
            }
            //sound.play();
            randVar = abs(randomSignedInt()) % 2;
            //sprite.setColor(sf::Color(abs(randomSignedInt()) % 256, abs(randomSignedInt()) % 256, abs(randomSignedInt()) % 256));
        }
        if(dot[0].position.y == (H - 1) - (faustoH / 2) || dot[0].position.y == (faustoH / 2))
        {
            dy = -dy;
            if(randVar == 0)
            {
                buffer.loadFromFile("ovo.wav");
            }
            if(randVar == 1)
            {
                buffer.loadFromFile("errou.wav");                
            }
            //sound.play();
            randVar = abs(randomSignedInt()) % 2;
            //sprite.setColor(sf::Color(abs(randomSignedInt()) % 256, abs(randomSignedInt()) % 256, abs(randomSignedInt()) % 256));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            dot[0].position = sf::Vector2f(abs(randomSignedInt()) % W, abs(randomSignedInt()) % H);
            win.clear(sf::Color::White);       
        }
        dot[0].position = sf::Vector2f(dot[0].position.x + dx, dot[0].position.y + dy);
        sprite.setPosition(sf::Vector2f(dot[0].position.x - (faustoW / 2), dot[0].position.y - (faustoH / 2)));
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            win.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            dot[0].position = sf::Vector2f(sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y);            
        }
    }    
}