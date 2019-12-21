#ifndef COMPONENTSET_H
#define COMPONENTSET_H
#include "Entity/Components/Component.h"
#include "Entity/Components/ComponentType.h"
#include <unordered_map>
#include <memory>


/************************************************************************//**
*   @brief  This class stores a vector of components.
*   @date   12/20/2019
***************************************************************************/
class ComponentSet
{
    public:
        /************************************************************************//**
        *   @brief  This method determines if a component is in the set.
        *   @param  The type of component.
        *   @return True is returned if the component exists in the set.
        ***************************************************************************/
        bool hasComponent(const ComponentType &type) const;


        /************************************************************************//**
        *   @brief  This method adds a component to the set.
        *   @param  A shared pointer to the component to be added.
        ***************************************************************************/
        void addComponent(std::shared_ptr<Component> comp);


        /************************************************************************//**
        *   @brief  This method removes a component from the set.
        *   @param  The type of component.
        *   @pre    The component should have already been added to the set.
        ***************************************************************************/
        void removeComponent(const ComponentType &type);


        /************************************************************************//**
        *   @brief  This method gets a component previously added to the set.
        *   @param  The type of component.
        *   @pre    The component should have been previously added to the set.
        *   @return A pointer to the component.
        ***************************************************************************/
        std::shared_ptr<Component> getComponent(const ComponentType &type) const;


        std::unordered_map<ComponentType, std::shared_ptr<Component>> components;
};

#endif // COMPONENTSET_H
