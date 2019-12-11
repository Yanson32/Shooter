#ifndef SHOOTER_MAPCREATORSTATE_H
#define SHOOTER_MAPCREATORSTATE_H
#include "Editor/MapCreatorPanel.h"
#include "Editor/Editor.h"
#include "Editor/Grid.h"
#include "States/PlayState.h"
#include "Editor/MapCreatorPanel.h"

class MapCreatorState: public PlayState
{
    public:
        MapCreatorState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap);
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

        virtual void handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event) override;

        virtual ~MapCreatorState();
    protected:
    private:
        std::shared_ptr<Editor> panel;
        sf::Clock collapseTimer;
        Grid grid;
};

#endif // SHOOTER_MAPCREATORSTATE_H
