#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <unistd.h>
#include "tile.hpp"
class Game{
    private:
        Tile current_tile;
        sf::Texture tile;
        sf::RenderWindow window;
        bool new_tile=false;
        short grid[NBHEIGHT][NBWIDTH]={0};
    public:
        Game();
        void init();
        void drawGrid();
        void play();
        bool check_line_full(int i);
        void delete_line(int i);
        void update_grid();

};

#endif