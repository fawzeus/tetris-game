#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <unistd.h>
#include "tile.hpp"
class Game{
    private:
        Tile current_tile;
        Tile next_tile;
        sf::Texture tile;
        sf::RenderWindow window;
        bool new_tile=false;
        short grid[NBHEIGHT][NBWIDTH]={0};
        double delay = 0.7;
    public:
        Game(); 
        void init(); //initialize the game
        void drawGrid(); //draw the grid and the tiles
        void play();// the Game loop
        bool check_line_full(int i); // check if line i is full
        void delete_line(int i); // delete line(i);
        void update_grid(); // update grid if there is a full lines;
        bool game_over(); //check for game over

};

#endif