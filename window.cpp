#include "window.h"

void WindowRender::render(sf::RenderWindow& window, ConwayGame &world){
    sf::Vector2f dim(5.0f, 5.0f);
    m_vertices.clear();
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(world.gameSize * world.gameSize * 4);

    for (int i = 0; i < world.gameSize; i++)
    {
        for (int j = 0; j < world.gameSize; j++)
        {
            int value = world.boardPosition[i * world.gameSize + j];

            sf::Vertex * quad = &m_vertices[(i*world.gameSize + j) * 4];
            
            quad[0].position = sf::Vector2f(i * dim.x, j * dim.y);
            quad[1].position = sf::Vector2f((i + 1) * dim.x, j * dim.y);
            quad[2].position = sf::Vector2f((i + 1) * dim.x, (j + 1) * dim.y);
            quad[3].position = sf::Vector2f((i) * dim.x, (j + 1) * dim.y);

            if (value) {
                quad[0].color = sf::Color::Black;
                quad[1].color = sf::Color::Black;
                quad[2].color = sf::Color::Black;
                quad[3].color = sf::Color::Black;
            } else {
                quad[0].color = sf::Color::White;
                quad[1].color = sf::Color::White;
                quad[2].color = sf::Color::White;
                quad[3].color = sf::Color::White;
            }
        }
    }


}

void WindowRender::draw(sf::RenderTarget & target, sf::RenderStates states)  const{
    target.draw(m_vertices, states);
}