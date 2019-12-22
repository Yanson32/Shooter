#include "States/MapCreatorState.h"
#include <GameUtilities/Event/EventManager.h>
#include <cassert>
#include <iostream>
#include "Editor/Map.h"
#include "States/Id.h"
#include <memory>
#include <GameUtilities/Event/Click.h>
#include "Gui/id.h"
#include "Editor/EditorObjectPanel.h"
#include "Editor/EditorGeneralPanel.h"
#include "Editor/MapCreatorPanel.h"
#include "Events/Id.h"
#include <iostream>
#include "Settings.h"
#include "Events/ShowGrid.h"
#include "Events/SnapToGrid.h"


MapCreatorState::MapCreatorState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap):
PlayState(newWindow, newGui, newWorld, newDebugDraw, newMap, States::Id::MAP_CREATION_STATE),
panel(new Editor(map, newGui))
{
    //ctor
}

/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void MapCreatorState::Init()
{
    PlayState::Init();
    panel->init();
    gui.add(panel);
    //gui.add(collapseButton);
}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void MapCreatorState::Clean()
{
    PlayState::Clean();
    gui.removeAllWidgets();
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void MapCreatorState::HandleEvents(GU::Engin::Engin& engin, const float &deltaTime)
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
    while(GU::Evt::EventManager::inst().Poll((evtPtr)))
    {
        assert(panel != nullptr);
        panel->handleGUEvent(engin, evtPtr);
        handleGUEvent(engin, evtPtr);

    }
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void MapCreatorState::Update(GU::Engin::Engin& engin, const float &deltaTime)
{
    PlayState::Update(engin, deltaTime);

    if(!IsPaused())
    {
        panel->update();
    }
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void MapCreatorState::Draw(GU::Engin::Engin& engin, const float &deltaTime)
{
    window.clear(sf::Color(map.red, map.green, map.blue));
    window.draw(map);
    window.draw(ecs);
    window.draw(debugDraw);
    gui.draw();
    window.display();
}



void MapCreatorState::handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event)
{

    switch(event->id)
    {
        case Events::Id::SHOW_GRID:
        {
            std::shared_ptr<ShowGrid> temp =  std::dynamic_pointer_cast<ShowGrid>(event);
            assert(temp);
            std::cout << "Show Grid from MapCreatorState = " << temp->grid<< std::endl;
        }
        break;
        case Events::Id::SNAP_TO_GRID:
        {
            std::shared_ptr<SnapToGrid> temp =  std::dynamic_pointer_cast<SnapToGrid>(event);
            assert(temp);
            std::cout << "Snap to grid from MapCreatorState = " << temp->snap<< std::endl;
        }
        break;
        case Events::Id::CLICK:
            std::shared_ptr<GU::Evt::Click> temp =  std::dynamic_pointer_cast<GU::Evt::Click>(event);
            std::cout << "temp id " << temp->id << std::endl;
            switch(temp->buttonId)
            {
                case Gui::id::EDITOR_GENERAL:
//                    if(panel->id != Gui::id::EDITOR_GENERAL)
//                    {
//                        gui.removeAllWidgets();
//                        panel.reset(new EditorGeneralPanel());
//                        gui.add(panel);
//                        gui.add(collapseButton);
//                    }
                break;
                case Gui::id::EDITOR_lAYERS:
//                    if(panel->id != Gui::id::EDITOR_lAYERS)
//                    {
//                        gui.removeAllWidgets();
//                        panel.reset(new EditorLayersPanel());
//                        gui.add(panel);
//                        gui.add(collapseButton);
//                    }
                break;
                case Gui::id::EDITOR_OBJECT:
//                    if(panel->id != Gui::id::EDITOR_OBJECT)
//                    {
//                        gui.removeAllWidgets();
//                        panel.reset(new EditorObjectPanel());
//                        gui.add(panel);
//                        gui.add(collapseButton);
//                    }
                break;
            };
        break;
    }
    StateBase::handleGUEvent(engin, event);
}


MapCreatorState::~MapCreatorState()
{
    //dtor
}
