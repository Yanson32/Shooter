#include "Entity/Systems/DrawingSystem.h"
#include "Entity/ECS.h"
#include <cassert>
#include "Entity/Components/PhysicsComponent.h"
#include "Entity/Components/SpriteComponent.h"
#include "Functions.h"


/************************************************************************//**
*   @brief  Constructor
****************************************************************************/
DrawingSystem::DrawingSystem()
{
    //ctor
}


/************************************************************************//**
*   @brief  This method updates the per frame logic.
*   @param  A reference to the game engin.
*   @param  Deltatime is the time each frame of the game takes.
****************************************************************************/
void DrawingSystem::update(GU::Engin::Engin& engin, const float &deltaTime, ECS &ecs)
{

    for(auto it = entities.begin(); it != entities.end(); ++it)
    {
        assert(ecs.hasEntity(*it));
        ComponentSet set = ecs.getComponents(*it);
        assert(set.hasComponent(ComponentType::PHYSICS));
        assert(set.hasComponent(ComponentType::SPRITE));
        std::shared_ptr<PhysicsComponent> pComp = std::dynamic_pointer_cast<PhysicsComponent>(set.getComponent(ComponentType::PHYSICS));
        std::shared_ptr<SpriteComponent> sComp = std::dynamic_pointer_cast<SpriteComponent>(set.getComponent(ComponentType::SPRITE));
        sf::Vector2f position = toPixles(pComp->body->GetPosition());
        sComp->sprite.setPosition(position);
    }
}


/************************************************************************//**
*   @brief  Destructor.
****************************************************************************/
DrawingSystem::~DrawingSystem()
{
    //dtor
}
