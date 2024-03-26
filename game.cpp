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
                else if(event.key.code==sf::Keyboard::Down)
                    delay/=2;
                
            }
            else if(event.type == sf::Event::KeyReleased){
                if(event.key.code==sf::Keyboard::Down)
                    delay*=2;
            }
        }
        if(clock.getElapsedTime().asSeconds()>delay){
            current_tile.gravity(grid,new_tile);
            clock.restart();
        }
        window.clear();
        drawGrid();
        if(new_tile){
            new_tile=false;
            update_grid();
            current_tile=Tile();
        }
        current_tile.draw(window);
        window.display();


    }
    sf::sleep(sf::milliseconds(10));
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

bool Game::check_line_full(int i){
    for(int j=0;j<NBWIDTH;j++){
        if (!grid[i][j]) return false;
    }
    return true;
}
void Game::delete_line(int i){
    for(int indy=i;indy>1;indy--){
        for(int indx=0;indx<NBWIDTH;indx++){
            grid[indy][indx]=grid[indy-1][indx];
        }
    }
    for(int j=0;j<NBWIDTH;j++){
        grid[0][j]=0;
    }
}
void Game::update_grid(){
    for(int i=0;i<NBHEIGHT;i++){
        if(check_line_full(i))
            delete_line(i);
    }
}