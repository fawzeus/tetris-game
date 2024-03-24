#include "tile.hpp"


Tile::Tile(double x, double y):x(x),y(y){
    tile.loadFromFile("images/tiles.png");
    tile_image.setTexture(tile);
    left=rand_choice();
    tile_image.setTextureRect(sf::IntRect(left,0,18,18));
    tile_image.setPosition(x,y);
    //tile_image.setOrigin(tile_image.getLocalBounds().width / 2, tile_image.getLocalBounds().height / 2); // Set origin to center of the bird image
}

Tile::Tile(const Tile &other){
    x=other.x;
    y=other.y;
    tile.loadFromFile("images/tiles.png");
    tile_image.setTexture(tile);
    left=other.left;
    tile_image.setTextureRect(sf::IntRect(left,0,18,18));
    tile_image.setPosition(x,y);
}
void Tile::draw(sf::RenderWindow &window){
    window.draw(tile_image);
}


int rand_choice(){
    srand(time(0));
    return rand()%8*18;
}
