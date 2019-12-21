#ifndef ENTITY_H
#define ENTITY_H
#include "Entity/Components/ComponentSet.h"
#include <unordered_map>
#include <SFML/Graphics/Drawable.hpp>
#include <GameUtilities/Engin/Engin.h>
#include <vector>
class System;

/************************************************************************//**
*   @brief  This is the main class for the Entity Component System.
*           This class keeps track of all entities and their systems.
*   @date   12/20/2019
*   @author Wayn J Larson Jr.
***************************************************************************/
class ECS: public sf::Drawable
{
    public:
        /************************************************************************//**
        *   @brief  Constructor
        ***************************************************************************/
        ECS();


        /************************************************************************//**
        *   @brief  This method determines if an entity is currently in the system.
        *   @param  The entity id.
        *   @return True if the entity is in the system.
        ***************************************************************************/
        bool hasEntity(const int &entity) const;


        /************************************************************************//**
        *   @brief  Add a new entity to the system.
        *   @param  The entity id.
        *   @return True if the entity was added to the system.
        ***************************************************************************/
        bool addEntity(const int &entity);


        /************************************************************************//**
        *   @brief  Remove an entity from the system.
        *   @param  The entity id.
        ***************************************************************************/
        void removeEntity(const int &entity);


        /************************************************************************//**
        *   @brief  This method gets a set of components associated with the entity.
        *   @param  The entity id.
        *   @return A set of components for the entity.
        ***************************************************************************/
        ComponentSet getComponents(const int &entity) const;


        /************************************************************************//**
        *   @brief  This method associates a component with an entity.
        *   @param  The entity id.
        *   @param  A pointer to the component to be added.
        ***************************************************************************/
        void addComponent(const int &entity, std::shared_ptr<Component> comp);


        /************************************************************************//**
        *   @brief  This method removes a component associated with the given entity.
        *   @param  The entity id.
        *   @param  The component type.
        ***************************************************************************/
        void removeComponent(const int &entity, ComponentType &type);


        /************************************************************************//**
        *   @brief  This method determines if an entity is currently in the system.
        *   @param  The entity id.
        ***************************************************************************/
        void addSystem(std::shared_ptr<System> system);


        /************************************************************************//**
        *   @brief  This method runs all the systems.
        *   @param  A reference to the game engin.
        *   @param  Deltatime is the lenght of time each frame takes.
        ***************************************************************************/
        void update(GU::Engin::Engin& engin, const float &deltaTime);


        /************************************************************************//**
        *   @brief  This method draws all entities to the window.
        *   @param  The window where the entities will be drawn.
        *   @param  Properties used to draw the entities.
        ***************************************************************************/
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /************************************************************************//**
        *   @brief  Destructor
        ***************************************************************************/
        virtual ~ECS();

    private:
        std::unordered_map<int, ComponentSet> entities;
        std::vector<std::shared_ptr<System>> systems;
};

#endif // ENTITY_H
