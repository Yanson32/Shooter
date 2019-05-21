#ifndef SHOOTER_MAPCREATORSTATE_H
#define SHOOTER_MAPCREATORSTATE_H
#include "States/StateBase.h"
#include "MapCreatorPanel.h"

class MapCreatorState: public StateBase
{
    public:
        MapCreatorState(sf::RenderWindow &newWindow, tgui::Gui &newGui);
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
        std::shared_ptr<MapCreatorPanel> panel;
        tgui::Button::Ptr collapseButton;
        void onCollapsePressed();
        sf::Clock collapseTimer;
};

#endif // SHOOTER_MAPCREATORSTATE_H
