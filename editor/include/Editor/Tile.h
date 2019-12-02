#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/String.hpp>
class Tile: public sf::Drawable
{
    public:
        Tile();
        sf::Vector2f position;
        sf::Vector2f size;
        sf::String image;
        sf::Vector2f imagePosition;
        sf::Vector2f imageDimensions;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual ~Tile();

    protected:

    private:
};

#endif // TILE_H
