#include "States/MapCreatorState.h"
#include "Events/Events.h"
#include <cassert>
MapCreatorState::MapCreatorState():
panel(new MapCreatorPanel())
{
    //ctor
    collapseButton = tgui::Button::create("Collapse");
    collapseButton->connect("pressed", &MapCreatorState::onCollapsePressed, this);
    collapseButton->setSize({50, 50});
}

/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void MapCreatorState::Init()
{
    gui.add(panel);
    gui.add(collapseButton);
}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void MapCreatorState::Clean()
{
    gui.removeAllWidgets();
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void MapCreatorState::HandleEvents(GU::Engin::Engin& engin, const int &deltaTime)
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
void MapCreatorState::Update(GU::Engin::Engin& engin, const int &deltaTime)
{
    if(!IsPaused())
    {
        sf::Vector2f panelPos = panel->getPosition();
        auto time = collapseTimer.restart();
        auto difference = (time.asSeconds() * panel->getSize().x * 2);


        if(panel->collapsed)
        {
            panelPos.x -= difference;
            if(panelPos.x < (0 - panel->getSize().x))
                panelPos.x = 0 - panel->getSize().x;

            panel->setPosition(panelPos);
        }
        else
        {
            panelPos.x += difference;
            if(panelPos.x > 0)
                panelPos.x = 0;

            panel->setPosition(panelPos);
        }

        sf::Vector2f buttonPos = panel->getPosition();
        buttonPos.x += panel->getSize().x;
        collapseButton->setPosition(buttonPos);
    }
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void MapCreatorState::Draw(GU::Engin::Engin& engin, const int &deltaTime)
{
    window.clear();
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
    }
    StateBase::handleGUEvent(engin, event);
}

void MapCreatorState::onCollapsePressed()
{
    assert(panel != nullptr);
    panel->collapsed = !panel->collapsed;
    collapseTimer.restart();
}

MapCreatorState::~MapCreatorState()
{
    //dtor
}
