#ifndef INTROSTATE_H
#define INTROSTATE_H
#include "States/StateBase.h"
#include "Editor/PanelBase.h"
#include "Gui/id.h"
#include <Box2D/Dynamics/b2World.h>

class IntroState: public StateBase
{
    public:
        IntroState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw);
                /*********************************************************************************//**
                *   \brief	Initialize the game state.
                *************************************************************************************/
                virtual void Init();

                /*********************************************************************************//**
                *   \brief	Clean any resource the state uses
                *************************************************************************************/
                virtual void Clean();

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

                void handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event);
        virtual ~IntroState();
    protected:
    private:
//        tgui::Button::Ptr startButton;
//        tgui::Button::Ptr optionButton;
//        tgui::Button::Ptr multiplayerButton;
//        tgui::Button::Ptr mapButton;

//        void onStartPressed();
//        void onMultiplayerPressed();
//        void onOptionsPressed();
//        void onMapPressed();
            Gui::id panelId = Gui::id::INTRO;

};

#endif // INTROSTATE_H
