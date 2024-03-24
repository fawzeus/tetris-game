#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <unistd.h>
#include "tile.hpp"
class Game{
    private:
        std:: vector<Tile> tiles;
        sf::RenderWindow window;
    public:
        Game();
        void init();
        void add_tile();
        void draw_tiles();
        void play();
};

#endif