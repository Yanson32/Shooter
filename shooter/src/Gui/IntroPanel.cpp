#include "Gui/IntroPanel.h"
#include "Settings.h"
//#include "Event/Object.h"
//#include "Event/Manager.h"
//#include "State/Id.h"
namespace Gui
{
    IntroPanel::IntroPanel()
    {
        //ctor
        const sf::Vector2f buttonPos1(300, 400);
        const sf::Vector2f buttonPos2(300, 475);
        //ctor
        startBtn = tgui::Button::create("Start");
        startBtn->setTextSize(buttonTextSize);
        startBtn->setSize(Settings::buttonSize);
        startBtn->connect("pressed", [](){
            //Event::Object event(Event::Object::Type::BUTTON_PRESSED);
            //event.buttonPressed.id = Event::ButtonPressed::START_BUTTON;
            //Event::Manager::inst().push(event);
        });

        multiplayerButton = tgui::Button::create("Multiplayer");
        multiplayerButton->setTextSize(buttonTextSize);
        //multiplayerButton->connect("pressed", &IntroState::onMultiplayerPressed, this);
        //multiplayerButton->setPosition(Settings::inst().buttonPosition(1));
        multiplayerButton->setSize(Settings::buttonSize);

        optionsBtn = tgui::Button::create("Options");
        optionsBtn->setTextSize(buttonTextSize);
        optionsBtn->setSize(Settings::buttonSize);
        optionsBtn->connect("pressed", [](){
            //Event::Object event(Event::Object::Type::BUTTON_PRESSED);
            //event.buttonPressed.id = Event::ButtonPressed::OPTIONS_BUTTON;
            //Event::Manager::inst().push(event);
        });


        layout3->add(spacer);
        layout3->add(startBtn);
        layout3->add(spacer);

        layout5->add(spacer);
        layout5->add(multiplayerButton);
        layout5->add(spacer);

        buttonLayout->add(spacer);
        buttonLayout->add(optionsBtn);
        buttonLayout->add(spacer);


        //    startButton = tgui::Button::create("Start");
//    startButton->connect("pressed", &IntroState::onStartPressed, this);
//    //startButton->setPosition(Settings::inst().buttonPosition(0));
//    startButton->setSize(Settings::buttonSize);
//
//    multiplayerButton = tgui::Button::create("Multiplayer");
//    multiplayerButton->connect("pressed", &IntroState::onMultiplayerPressed, this);
//    //multiplayerButton->setPosition(Settings::inst().buttonPosition(1));
//    multiplayerButton->setSize(Settings::buttonSize);
//
//    mapButton = tgui::Button::create("Map Creator");
//    mapButton->connect("pressed", &IntroState::onMapPressed, this);
//    //mapButton->setPosition(Settings::inst().buttonPosition(2));
//    mapButton->setSize(Settings::buttonSize);
//
//    optionButton = tgui::Button::create("Options");
//    optionButton->connect("pressed", &IntroState::onOptionsPressed, this);
//    //optionButton->setPosition(Settings::inst().buttonPosition(3));
//    optionButton->setSize(Settings::buttonSize);
    }

    IntroPanel::~IntroPanel()
    {
        //dtor
    }
}
