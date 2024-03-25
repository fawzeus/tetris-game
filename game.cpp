#include"game.hpp"

Game::Game():window(sf::VideoMode(WIDTH,HEIGHT),"Tetris game"){}

void Game::play(){
    //add_tile();
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed){ 
                if(event.key.code==sf::Keyboard::Left)
                    current_tile.move(Direction::Left);
                else if(event.key.code==sf::Keyboard::Right)
                    current_tile.move(Direction::Right);
            }
        }
        window.clear();
        drawGrid();
        current_tile.draw(window);
        draw_tiles();
        window.display();


    }
    sf::sleep(sf::milliseconds(10));
}
void Game::add_tile() {
    tiles.push_back(Tile(0,0));
}

void Game::draw_tiles(){
    for(auto tile=tiles.begin();tile!=tiles.end();tile++){
        tile->draw(window);
    }
}

void Game::drawGrid() {
    // Draw vertical lines
    for (int i = 0; i <= NBWIDTH; ++i) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(i * 18, 0)),
            sf::Vertex(sf::Vector2f(i * 18, NBHEIGHT * 18))
        };
        window.draw(line, 2, sf::Lines);
    }

    // Draw horizontal lines
    for (int j = 0; j <= NBHEIGHT; ++j) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, j * 18)),
            sf::Vertex(sf::Vector2f(NBWIDTH * 18, j * 18))
        };
        window.draw(line, 2, sf::Lines);
    }
}