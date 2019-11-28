#include "Gui/StartPanel.h"
#include "States/Id.h"
#include "Events/EventManager.h"
#include <GameUtilities/Event/PushState.h>
#include <GameUtilities/Event/Click.h>
StartPanel::StartPanel():
GuiBase(Gui::id::START)
{
    //ctor

    newGame = tgui::Button::create("New Game");
    newGame->connect("pressed", [&](){
        EventManager::inst().Post<GU::Evt::PushState>(States::Id::PLAY_STATE);
    });
    tgui::HorizontalLayout::Ptr layout1 = content->appendLayout();

    layout1->add(spacer);
    layout1->add(newGame);
    layout1->add(spacer);

    host = tgui::Button::create("Host Game");
    tgui::HorizontalLayout::Ptr layout2 = content->appendLayout();

    layout2->add(spacer);
    layout2->add(host);
    layout2->add(spacer);

    load = tgui::Button::create("Load Game");
    tgui::HorizontalLayout::Ptr layout3 = content->appendLayout();

    layout3->add(spacer);
    layout3->add(load);
    layout3->add(spacer);

    back = tgui::Button::create("Back");
    back->connect("pressed", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::INTRO);
    });
    buttonLayout->add(back);
}

StartPanel::~StartPanel()
{
    //dtor
}
