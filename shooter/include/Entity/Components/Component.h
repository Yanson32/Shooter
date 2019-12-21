#ifndef COMPONENT_H
#define COMPONENT_H
#include "Entity/Components/ComponentType.h"


/************************************************************************//**
*   @brief  This is the base class for all components.
*   @date   12/20/2019
****************************************************************************/
class Component
{
    public:
        /************************************************************************//**
        *   @brief  Constructor.
        *   @param  The type of component.
        ****************************************************************************/
        Component(const int &newType);

        /************************************************************************//**
        *   @brief  Destructor.
        *   @param  The type of component.
        ****************************************************************************/
        virtual ~Component();


        const int type = -1;
};

#endif // COMPONENT_H
