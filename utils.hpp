#ifndef UTILS_HPP
#define UTILS_HPP
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <SFML/Graphics.hpp>
void drawSquareOutline(sf::RenderWindow& window, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& outlineColor, float outlineThickness);
int rand_int(int a, int b);
#endif