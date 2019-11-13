#include "Gui/OptionsPanel.h"
//#include "Event/Manager.h"
//#include "Event/Object.h"
namespace Gui
{
    OptionsPanel::OptionsPanel()
    {

    tabs = tgui::Tabs::create();
    tabLayout->add(tabs);
    //tabs->setPosition({300, 100});
    tabs->add("General");
    tabs->add("Controls");
    tabs->add("Sound");
    #ifdef DEBUG
        tabs->add("Dev");
    #endif
    tabs->select("General");
    tabs->setTabVisible(0, true);
    tabs->connect("TabSelected", [&](){
        sf::String text = tabs->getSelected();
        Event::Object event(Event::Object::Type::TAB_PRESSED);
        if(text == "General")
            event.tabPressed.id = Event::TabPressed::GENERAL_TAB;
        else if(text == "Controls")
            event.tabPressed.id = Event::TabPressed::CONTROLS_TAB;
        else if(text == "Sound")
            event.tabPressed.id = Event::TabPressed::SOUND_TAB;
        else if(text == "Dev")
            event.tabPressed.id = Event::TabPressed::DEV_TAB;

        Event::Manager::inst().push(event);
    });




    backBtn = tgui::Button::create("Back");
    backBtn->setTextSize(buttonTextSize);
    backBtn->connect("pressed", [](){
            Event::Object event(Event::Object::Type::BUTTON_PRESSED);
            event.buttonPressed.id = Event::ButtonPressed::BACK_BUTTON;
            Event::Manager::inst().push(event);
    });


    buttonLayout->add(spacer);
    buttonLayout->add(backBtn);
    buttonLayout->add(spacer);

    }

    OptionsPanel::~OptionsPanel()
    {

    }
}
