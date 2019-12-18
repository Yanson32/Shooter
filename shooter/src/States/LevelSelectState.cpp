#include "States/LevelSelectState.h"
#include "Events/EventManager.h"
#include "Settings.h"
#include "Editor/Map.h"
#include <iostream>
#include <GameUtilities/Event/PushState.h>
LevelSelectState::LevelSelectState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap, const int &newId):
StateBase(newWindow, newGui, newWorld, newDebugDraw, newMap, newId)
{
    //ctor
    icon.setSize({20, 20});
    icon.setFillColor(sf::Color::Red);
    icon.setOrigin(10, 10);
}
/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void LevelSelectState::Init()
{
    path.clear();
    path.setPrimitiveType(sf::LineStrip);

    sf::Vertex vert0;
    vert0.position = sf::Vector2f(100, 50);
    vert0.color = sf::Color::White;
    path.append(vert0);

    sf::Vertex vert1;
    vert1.position = sf::Vector2f(400, 50);
    vert1.color = sf::Color::Red;
    path.append(vert1);

    sf::Vertex vert2;
    vert2.position = sf::Vector2f(700, 50);
    vert2.color = sf::Color::Blue;
    path.append(vert2);

    sf::Vertex vert3;
    vert3.position = sf::Vector2f(700, 200);
    vert3.color = sf::Color::Yellow;
    path.append(vert3);

    sf::Vertex vert4;
    vert4.position = sf::Vector2f(400, 200);
    vert4.color = sf::Color::Magenta;
    path.append(vert4);

    sf::Vertex vert5;
    vert5.position = sf::Vector2f(100, 200);
    vert5.color = sf::Color::Green;
    path.append(vert5);

    sf::Vertex vert6;
    vert6.position = sf::Vector2f(100, 350);
    vert6.color = sf::Color::White;
    path.append(vert6);

    sf::Vertex vert7;
    vert7.position = sf::Vector2f(400, 350);
    vert7.color = sf::Color::Red;
    path.append(vert7);

    sf::Vertex vert8;
    vert8.position = sf::Vector2f(700, 350);
    vert8.color = sf::Color::Blue;
    path.append(vert8);

    position = 0;
    circle.setRadius(5);
    circle.setOrigin(5, 5);
    circle.setFillColor(sf::Color::Green);
//    circle.setPosition({100, 50});
//    dots.push_back(circle);
//    circle.setPosition({400, 50});
//    dots.push_back(circle);
//    circle.setPosition({700, 50});
//    dots.push_back(circle);
//    circle.setPosition({700, 200});
//    dots.push_back(circle);
//    circle.setPosition({400, 200});
//    dots.push_back(circle);
//    circle.setPosition({100, 200});
//    dots.push_back(circle);
//
//
//
//    circle.setPosition({100, 350});
//    dots.push_back(circle);
//    circle.setPosition({400, 350});
//    dots.push_back(circle);
//    circle.setPosition({700, 350});
//    dots.push_back(circle);

    icon.setPosition(path[position].position);
}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void LevelSelectState::Clean()
{
    path.clear();
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
                icon.setPosition(path[position].position);
                break;
            }

            if(event.key.code == sf::Keyboard::Enter)
            {
                unsigned currentLevel = Settings::currentWorld * Settings::maxLevel + position;
                Settings::currentLevel = currentLevel;
                EventManager::inst().Post<GU::Evt::PushState>(States::Id::PLAY_STATE);
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
    window.draw(path);
    for(size_t i = 0; i < path.getVertexCount(); ++i)
    {
        circle.setPosition(path[i].position);
        window.draw(circle);
    }
    window.draw(icon);
    window.display();
}

LevelSelectState::~LevelSelectState()
{
    //dtor
}
