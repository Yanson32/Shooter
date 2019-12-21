#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <Box2D/Dynamics/b2World.h>
#include "Entity/Systems/System.h"


/************************************************************************//**
*   @brief  This system updates the entities physics
*   @date   12/20/2019
***************************************************************************/
class PhysicsSystem: public System
{
    public:
        /************************************************************************//**
        *   @brief  Constructor
        *   @param  Box2d world object.
        ***************************************************************************/
        PhysicsSystem(b2World &newWorld);


        /************************************************************************//**
        *   @brief  This method executes per frame logic
        *   @param  A reference to the game engin.
        *   @param  The time each frame takes.
        ***************************************************************************/
        virtual void update(GU::Evt::Engin& engin, const float &deltaTime);


        /************************************************************************//**
        *   @brief  Destructor.
        ***************************************************************************/
        virtual ~PhysicsSystem();


        b2World &world;
        
};

#endif // PHYSICSSYSTEM_H
