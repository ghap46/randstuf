#include <iostream>
#include <SFML/Graphics.hpp>
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
    sf::Color fg = sf::Color::Black;
    sf::Color bg = sf::Color::White;
    sf::RenderWindow win(sf::VideoMode(W, H), "Title", sf::Style::Close | sf::Style::Titlebar);
    sf::VertexArray cells(sf::Points, W * H);
    sf::Clock clk;
    for(int i = 0; i < W * H; ++i)
    {
        cells[i].color = bg;
    }
    for(int i = 0; i < W; ++i)
    {
        for(int j = 0; j < H; ++j)
        {
            cells[xyToNum(i, j, W)].position = sf::Vector2f(i, j);
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
        tics++;
        win.draw(cells);
        win.display();
        std::cout << "Tics per second -> " << (double)tics / clk.getElapsedTime().asSeconds() << std::endl;
    }
}