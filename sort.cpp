#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <chrono>
unsigned int randomInt()
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ ((std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() + (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(0, 4294967295);
    return distrib(gen);    
}
int main()
{
    unsigned int W = 100;
    unsigned int H = 512;
    unsigned int arr[W];
    for(int i = 0; i < W; ++i)
    {
        arr[i] = randomInt() % W;
    }
    for(int i = 0; i < W; ++i)
    {
        for(int j = 1; j < W; ++j)
        {
            if(arr[i] == arr[j])
            {
                std::cout << "ARRI[" << i << "] = " << arr[i] << std::endl << "ARRJ[" << j << "] = " << arr[j] << std::endl << std::endl;
            }
        }
    }
    sf::RenderWindow win(sf::VideoMode(W, H), "Title", sf::Style::Close | sf::Style::Titlebar);
    sf::VertexArray bars(sf::Lines, W * 2);
    for(int i = 0; i < W; ++i)
    {
        bars[2 * i].position = sf::Vector2f(i, H - 1);
        bars[2 * i].color = sf::Color::Black;
    }
    for(int i = 0; i < W; ++i)
    {
        bars[2 * i + 1].position = sf::Vector2f(0, 0);
        bars[2 * i + 1].color = sf::Color::Black;
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
        win.clear(sf::Color::White);
        win.draw(bars);
        win.display();
    }
}