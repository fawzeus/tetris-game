#include"game.hpp"

Game::Game():window(sf::VideoMode(WIDTH,HEIGHT),"Tetris game"){}

void Game::play(){
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        add_tile();
        draw_tiles();
        window.display();


    }
    usleep(100000);
}
void Game::add_tile() {
    tiles.push_back(Tile(0,0));
}

void Game::draw_tiles(){
    for(auto tile=tiles.begin();tile!=tiles.end();tile++){
        tile->draw(window);
    }
}