#include "States/LevelSelectState.h"
#include "Events/EventManager.h"
#include "Settings.h"
#include "Editor/Map.h"
#include <iostream>
LevelSelectState::LevelSelectState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap, const int &newId):
StateBase(newWindow, newGui, newWorld, newDebugDraw, newMap, newId)
{
    //ctor
    icon.setSize({10, 10});
    icon.setFillColor(sf::Color::Red);
}
/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void LevelSelectState::Init()
{
    position = 0;
    sf::CircleShape circle;
    circle.setRadius(5);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({100, 50});
    dots.push_back(circle);
    circle.setPosition({400, 50});
    dots.push_back(circle);
    circle.setPosition({700, 50});
    dots.push_back(circle);
    circle.setPosition({700, 200});
    dots.push_back(circle);
    circle.setPosition({400, 200});
    dots.push_back(circle);
    circle.setPosition({100, 200});
    dots.push_back(circle);



    circle.setPosition({100, 300});
    dots.push_back(circle);
    circle.setPosition({400, 300});
    dots.push_back(circle);
    circle.setPosition({700, 300});
    dots.push_back(circle);

    icon.setPosition(dots[position].getPosition());
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

                    switch(event.type)
        {
            case sf::Event::KeyPressed:
//            if(event.key.code == Settings::right)
//            {
//                if(position == 2 ||
//                    position == 5 ||
//                    position == 8)
//                    return;
//                position += 1;
//                if(position >= dots.size())
//                    position = 0;
//
//                icon.setPosition(dots[position].getPosition());
//            }
//            else if(event.key.code == Settings::down)
//            {
//                if(position == 2 ||
//                    position == 5 ||
//                    position == 8)
//                    {
//                        position += 1;
//                        if(position >= dots.size())
//                            position = 0;
//
//                        icon.setPosition(dots[position].getPosition());
//                    }
//            }

            if(position == 0)
            {
                if(event.key.code == Settings::right)
                {
                    position = 1;

                }
            }
            else if(position == 1)
            {
                if(event.key.code == Settings::right)
                    position = 2;
                else if(event.key.code == Settings::left)
                    position = 0;
            }
            else if(position == 2)
            {
                if(event.key.code == Settings::down)
                    position = 3;
                else if(event.key.code == Settings::left)
                    position = 1;
            }
            else if(position == 3)
            {
                if(event.key.code == Settings::left)
                    position = 4;
                else if(event.key.code == Settings::up)
                    position = 2;
            }
            else if(position == 4)
            {
                if(event.key.code == Settings::left)
                    position = 5;
                else if(event.key.code == Settings::right)
                    position = 3;
            }
            else if(position == 5)
            {
                if(event.key.code == Settings::down)
                    position = 6;
                else if(event.key.code == Settings::right)
                    position = 4;
            }
            else if(position == 6)
            {
                if(event.key.code == Settings::up)
                    position = 5;
                else if(event.key.code == Settings::right)
                    position = 7;
            }
            else if(position == 7)
            {
                if(event.key.code == Settings::left)
                    position = 6;
                else if(event.key.code == Settings::right)
                    position = 8;
            }
            else if(position == 8)
            {
                if(event.key.code == Settings::left)
                    position = 7;
            }
            icon.setPosition(dots[position].getPosition());
            break;
        }
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

    window.draw(icon);
    window.display();
}

LevelSelectState::~LevelSelectState()
{
    //dtor
}
