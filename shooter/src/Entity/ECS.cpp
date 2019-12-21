#include "Entity/ECS.h"
#include <cassert>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Entity/Components/SpriteComponent.h"
#include "Entity/Systems/System.h"


/************************************************************************//**
*   @brief  Constructor
***************************************************************************/
ECS::ECS()
{
    //ctor
}


/************************************************************************//**
*   @brief  This method determines if an entity is currently in the system.
*   @param  The entity id.
*   @return True if the entity is in the system.
***************************************************************************/
bool ECS::hasEntity(const int &entity) const
{
    if(entities.find(entity) != entities.end())
        return true;

    return false;
}


/************************************************************************//**
*   @brief  Add a new entity to the system.
*   @param  The entity id.
*   @return True if the entity was added to the system.
***************************************************************************/
bool ECS::addEntity(const int &entity)
{
    if(hasEntity(entity))
        return false;

    auto val = entities.insert(std::make_pair<int, ComponentSet>(static_cast<int>(entity), ComponentSet()));


    return val.second;
}


/************************************************************************//**
*   @brief  Remove an entity from the system.
*   @param  The entity id.
***************************************************************************/
void ECS::removeEntity(const int &entity)
{
    assert(hasEntity(entity));
    entities.erase(entity);
}


/************************************************************************//**
*   @brief  This method gets a set of components associated with the entity.
*   @param  The entity id.
*   @return A set of components for the entity.
***************************************************************************/
ComponentSet ECS::getComponents(const int &entity) const
{
    assert(hasEntity(entity));
    auto val = entities.find(entity);

    return val->second;
}


/************************************************************************//**
*   @brief  This method associates a component with an entity.
*   @param  The entity id.
*   @param  A pointer to the component to be added.
***************************************************************************/
void ECS::addComponent(const int &entity, std::shared_ptr<Component> comp)
{
    assert(hasEntity(entity));
    auto val = entities.find(entity);

    if(!val->second.hasComponent(static_cast<ComponentType>(comp->type)))
    {
        val->second.addComponent(comp);
    }

}


/************************************************************************//**
*   @brief  This method removes a component associated with the given entity.
*   @param  The entity id.
*   @param  The component type.
***************************************************************************/
void ECS::removeComponent(const int &entity, ComponentType &type)
{
    assert(hasEntity(entity));
    auto iter = entities.find(entity);
    assert(iter->second.hasComponent(type));
    iter->second.removeComponent(type);
}


/************************************************************************//**
*   @brief  This method determines if an entity is currently in the system.
*   @param  The entity id.
***************************************************************************/
void ECS::addSystem(std::shared_ptr<System> system)
{
    systems.push_back(system);
}


/************************************************************************//**
*   @brief  This method runs all the systems.
*   @param  A reference to the game engin.
*   @param  Deltatime is the lenght of time each frame takes.
***************************************************************************/
void ECS::update(GU::Engin::Engin& engin, const float &deltaTime)
{
    for(std::size_t i = 0; i < systems.size(); ++i)
    {
        systems[i]->update(engin, deltaTime, *this);
    }
}


/************************************************************************//**
*   @brief  This method draws all entities to the window.
*   @param  The window where the entities will be drawn.
*   @param  Properties used to draw the entities.
***************************************************************************/
void ECS::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto it = entities.begin(); it  != entities.end(); ++it)
    {
        ComponentSet set = getComponents(it->first);
        if(set.hasComponent(ComponentType::SPRITE))
        {
            std::shared_ptr<Component> comp = set.getComponent(ComponentType::SPRITE);
            std::shared_ptr<SpriteComponent> sComp = std::dynamic_pointer_cast<SpriteComponent>(comp);

            target.draw(*sComp);
        }
    }
}


/************************************************************************//**
*   @brief  Destructor
***************************************************************************/
ECS::~ECS()
{
    //dtor
}
