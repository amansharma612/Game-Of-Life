#include <iostream>
#include <SFML/Graphics.hpp>
#include "window.h"
#include <unistd.h>
#include <chrono>
#include <thread>


#define GAME_SIZE 100
#define WINDOW_WIDTH 500

int main (int argc, char * argv[]){
    int godNum = atoi(argv[1]);
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_WIDTH), "Conway's game of life");
    ConwayGame game(100, godNum);
    WindowRender renderer1;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        renderer1.render(window, game);
        window.draw(renderer1);
        game.updatePositions();
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    }

    return 0;

}