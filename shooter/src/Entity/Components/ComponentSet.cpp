#include "Entity/Components/ComponentSet.h"
#include <cassert>


/************************************************************************//**
*   @brief  This method determines if a component is in the set.
*   @param  The type of component.
*   @return True is returned if the component exists in the set.
***************************************************************************/
bool ComponentSet::hasComponent(const ComponentType &type) const
{
    if(components.find(type) != components.end())
        return true;

    return false;
}


/************************************************************************//**
*   @brief  This method adds a component to the set.
*   @param  A shared pointer to the component to be added.
***************************************************************************/
void ComponentSet::addComponent(std::shared_ptr<Component> comp)
{
    assert(!hasComponent(static_cast<ComponentType>(comp->type)));
    components[static_cast<ComponentType>(comp->type)] = comp;
}


/************************************************************************//**
*   @brief  This method removes a component from the set.
*   @param  The type of component.
*   @pre    The component should have already been added to the set.
***************************************************************************/
void ComponentSet::removeComponent(const ComponentType &type)
{
    assert(hasComponent(type));
    components.erase(type);
}


/************************************************************************//**
*   @brief  This method gets a component previously added to the set.
*   @param  The type of component.
*   @pre    The component should have been previously added to the set.
*   @return A pointer to the component.
***************************************************************************/
std::shared_ptr<Component> ComponentSet::getComponent(const ComponentType &type) const
{
    assert(hasComponent(type));
    for(auto it = components.begin(); it != components.end(); ++it)
    {
        if(it->first == type)
            return it->second;
    }
}

