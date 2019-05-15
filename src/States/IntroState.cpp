#include "States/IntroState.h"
#include "States/Id.h"
#include <SFML/Window/Event.hpp>
#include "Events/EventManager.h"
#include <iostream>
#include "Settings.h"
#include "Events/Events.h"
//tgui::Gui IntroState::gui(window);

IntroState::IntroState(sf::RenderWindow &newWindow, tgui::Gui &newGui):
StateBase(newWindow, newGui)
{
    //ctor
    startButton = tgui::Button::create("Start");
    startButton->connect("pressed", &IntroState::onStartPressed, this);
    startButton->setPosition(Settings::inst().buttonPosition(0));
    startButton->setSize(Settings::inst().buttonSize());

    multiplayerButton = tgui::Button::create("Multiplayer");
    multiplayerButton->connect("pressed", &IntroState::onMultiplayerPressed, this);
    multiplayerButton->setPosition(Settings::inst().buttonPosition(1));
    multiplayerButton->setSize(Settings::inst().buttonSize());

    mapButton = tgui::Button::create("Map Creator");
    mapButton->connect("pressed", &IntroState::onMapPressed, this);
    mapButton->setPosition(Settings::inst().buttonPosition(2));
    mapButton->setSize(Settings::inst().buttonSize());

    optionButton = tgui::Button::create("Options");
    optionButton->connect("pressed", &IntroState::onOptionsPressed, this);
    optionButton->setPosition(Settings::inst().buttonPosition(3));
    optionButton->setSize(Settings::inst().buttonSize());

}

/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void IntroState::Init()
{
    gui.add(startButton);
    gui.add(multiplayerButton);
    gui.add(optionButton);
    gui.add(mapButton);
}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void IntroState::Clean()
{
    gui.removeAllWidgets();
}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void IntroState::HandleEvents(GU::Engin::Engin& engin, const float &deltaTime)
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
void IntroState::Update(GU::Engin::Engin& engin, const float &deltaTime)
{

}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void IntroState::Draw(GU::Engin::Engin& engin, const float &deltaTime)
{
    window.clear();
    gui.draw();
    window.display();
}


void IntroState::onStartPressed()
{
    EventManager::inst().Post<GU::Evt::PushState>(States::Id::PLAY_STATE);
}

void IntroState::onMultiplayerPressed()
{
    EventManager::inst().Post<GU::Evt::PushState>(States::Id::MULTIPLAYER_STATE);
}

void IntroState::onOptionsPressed()
{
    EventManager::inst().Post<GU::Evt::PushState>(States::Id::OPTIONS_STATE);
}

void IntroState::onMapPressed()
{
    EventManager::inst().Post<GU::Evt::PushState>(States::Id::MAP_CREATOR_STATE);
}

IntroState::~IntroState()
{
    //dtor
}
