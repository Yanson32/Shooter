#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Entity/Components/Component.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


/************************************************************************//**
*   @brief  This class adds the ability for an entity to be drawn to a
*           screen.
*   @date   12/20/2019
***************************************************************************/
class SpriteComponent : public Component, public sf::Drawable
{
    public:
        /************************************************************************//**
        *   @brief  Constructor
        ****************************************************************************/
        SpriteComponent();


        /************************************************************************//**
        *   @brief  This method draws the entity to a screen.
        *   @param  The window where the entity will be drawn.
        *   @param  Properties used to draw the entity.
        ****************************************************************************/
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /************************************************************************//**
        *   @brief  Destructor
        ****************************************************************************/
        virtual ~SpriteComponent();

        sf::Sprite sprite;
};

#endif // SPRITECOMPONENT_H
