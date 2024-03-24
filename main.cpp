#include "tile.hpp"
#include <unistd.h>

int main(){
   Tile t(0,0);
   sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"Snake Game");
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        t.draw(window);
        window.display();


    }
    usleep(100000);
}

