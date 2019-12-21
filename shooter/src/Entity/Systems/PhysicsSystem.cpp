#include "Entity/Systems/PhysicsSystem.h"


/************************************************************************//**
*   @brief  Constructor
*   @param  Box2d world object.
***************************************************************************/
PhysicsSystem::PhysicsSystem(b2World &newWorld):
world(newWorld)
{
    //ctor
}


/************************************************************************//**
*   @brief  This method executes per frame logic
*   @param  A reference to the game engin.
*   @param  The time each frame takes.
***************************************************************************/
void PhysicsSystem::update(GU::Evt::Engin& engin, const float &deltaTime)
{

}


/************************************************************************//**
*   @brief  Destructor.
***************************************************************************/
PhysicsSystem::~PhysicsSystem()
{
    //dtor
}
