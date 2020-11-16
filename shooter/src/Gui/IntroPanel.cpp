#include "Gui/IntroPanel.h"
#include "Settings.h"
//#include "Event/Object.h"
#include <GameUtilities/Event/EventManager.h>
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

    //Create start button
    startBtn = tgui::Button::create("Start");
    startBtn->setSize(Settings::buttonSize);
    startBtn->connect("pressed", [](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::PLAYER_INFO);
    });


    tgui::HorizontalLayout::Ptr layout1 = content->appendLayout();
    layout1->addSpace(1);
    layout1->add(startBtn);
    layout1->addSpace(1);
   

    //Create load button 
    loadButton = tgui::Button::create("Load");
    tgui::HorizontalLayout::Ptr layout2 = content->appendLayout();
    
    layout2->addSpace(1);
    layout2->add(loadButton);
    layout2->addSpace(1);


    //Create host button
    hostButton = tgui::Button::create("Host");
    hostButton->connect("pressed", [](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::MULTIPLAYER);

    });


    tgui::HorizontalLayout::Ptr layout3 = content->appendLayout();
    layout3->addSpace(1);
    layout3->add(hostButton);
    layout3->addSpace(1);

  
    //Create connect button 
    tgui::HorizontalLayout::Ptr layout4 = content->appendLayout();
    connectButton = tgui::Button::create("Connect");

    layout4->addSpace(1);
    layout4->add(connectButton);
    layout4->addSpace(1);


    //Create options button
    optionsBtn = tgui::Button::create("Options");
    optionsBtn->connect("pressed", [](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::OPTIONS);
    });

    tgui::HorizontalLayout::Ptr layout5 = content->appendLayout();

    layout5->addSpace(1);
    layout5->add(optionsBtn);
    layout5->addSpace(1);


    //Create map button
    #ifdef DEBUG
        content->appendSpacer();
        tgui::HorizontalLayout::Ptr layout6 = content->appendLayout();
        tgui::Button::Ptr mapButton = tgui::Button::create("Map");
        layout6->addSpace(1);
        layout6->add(mapButton);
        layout6->addSpace(1);
        
	mapButton->connect("pressed", [&](){
            GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::MAP_LOADER);
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

