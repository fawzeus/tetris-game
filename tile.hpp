#ifndef TILE_HPP
#define TILE_HPP
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "CONSTANTS.hpp"
class Tile{
    private:
        double x,y;
        int left;
        sf::Texture tile;
        sf::Sprite tile_image;
    public:
        Tile(double x,double y);
        Tile(const Tile &other);
        Tile& operator=(const Tile &other);
        void draw(sf::RenderWindow &window);
        void move();
};

int rand_choice();
#endif