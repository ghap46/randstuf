// Highly inefficient code ahead, close your eyes.
// Still need to fix the segmentation fault at the end.
#include <iostream>
#include <SFML/Graphics.hpp>
#define UP 0                //I know what you're thinking.
#define RIGHT 1
#define DOWN 2
#define LEFT 3
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
    unsigned int xCoord = W / 2;
    unsigned int yCoord = H / 2;
    unsigned int tics = 0;
    int dir = UP;
    bool arr[W][H];
    for(int i = 0; i < W; ++i)
    {
        for(int j = 0; j < H; ++j)
        {
            arr[W][H] = false;
        }
    }
    sf::Clock clk;
    sf::Color fg = sf::Color::Black;
    sf::Color bg = sf::Color::White;
    sf::RenderWindow win(sf::VideoMode(W, H), "Title", sf::Style::Close | sf::Style::Titlebar);
    sf::VertexArray ants(sf::Points, W * H);
    for(int i = 0; i < W * H; ++i)
    {
        ants[i].color = bg;
    }
    for(int i = 0; i < W; ++i)
    {
        for(int j = 0; j < H; ++j)
        {
            ants[xyToNum(i, j, W)].position = sf::Vector2f(i, j);
        }
    }
    ants[xyToNum(xCoord, yCoord, W)].position = sf::Vector2f(xCoord, yCoord);
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
        win.draw(ants);
        win.display();
        if(arr[xCoord][yCoord] == false)
        {
            dir = (dir + 1) % 4;
            arr[xCoord][yCoord] = true;
            ants[xyToNum(xCoord, yCoord, W)].color = fg;
            if(dir == UP)
            {
                yCoord -= 1;
            }
            if(dir == RIGHT)
            {
                xCoord += 1;
            }
            if(dir == DOWN)
            {
                yCoord += 1;
            }
            if(dir == LEFT)
            {
                xCoord -= 1;
            }
            ants[xyToNum(xCoord, yCoord, W)].position = sf::Vector2f(xCoord, yCoord);            
        }
        if(arr[xCoord][yCoord] == true)
        {
            dir = (dir + 3) % 4;
            arr[xCoord][yCoord] = false;
            ants[xyToNum(xCoord, yCoord, W)].color = bg;
            if(dir == UP)
            {
                yCoord -= 1;
            }
            if(dir == RIGHT)
            {
                xCoord += 1;
            }
            if(dir == DOWN)
            {
                yCoord += 1;
            }
            if(dir == LEFT)
            {
                xCoord -= 1;
            }
            ants[xyToNum(xCoord, yCoord, W)].position = sf::Vector2f(xCoord, yCoord);            
        }
        tics++;
        std::cout << "Tics per second -> " << (double)tics / clk.getElapsedTime().asSeconds() << std::endl;
    }
}