#include "States/PlayState.h"
#include "Events/EventManager.h"

PlayState::PlayState():
StateBase::StateBase()
{

}
/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void PlayState::Init()
{

}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void PlayState::Clean()
{

}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void PlayState::HandleEvents(GU::Engin::Engin& engin, const int &deltaTime)
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
void PlayState::Update(GU::Engin::Engin& engin, const int &deltaTime)
{
    if(!IsPaused())
    {

    }
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void PlayState::Draw(GU::Engin::Engin& engin, const int &deltaTime)
{
    window.clear();
    gui.draw();
    window.display();
}

PlayState::~PlayState()
{
    //dtor
}