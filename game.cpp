#include"game.hpp"

Game::Game():window(sf::VideoMode(WIDTH,HEIGHT),"Tetris game"){
    tile.loadFromFile("images/tiles.png");
}

void Game::play(){
    //add_tile();
    sf::Clock clock;
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
                else if(event.key.code==sf::Keyboard::Up)
                    current_tile.rotate();
            }
        }
        if(clock.getElapsedTime().asSeconds()>0.7){
            current_tile.gravity(grid,new_tile);
            clock.restart();
        }
        window.clear();
        drawGrid();
        if(new_tile){
            new_tile=false;
            current_tile=Tile();
        }
        current_tile.draw(window);
        window.display();


    }
    sf::sleep(sf::milliseconds(10));
}
void Game::add_tile() {
    tiles.push_back(Tile(0,0));
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
    //draw tiles
    for(int i=0;i<NBHEIGHT;i++){
        for(int j=0;j<NBWIDTH;j++){
            sf::Sprite tile_image(tile);
            if(grid[i][j]){
                tile_image.setPosition(j*18,i*18);
                tile_image.setTextureRect(sf::IntRect(grid[i][j]-1,0,18,18));
                window.draw(tile_image);
            }
        }
    }
}