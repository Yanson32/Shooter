#ifndef SHOOTER_PLAYSTATE_H
#define SHOOTER_PLAYSTATE_H
#include "Engin/StateBase.h"

class PlayState: public StateBase
{
    public:
        PlayState();

        /*********************************************************************************//**
        *   \brief	Initialize the game state.
        *************************************************************************************/
        virtual void Init() override;

        /*********************************************************************************//**
        *   \brief	Clean any resource the state uses
        *************************************************************************************/
        virtual void Clean() override;

        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void HandleEvents(GU::Engin::Engin& engin, const int &deltaTime) override;


        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void Update(GU::Engin::Engin& engin, const int &deltaTime) override;


        /*********************************************************************************//**
        *   \brief	This method draws the current game state.
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void Draw(GU::Engin::Engin& engin, const int &deltaTime) override;
        virtual ~PlayState();
    protected:
    private:
};

#endif // SHOOTER_PLAYSTATE_H
