#include "tile.hpp"


Tile::Tile(double x, double y):x(x),y(y){
    tile.loadFromFile("images/tiles.png");
    tile_image.setTexture(tile);
    left=rand_choice();
    tile_image.setTextureRect(sf::IntRect(left,0,18,18));
    //tile_image.setPosition(x,y);
    std::vector<std::pair<int,int>> shape=shapes[rand_int(0,7)];
    for(auto it=shape.begin();it!=shape.end();it++){
        tile_grid[it->first][it->second]=true;
    }
}

Tile::Tile(const Tile &other){
    x=other.x;
    y=other.y;
    tile.loadFromFile("images/tiles.png");
    tile_image.setTexture(tile);
    left=other.left;
    tile_image.setTextureRect(sf::IntRect(left,0,18,18));
    //tile_image.setPosition(x,y);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tile_grid[i][j]=other.tile_grid[i][j];
        }
    }

}
void Tile::draw(sf::RenderWindow &window){
    double posx=x,posy=y;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tile_grid[i][j]){
                tile_image.setPosition(posx,posy);
                window.draw(tile_image);
            }
            posy+=18;
        }
        posy=y;
        posx+=18;
    }
    //window.draw(tile_image);
}


int rand_choice(){
    srand(time(0));
    return rand()%8*18;
}
