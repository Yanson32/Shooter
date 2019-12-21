#ifndef DRAWINGSYSTEM_H
#define DRAWINGSYSTEM_H
#include "Entity/Systems/System.h"


/************************************************************************//**
*   @brief  This class updates the sprite component so the sprite is on
*           top of the body.
*   @date   12/20/2019
***************************************************************************/
class DrawingSystem: public System
{
    public:
        /************************************************************************//**
        *   @brief  Constructor
        ****************************************************************************/
        DrawingSystem();


        /************************************************************************//**
        *   @brief  This method updates the per frame logic.
        *   @param  A reference to the game engin.
        *   @param  Deltatime is the time each frame of the game takes.
        ****************************************************************************/
        virtual void update(GU::Engin::Engin& engin, const float &deltaTime, ECS &ecs) override;


        /************************************************************************//**
        *   @brief  Destructor.
        ****************************************************************************/
        virtual ~DrawingSystem();
};

#endif // DRAWINGSYSTEM_H
