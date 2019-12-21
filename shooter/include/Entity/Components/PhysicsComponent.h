#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "Entity/Components/Component.h"
#include <Box2D/Dynamics/b2Body.h>


/************************************************************************//**
*   @brief  This adds a Box2D physics body to an entity.
****************************************************************************/
class PhysicsComponent: public Component
{
    public:
        /************************************************************************//**
        *   @brief  Constructor.
        ****************************************************************************/
        PhysicsComponent();
        

        /************************************************************************//**
        *   @brief  Destructor.
        ****************************************************************************/
        virtual ~PhysicsComponent();


        b2Body *body = nullptr;
};

#endif // PHYSICSCOMPONENT_H
