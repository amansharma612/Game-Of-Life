#include <SFML/Graphics.hpp>

class Cell
{
    public:
        Cell(sf::Vector2i position, sf::Color color);
        
        sf::Vector2i position;
        sf::Color color;

};