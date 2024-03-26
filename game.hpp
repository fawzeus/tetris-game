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
        void add_tile();
        void drawGrid();
        void play();
};

#endif