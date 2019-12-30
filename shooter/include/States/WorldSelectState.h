#ifndef WORLDSELECTSTATE_H
#define WORLDSELECTSTATE_H
#include "StateBase.h"
#include "States/Id.h"
class Engin;

class WorldSelectState: public StateBase
{
    public:
        WorldSelectState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap, const int &newId = States::Id::WORLD_SELECT_STATE);
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
        virtual void HandleEvents(GU::Engin::Engin& engin, const float &deltaTime) override;


        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void Update(GU::Engin::Engin& engin, const float &deltaTime) override;


        /*********************************************************************************//**
        *   \brief	This method draws the current game state.
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void Draw(GU::Engin::Engin& engin, const float &deltaTime) override;


        virtual void handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event) override;


        virtual ~WorldSelectState();

    protected:

    private:
        tgui::Label::Ptr currentWorldLabel;
};

#endif // WORLDSELECTSTATE_H
