#include "Editor/Grid.h"


/****************************************************************************//**
*   @brief  Constructor
********************************************************************************/
Grid::Grid()
{

}


/****************************************************************************//**
*   @brief  Constructor
*   @param  The width and height of the map.
*   @param  The width and height of the tiles in the map.
********************************************************************************/
Grid::Grid(const sf::Vector2f &newMapSize, const sf::Vector2f &newTileSize)
{
    //ctor
    this->init(newMapSize, newTileSize);
}


/****************************************************************************//**
*   @brief  Initialize the grid. Create the grid lines from map and tile
*           dimensions.
*   @param  The width and height of the map.
*   @param  The width and height of the tiles in the map.
********************************************************************************/
void Grid::init(const sf::Vector2f &newMapSize, const sf::Vector2f &newTileSize)
{
    lines.clear();
    lines.setPrimitiveType(sf::Lines);

    //Build vertical lines
    for(std::size_t i = 0; i < newMapSize.x; i += newTileSize.x)
    {
        sf::Vertex vertTop;
        vertTop.position = sf::Vector2f(i, 0);
        vertTop.color = sf::Color::White;
        lines.append(vertTop);

        sf::Vertex vertBottom;
        vertBottom.position = sf::Vector2f(i, newMapSize.y);
        vertBottom.color = sf::Color::White;
        lines.append(vertBottom);

    }

    //Build horizontal lines
    for(std::size_t i = 0; i < newMapSize.y; i += newTileSize.y)
    {
        sf::Vertex vertLeft;
        vertLeft.position = sf::Vector2f(0, i);
        vertLeft.color = sf::Color::White;
        lines.append(vertLeft);

        sf::Vertex vertRight;
        vertRight.position = sf::Vector2f(newMapSize.x, i);
        vertRight.color = sf::Color::White;
        lines.append(vertRight);

    }
}


/****************************************************************************//**
*   @brief  Draw the grid lines to a target (window).
*   @param  Where the grid lines will be drawn.
*   @param  Properties used while drawing.
********************************************************************************/
void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(lines);
}


/****************************************************************************//**
*   @brief  Destructor.
********************************************************************************/
Grid::~Grid()
{
    //dtor
}
