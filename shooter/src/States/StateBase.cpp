#include "States/StateBase.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include "Settings.h"
#include <GameUtilities/Engin/Engin.h>
#include "Events/Id.h"
#include "Events/Events.h"
#include "States/Id.h"
#include "States/States.h"
#include <iostream>
#include "Gui/id.h"
#include "GameUtilities/Event/Click.h"
#include "Gui/GeneralPanel.h"
#include "Gui/IntroPanel.h"
#include "Gui/ControlPanel.h"
#include "Gui/SoundPanel.h"
#include "Gui/MultiPlayerSettingsPanel.h"
#include "Gui/DevSettingsPanel.h"
#include "Gui/MapLoader.h"
#include "Gui/NewLevelSettingsPanel.h"

//sf::RenderWindow StateBase::window(sf::VideoMode({800, 600}), Settings::inst().getTitle());
//tgui::Gui StateBase::gui(window);
StateBase::StateBase(sf::RenderWindow &newWindow, tgui::Gui &newGui, const int &newId):
window(newWindow),
gui(newGui),
id(newId)
{
    //ctor
    title = tgui::Label::create(Settings::title);
    gui.add(title);
    title->setPosition({320, 25});
    title->setTextSize(40);
}


void StateBase::handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event)
{
    switch(event->id)
    {
        case Events::Id::POP_STATE:
            engin.Pop();
        break;
        case Events::Id::PUSH_STATE:
        {
            std::shared_ptr<GU::Evt::PushState> temp =  std::dynamic_pointer_cast<GU::Evt::PushState>(event);
            if(temp)
            {   std::cout << "Push state" << std::endl;
                switch(temp->id)
                {
                    case States::Id::PLAY_STATE:
                        engin.Push<PlayState>(window, gui);
                    break;
                    case States::Id::MAP_CREATION_STATE:
                        engin.Push<MapCreatorState>(window, gui, Settings::map);
                    break;
                    case States::Id::INTRO_STATE:
                        engin.Push<IntroState>(window, gui);
                    break;
                }
            }
        }
        break;
        case Events::Id::CLICK:
            std::shared_ptr<GU::Evt::Click> temp =  std::dynamic_pointer_cast<GU::Evt::Click>(event);
            std::cout << "Click" << std::endl;
            switch(temp->buttonId)
            {
                case Gui::id::OPTIONS:
                    gui.removeAllWidgets();
                    panel = std::shared_ptr<GeneralPanel>(new GeneralPanel());
                    gui.add(panel);
                break;
                case Gui::id::INTRO:
                    if(panel->id != Gui::id::INTRO)
                    {
                        gui.removeAllWidgets();
                        gui.add(title);
                        panel = std::shared_ptr<IntroPanel>(new IntroPanel());
                        gui.add(panel);
                    }
                break;
                case Gui::id::CONTROLS:
                {
                    if(panel->id != Gui::id::CONTROLS)
                    {
                        gui.removeAllWidgets();
                        gui.add(title);
                        std::shared_ptr<ControlPanel> tempPanel = std::shared_ptr<ControlPanel>(new ControlPanel());
                        tempPanel->init();
                        panel = tempPanel;
                        gui.add(panel);
                    }
                }
                break;
                case Gui::id::SOUND:
                    if(panel->id != Gui::id::SOUND)
                    {
                        gui.removeAllWidgets();
                        gui.add(title);
                        std::shared_ptr<SoundPanel> tempPanel = std::shared_ptr<SoundPanel>(new SoundPanel());
                        tempPanel->init();
                        panel = tempPanel;
                        gui.add(panel);
                    }
                break;
                case Gui::id::GENERAL:
                {
                    std::cout << "General" << std::endl;
                    if(panel->id != Gui::id::GENERAL)
                    {
                        gui.removeAllWidgets();
                        gui.add(title);
                        std::shared_ptr<GeneralPanel> tempPanel = std::shared_ptr<GeneralPanel>(new GeneralPanel());
                        tempPanel->init();
                        panel = tempPanel;
                        gui.add(panel);
                    }
                }
                break;
                case Gui::id::MULTIPLAYER:
                {
                    if(panel->id != Gui::id::MULTIPLAYER)
                    {
                        gui.removeAllWidgets();
                        gui.add(title);
                        std::shared_ptr<MultiPlayerSettingsPanel> tempPanel = std::shared_ptr<MultiPlayerSettingsPanel>(new MultiPlayerSettingsPanel());
                        tempPanel->init();
                        panel = tempPanel;
                        gui.add(panel);
                    }
                }
                break;
                case Gui::id::DEV:
                {
                    if(panel->id != Gui::id::DEV)
                    {
                        gui.removeAllWidgets();
                        gui.add(title);
                        std::shared_ptr<DevSettingsPanel> tempPanel = std::shared_ptr<DevSettingsPanel>(new DevSettingsPanel());
                        tempPanel->init();
                        panel = tempPanel;
                        gui.add(panel);
                    }
                }
                break;
                case Gui::id::MAP_LOADER:
                {
                    if(this->id)
                    if(panel->id != Gui::id::MAP_LOADER)
                    {
                        gui.removeAllWidgets();
                        std::shared_ptr<MapLoader> tempPanel = std::shared_ptr<MapLoader>(new MapLoader());
                        tempPanel->init();
                        panel = tempPanel;
                        gui.add(panel);
                    }
                }
                break;
                case Gui::id::NEW_LEVEL:
                {
                    if(panel->id != Gui::id::NEW_LEVEL)
                    {
                        gui.removeAllWidgets();
                        std::shared_ptr<NewLevelSettingsPanel> tempPanel = std::shared_ptr<NewLevelSettingsPanel>(new NewLevelSettingsPanel());
                        tempPanel->init();
                        panel = tempPanel;
                        gui.add(panel);
                    }
                }
                break;

            }
        break;
    }
}

void StateBase::handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event)
{
    switch(event.type)
    {
        case sf::Event::Closed:
            engin.Quit();
        break;
        case sf::Event::KeyPressed:
            switch(event.key.code)
            {
                case sf::Keyboard::Escape:
                    gui.removeAllWidgets();
                    panel = std::shared_ptr<GeneralPanel>(new GeneralPanel());
                    std::shared_ptr<GeneralPanel> temp = std::static_pointer_cast<GeneralPanel>(panel);
                    if(temp)
                    {
                        temp->backBtn->connect("pressed", [&](){
                            EventManager::inst().Post<GU::Evt::Pop>();
                            gui.removeAllWidgets();
                        });
                    }

                    gui.add(panel);
                break;
            }
        break;
    }
}

StateBase::~StateBase()
{
    //dtor
}
