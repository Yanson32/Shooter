#include "Entity/Components/SpriteComponent.h"
#include "Entity/Components/ComponentType.h"


/************************************************************************//**
*   @brief  Constructor
****************************************************************************/
SpriteComponent::SpriteComponent():
Component(ComponentType::SPRITE)
{
    //ctor
}


/************************************************************************//**
*   @brief  This method draws the entity to a screen.
*   @param  The window where the entity will be drawn.
*   @param  Properties used to draw the entity.
****************************************************************************/
void SpriteComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite);
}


/************************************************************************//**
*   @brief  Destructor
****************************************************************************/
SpriteComponent::~SpriteComponent()
{
    //dtor
}
