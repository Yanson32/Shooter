#include "States/LevelSelectState.h"
#include "Events/EventManager.h"
#include "Settings.h"
#include "Editor/Map.h"
LevelSelectState::LevelSelectState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, const int &newId):
StateBase(newWindow, newGui, newWorld, newDebugDraw, newId)
{
    //ctor
}
/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void LevelSelectState::Init()
{

}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void LevelSelectState::Clean()
{

}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void LevelSelectState::HandleEvents(GU::Engin::Engin& engin, const float &deltaTime)
{
    if(window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            handleSFEvent(engin, event);
            gui.handleEvent(event);
        }
    }

    //GameUtilities event loop
    GU::Evt::EventPtr evtPtr;
    while(EventManager::inst().Poll((evtPtr)))
    {
        handleGUEvent(engin, evtPtr);
    }
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void LevelSelectState::Update(GU::Engin::Engin& engin, const float &deltaTime)
{
    if(!IsPaused())
    {
        world.Step(deltaTime, Settings::velocityIterations, Settings::positionIterations);
        debugDraw.update();
        world.DrawDebugData();
    }
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void LevelSelectState::Draw(GU::Engin::Engin& engin, const float &deltaTime)
{
    window.clear(sf::Color::Black);

    window.display();
}

LevelSelectState::~LevelSelectState()
{
    //dtor
}
