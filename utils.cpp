#include "utils.hpp"
int rand_int(int a, int b){
    if (a==b) return a;
    srand(time(0));
    if(a>=0)return rand()%(b-a)+a;
    else{
        if (b>=0){
            return rand()%(b-a)+a;
        }
        else {
            a*=-1;
            b*=-1;
            return -1*rand()%(a-b)+b;
        }
    }
}

void drawSquareOutline(sf::RenderWindow& window, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& outlineColor, float outlineThickness)
{
    // Create the square shape
    sf::RectangleShape square(size);
    square.setPosition(position);
    square.setFillColor(sf::Color::Transparent);
    square.setOutlineColor(outlineColor);
    square.setOutlineThickness(outlineThickness);

    // Draw the square outline
    window.draw(square);
}