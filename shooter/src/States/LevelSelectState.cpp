#include "States/LevelSelectState.h"
#include "Events/EventManager.h"
#include "Settings.h"
#include "Editor/Map.h"
LevelSelectState::LevelSelectState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap, const int &newId):
StateBase(newWindow, newGui, newWorld, newDebugDraw, newMap, newId)
{
    //ctor
}
/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void LevelSelectState::Init()
{

    sf::CircleShape circle;
    circle.setRadius(5);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({100, 50});
    dots.push_back(circle);
    circle.setPosition({400, 50});
    dots.push_back(circle);
    circle.setPosition({700, 50});
    dots.push_back(circle);
    circle.setPosition({100, 200});
    dots.push_back(circle);
    circle.setPosition({400, 200});
    dots.push_back(circle);
    circle.setPosition({700, 200});
    dots.push_back(circle);
    circle.setPosition({100, 300});
    dots.push_back(circle);
    circle.setPosition({400, 300});
    dots.push_back(circle);
    circle.setPosition({700, 300});
    dots.push_back(circle);
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
    for(size_t i = 0; i < dots.size(); ++i)
    {
        window.draw(dots[i]);
    }
    window.display();
}

LevelSelectState::~LevelSelectState()
{
    //dtor
}
