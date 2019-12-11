#ifndef LEVELSELECTSTATE_H
#define LEVELSELECTSTATE_H
#include "States/StateBase.h"
#include "States/Id.h"
#include "Editor/Map.h"
#include "Gui/Options/OptionsPanel.h"
#include <vector>
#include <SFML/Graphics/CircleShape.hpp>
class LevelSelectState: public StateBase
{
    public:
        LevelSelectState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap, const int &newId = States::Id::LEVEL_SELECT_STATE);
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

        virtual ~LevelSelectState();

    protected:
        std::vector<sf::CircleShape> dots;
        sf::RectangleShape icon;
        unsigned position = 0;
    private:
};

#endif // LEVELSELECTSTATE_H
