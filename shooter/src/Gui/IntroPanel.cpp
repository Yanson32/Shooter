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
    //getRenderer()->setBackgroundColor(sf::Color::Transparent);
    const sf::Vector2f buttonPos1(300, 400);
    const sf::Vector2f buttonPos2(300, 475);
    //ctor
    startBtn = tgui::Button::create("Start");
    //startBtn->setTextSize(buttonTextSize);
    startBtn->setSize(Settings::buttonSize);
    startBtn->connect("pressed", [](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::START);
    });

    multiplayerButton = tgui::Button::create("Multiplayer");
    //multiplayerButton->setTextSize(buttonTextSize);
    multiplayerButton->connect("pressed", [](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::MULTIPLAYER);

    });

    multiplayerButton->setSize(Settings::buttonSize);

    optionsBtn = tgui::Button::create("Options");
    //optionsBtn->setTextSize(buttonTextSize);
    optionsBtn->setSize(Settings::buttonSize);
    optionsBtn->connect("pressed", [](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::GENERAL);
    });

    tgui::HorizontalLayout::Ptr layout1 = content->appendLayout();
    layout1->add(spacer);
    layout1->add(startBtn);
    layout1->add(spacer);

    tgui::HorizontalLayout::Ptr mapSpace = content->appendLayout();

    #ifdef DEBUG
        tgui::Button::Ptr mapButton = tgui::Button::create("Map");
        mapSpace->add(spacer);
        mapSpace->add(mapButton);
        mapSpace->add(spacer);
        mapButton->connect("pressed", [&](){
            EventManager::inst().Post<GU::Evt::Click>(Gui::id::MAP_LOADER);
        });
    #endif
    tgui::HorizontalLayout::Ptr layout2 = content->appendLayout();

    layout2->add(spacer);
    layout2->add(multiplayerButton);
    layout2->add(spacer);

    content->appendSpacer();
    tgui::HorizontalLayout::Ptr layout3 = content->appendLayout();

    layout3->add(spacer);
    layout3->add(optionsBtn);
    layout3->add(spacer);
}


/****************************************************************************//**
*   @brief  Destructor.
********************************************************************************/
IntroPanel::~IntroPanel()
{
    //dtor
}

