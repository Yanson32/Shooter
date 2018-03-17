#include "States/IntroState.h"
#include <SFML/Window/Event.hpp>
#include "Events/EventManager.h"
#include <iostream>

IntroState::IntroState()
{
    //ctor
}

/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void IntroState::Init()
{

}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void IntroState::Clean()
{

}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void IntroState::HandleEvents(GU::Engin::Engin& engin, const int &deltaTime)
{
    if(window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            StateBase::sfEvent(engin, event);
            //sfEvent(engin, event);
            //gui.handleEvent(event);
        }
    }

    //GameUtilities event loop
    GU::Evt::EventPtr evtPtr;
    while(EventManager::inst().Poll((evtPtr)))
    {
        //StateBase::guEvent(engin, evtPtr);
        //guEvent(engin, evtPtr);
    }
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void IntroState::Update(GU::Engin::Engin& engin, const int &deltaTime)
{

}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void IntroState::Draw(GU::Engin::Engin& engin, const int &deltaTime)
{
    window.clear();
    window.display();
}

IntroState::~IntroState()
{
    //dtor
}
