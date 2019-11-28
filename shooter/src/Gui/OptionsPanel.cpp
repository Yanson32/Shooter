#include "Gui/OptionsPanel.h"
#include "Settings.h"
#include "Events/EventManager.h"
#include "Gui/id.h"
#include "GameUtilities/Event/Click.h"


/****************************************************************************//**
*   @brief The constructor
*   @param  The id param is used to identify the gui panel.
********************************************************************************/
OptionsPanel::OptionsPanel(const int newId):
GuiBase(newId)
{
    //ctor
    getRenderer()->setBackgroundColor(sf::Color::Black);
    tabs = tgui::Tabs::create();
    tabLayout->add(tabs);
    //tabs->setPosition({300, 100});
    tabs->add("General");
    tabs->add("Controls");
    tabs->add("Sound");
    tabs->add("Multiplayer");
    #ifdef DEBUG
        tabs->add("Dev");
    #endif
    //tabs->select("General");
    tabs->setTabVisible(0, true);

    tabs->connect("TabSelected", [&](){
            sf::String text = tabs->getSelected();
            if(text == "General")
                EventManager::inst().Post<GU::Evt::Click>(Gui::id::GENERAL);
            else if(text == "Controls")
                EventManager::inst().Post<GU::Evt::Click>(Gui::id::CONTROLS);
            else if(text == "Sound")
                EventManager::inst().Post<GU::Evt::Click>(Gui::id::SOUND);
            else if(text == "Multiplayer")
                EventManager::inst().Post<GU::Evt::Click>(Gui::id::MULTIPLAYER);
            else if(text == "Dev")
                EventManager::inst().Post<GU::Evt::Click>(Gui::id::DEV);

        });
    backBtn = tgui::Button::create("Back");
//    backBtn->connect("pressed", [](){
//            EventManager::inst().Post<GU::Evt::Click>(Gui::id::INTRO);
//        });

    buttonLayout->add(spacer);
    buttonLayout->add(backBtn);
    buttonLayout->add(spacer);


}


/****************************************************************************//**
*   @brief  Destructor
********************************************************************************/
OptionsPanel::~OptionsPanel()
{
    //dtor
}
