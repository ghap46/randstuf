#include <iostream>
#include <SFML/Graphics.hpp>
int main()
{
    const unsigned int W = 512;
    const unsigned int H = 512;
    const unsigned int l = 32;
    const unsigned int Mx = 64;
    const unsigned int My = 64;
    sf::RenderWindow win(sf::VideoMode(W, H), "Chess Board", sf::Style::Close | sf::Style::Titlebar);
    sf::VertexArray squares(sf::Quads, 4 * 64);
    for(int i = 0; i < 4; ++i)
    {
        squares[i].color = sf::Color::Black;
    }
    squares[0].position = sf::Vector2f(Mx, My);
    squares[1].position = sf::Vector2f(Mx + l, My);
    squares[2].position = sf::Vector2f(Mx + l, My + l);
    squares[3].position = sf::Vector2f(Mx, My + l);
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
        win.draw(squares);
        win.display();
    }
}