#ifndef TILE_HPP
#define TILE_HPP
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "utils.hpp"
#include "CONSTANTS.hpp"
class Tile{
    private:
        double x,y;
        int left;
        sf::Texture tile;
        sf::Sprite tile_image;
        bool tile_grid[4][4]={false};
    public:
        Tile(double x = 0,double y = 0);
        Tile(const Tile &other);
        Tile& operator=(const Tile &other);
        void draw(sf::RenderWindow &window);
        void rotate();
        double get_right();
        double get_left();
        double get_top();
        double get_buttom();
        void shift();
        void move(Direction dir);
};

int rand_choice();
#endif