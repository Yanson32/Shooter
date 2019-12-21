#ifndef SYSTEM_H
#define SYSTEM_H
#include <GameUtilities/Engin/Engin.h>
#include <GameUtilities/Event/Event.h>
#include <set>
class ECS;


/************************************************************************//**
*   @brief  This the base class for all systems.
*   @date   12/20/2019
*   @author Wayne J Larson Jr.
***************************************************************************/
class System
{
    public:
        /************************************************************************//**
        *   @brief  This method executes the per fram logic.
        *   @param  A reference to the game engin.
        *   @param  The time each frame takes.
        *   @param  A reference to the Entity Component System.
        ***************************************************************************/
        virtual void update(GU::Engin::Engin& engin, const float &deltaTime, ECS &ecs) = 0;


        /************************************************************************//**
        *   @brief  This method adds an entity to the list of entities associated
        *           with this system.
        *   @param  The id of the entity.
        ***************************************************************************/
        void registerEntity(const int &entity);
    protected:

        std::set<int> entities;
};
#endif
