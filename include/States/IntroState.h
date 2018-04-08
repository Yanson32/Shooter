#ifndef INTROSTATE_H
#define INTROSTATE_H
#include "Engin/StateBase.h"

class IntroState: public StateBase
{
    public:
        IntroState();
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
                virtual void HandleEvents(GU::Engin::Engin& engin, const int &deltaTime);


                /*********************************************************************************//**
                *   \brief	This method handles input such as user input and events
                *	\param	engin is a reference to the game's Engin object.
                *************************************************************************************/
                virtual void Update(GU::Engin::Engin& engin, const int &deltaTime);


                /*********************************************************************************//**
                *   \brief	This method draws the current game state.
                *	\param	engin is a reference to the game's Engin object.
                *************************************************************************************/
                virtual void Draw(GU::Engin::Engin& engin, const int &deltaTime);
        virtual ~IntroState();
    protected:
    private:
        tgui::Button::Ptr startButton;
        tgui::Button::Ptr optionButton;
        tgui::Button::Ptr multiplayerButton;
        void onStartPressed();
        void onMultiplayerPressed();
        void onOptionsPressed();

};

#endif // INTROSTATE_H
