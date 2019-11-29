#include "Gui/Options/OptionsPanel.h"
#include "Settings.h"
#include "Events/EventManager.h"
#include "Gui/id.h"
#include "GameUtilities/Event/Click.h"

#include <iostream>
/****************************************************************************//**
*   @brief The constructor
*   @param  The id param is used to identify the gui panel.
********************************************************************************/
OptionsPanel::OptionsPanel(const bool back, const int newId):
GuiBase(newId)
{
    //ctor
    closeBtn = tgui::Button::create("Close");
    sf::Color grey(50, 50, 50);
    getRenderer()->setBackgroundColor(grey);
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
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content.reset(new GeneralPanel());
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }
            else if(text == "Controls")
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content.reset(new ControlPanel());
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }
            else if(text == "Sound")
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content.reset(new SoundPanel());
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }
            else if(text == "Multiplayer")
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content.reset(new MultiPlayerSettingsPanel());
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }
            else if(text == "Dev")
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content.reset(new DevSettingsPanel());
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }

        });
    backBtn = tgui::Button::create("Back");
//    backBtn->connect("pressed", [](){
//            EventManager::inst().Post<GU::Evt::Click>(Gui::id::INTRO);
//        });
    backBtn->getRenderer()->setBackgroundColor(grey);
    closeBtn->getRenderer()->setBackgroundColor(grey);
    if(back)
    {
        buttonLayout->add(backBtn);
        buttonLayout->add(closeBtn);
        buttonLayout->add(spacer);

    }
    else
    {
        buttonLayout->add(spacer);
        buttonLayout->add(closeBtn);
        buttonLayout->add(spacer);
    }

   // content->setSize(100, 100);
   tabs->select("General");
}


/****************************************************************************//**
*   @brief  Destructor
********************************************************************************/
OptionsPanel::~OptionsPanel()
{
    //dtor
}
