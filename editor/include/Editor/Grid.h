#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp>

/****************************************************************************//**
*   @brief  This class is used to draw grid lines to the editor.
*   @author Wayne J Larson Jr.
*   @date   11/20/19
********************************************************************************/
class Grid: public sf::Drawable
{
    public:
        /****************************************************************************//**
        *   @brief  Constructor
        ********************************************************************************/
        Grid();


        /****************************************************************************//**
        *   @brief  Constructor
        *   @param  The width and height of the map.
        *   @param  The width and height of the tiles in the map.
        ********************************************************************************/
        Grid(const sf::Vector2f &newMapSize, const sf::Vector2f &newTileSize);


        /****************************************************************************//**
        *   @brief  Initialize the grid. Create the grid lines from map and tile
        *           dimensions.
        *   @param  The width and height of the map.
        *   @param  The width and height of the tiles in the map.
        ********************************************************************************/
        void init(const sf::Vector2f &newMapSize, const sf::Vector2f &newTileSize);


        /****************************************************************************//**
        *   @brief  Draw the grid lines to a target (window).
        *   @param  Where the grid lines will be drawn.
        *   @param  Properties used while drawing.
        ********************************************************************************/
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /****************************************************************************//**
        *   @brief  Destructor.
        ********************************************************************************/
        virtual ~Grid();
    private:
        sf::VertexArray lines;

};

#endif // GRID_H
