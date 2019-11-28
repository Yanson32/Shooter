#include "Gui/IntroPanel.h"
#include "Settings.h"
//#include "Event/Object.h"
#include "Events/EventManager.h"
//#include "State/Id.h"
#include "GameUtilities/Event/Click.h"
#include "GameUtilities/Event/PushState.h"
#include "Gui/id.h"
#include "States/Id.h"
#include "Gui/id.h"

/****************************************************************************//**
*   @brief  Constructor.
********************************************************************************/
IntroPanel::IntroPanel():
GuiBase(Gui::id::INTRO)
{
    //ctor
    const sf::Vector2f buttonPos1(300, 400);
    const sf::Vector2f buttonPos2(300, 475);

    startBtn = tgui::Button::create("Start");
    startBtn->setSize(Settings::buttonSize);
    startBtn->connect("pressed", [](){
        EventManager::inst().Post<GU::Evt::PushState>(States::Id::PLAY_STATE);
    });


    tgui::HorizontalLayout::Ptr layout1 = content->appendLayout();
    layout1->add(spacer);
    layout1->add(startBtn);
    layout1->add(spacer);

    loadButton = tgui::Button::create("Load");
    tgui::HorizontalLayout::Ptr layout2 = content->appendLayout();
    layout2->add(loadButton);


    hostButton = tgui::Button::create("Host");
    hostButton->connect("pressed", [](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::MULTIPLAYER);

    });

    hostButton->setSize(Settings::buttonSize);

    tgui::HorizontalLayout::Ptr layout3 = content->appendLayout();
    layout3->add(spacer);
    layout3->add(hostButton);
    layout3->add(spacer);

    tgui::HorizontalLayout::Ptr layout4 = content->appendLayout();
    connectButton = tgui::Button::create("Connect");

    layout4->add(spacer);
    layout4->add(connectButton);
    layout4->add(spacer);


    optionsBtn = tgui::Button::create("Options");
    optionsBtn->setSize(Settings::buttonSize);
    optionsBtn->connect("pressed", [](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::GENERAL);
    });

    tgui::HorizontalLayout::Ptr layout5 = content->appendLayout();
    connectButton = tgui::Button::create("Connect");

    layout5->add(spacer);
    layout5->add(optionsBtn);
    layout5->add(spacer);



    #ifdef DEBUG
        content->appendSpacer();
        tgui::HorizontalLayout::Ptr layout6 = content->appendLayout();
        tgui::Button::Ptr mapButton = tgui::Button::create("Map");
        layout6->add(spacer);
        layout6->add(mapButton);
        layout6->add(spacer);
        mapButton->connect("pressed", [&](){
            EventManager::inst().Post<GU::Evt::Click>(Gui::id::MAP_LOADER);
        });
    #endif
}


/****************************************************************************//**
*   @brief  Destructor.
********************************************************************************/
IntroPanel::~IntroPanel()
{
    //dtor
}

