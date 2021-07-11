#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
unsigned int randomint()
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ ((std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() + (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(0, 4294967295);
    return distrib(gen);    
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
    const unsigned int W = 512;
    const unsigned int H = 512;
    unsigned int xCoord = randomint() % W;
    unsigned int yCoord = randomint() % H;
    unsigned int ranDir = randomint() % 4;
    sf::RenderWindow win(sf::VideoMode(W, H), "Title", sf::Style::Titlebar | sf::Style::Close);
    sf::VertexArray point(sf::Points, W * H);
    for(int i = 0; i < W; ++i)
    {
        for(int j = 0; j < H; ++j)
        {
            point[xyToNum(i, j, W)].position = sf::Vector2f(i, j);
            point[xyToNum(i, j, W)].color = sf::Color::White;
        }
    }
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
        win.draw(point);
        win.display();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            for(int i = 0; i < W; ++i)
            {
                for(int j = 0; j < H; ++j)
                {
                    point[xyToNum(i, j, W)].color = sf::Color::White;
                }
            }
            xCoord = randomint() % W;
            yCoord = randomint() % H;     
        }
        point[xyToNum(xCoord, yCoord, W)].color = sf::Color::Black;
        switch (ranDir)
        {
            case UP:
                if(yCoord == 0/* || point[xyToNum(xCoord, yCoord - 1, W)].color == sf::Color::Black*/)
                {
                    ranDir = randomint() % 4;
                }
                else
                {
                    --yCoord;
                }
                break;
            case RIGHT:
                if(xCoord == W - 1/* || point[xyToNum(xCoord + 1, yCoord, W)].color == sf::Color::Black*/)
                {
                    ranDir = randomint() % 4;
                }
                else
                {
                    ++xCoord;
                }
                break;
            case DOWN:
                if(yCoord == H - 1/* || point[xyToNum(xCoord, yCoord + 1, W)].color == sf::Color::Black*/)
                {
                    ranDir = randomint() % 4;
                }
                else
                {
                    ++yCoord;
                }
                break;
            case LEFT:
                if(xCoord == 0/* || point[xyToNum(xCoord - 1, yCoord, W)].color == sf::Color::Black*/)
                {
                    ranDir = randomint() % 4;
                }
                else
                {
                    --xCoord;
                }
                break;
        }
        ranDir = randomint() % 4;
    }
}