#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "CONSTANTS.hpp"
class Tile{
    private:
        double x,y;
        sf::Texture tile;
        sf::Sprite tile_image;
    public:
        Tile(double x,double y);
        void draw(sf::RenderWindow &window);
        void Move();
};

int rand_choice();