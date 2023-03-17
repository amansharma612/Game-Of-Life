#ifndef CONWAY
#define CONWAY
#include "ConwayGame.h"
#endif
#include <SFML/Graphics.hpp>
#include <vector>

class WindowRender : public sf::Drawable, public sf::Transformable 
{
    public:
        
        void render(sf::RenderWindow& window, ConwayGame &world);


    private:
        
        sf::VertexArray m_vertices;
        virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    
};