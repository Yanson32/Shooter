#ifndef SHOOTER_PLAYSTATE_H
#define SHOOTER_PLAYSTATE_H
#include "States/StateBase.h"
#include "States/Id.h"
#include "Editor/Map.h"
#include "Gui/Options/OptionsPanel.h"
#include <SFML/Graphics.hpp>
class PlayState: public StateBase
{
    public:
        PlayState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap, const int &newId = States::Id::PLAY_STATE);

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

        void handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event);

        /*********************************************************************************//**
        *   \brief	This method draws the current game state.
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void Draw(GU::Engin::Engin& engin, const float &deltaTime) override;
        virtual ~PlayState();
        sf::Texture texture;
};

#endif // SHOOTER_PLAYSTATE_H
