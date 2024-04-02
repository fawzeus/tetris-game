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
        int shape_number;
        sf::Texture tile;
        sf::Sprite tile_image;
        bool tile_grid[4][4]={false};
    public:
        Tile(double x = (NBWIDTH/2-1)*18,double y = -18*4);
        Tile(const Tile &other);
        Tile& operator=(const Tile &other);
        void draw(sf::RenderWindow &window); // draw the Tile
        void rotate(short grid[NBHEIGHT][NBWIDTH]); // rotate the tile
        double get_right(); 
        double get_left(); 
        double get_top();
        double get_bottom();
        void shift(); // shift the tile
        double get_x(); 
        double get_y();
        void move(Direction dir,short grid[NBHEIGHT][NBWIDTH]); // move tile to left and right
        bool check_for_dead_end(short grid[NBHEIGHT][NBWIDTH]); // check if there is a collusion
        void gravity(short grid[NBHEIGHT][NBWIDTH],bool &new_tile); // apply gravity
        void set_position(int indx,int indy);
        bool is_valide_move(short grid[NBHEIGHT][NBWIDTH]);
        bool is_valide_rotate(short grid[NBHEIGHT][NBWIDTH]);
};

int rand_choice();
#endif