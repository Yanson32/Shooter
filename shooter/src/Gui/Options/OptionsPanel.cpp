#include "Gui/Options/OptionsPanel.h"
#include "Settings.h"
#include <GameUtilities/Event/EventManager.h>
#include "Gui/id.h"
#include "GameUtilities/Event/Click.h"

#include <iostream>
/****************************************************************************//**
*   @brief The constructor
*   @param  The id param is used to identify the gui panel.
********************************************************************************/
OptionsPanel::OptionsPanel(const bool greyStyle, const int newId):
GuiBase(newId),
devSettingsPanel(new DevSettingsPanel()),
generalPanel(new GeneralPanel()),
controlPanel(new ControlPanel()),
soundPanel(new SoundPanel()),
multiPlayerSettingsPanel(new MultiPlayerSettingsPanel())
{
    //ctor
    closeBtn = tgui::Button::create("Close");
    sf::Color grey(50, 50, 50);

    tabs = tgui::Tabs::create();
    tabLayout->add(tabs);

    tabs->add("General");
    tabs->add("Controls");
    tabs->add("Sound");
    tabs->add("Multiplayer");
    #ifdef DEBUG
        tabs->add("Dev");
    #endif

    tabs->setTabVisible(0, true);

    tabs->connect("TabSelected", [&](){
            sf::String text = tabs->getSelected();
            if(text == "General")
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content = generalPanel;
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }
            else if(text == "Controls")
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content = controlPanel;
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }
            else if(text == "Sound")
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content = soundPanel;
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }
            else if(text == "Multiplayer")
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content = multiPlayerSettingsPanel;
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }
            else if(text == "Dev")
            {
                this->removeAllWidgets();
                this->add(tabLayout);
                content = devSettingsPanel;
                content->setSize("95%", "70%");
                content->setPosition("5%", "15%");
                this->add(content);
                this->add(buttonLayout);
            }

        });
    backBtn = tgui::Button::create("Back");

    if(greyStyle)
    {
        getRenderer()->setBackgroundColor(grey);
        backBtn->getRenderer()->setBackgroundColor(grey);
        closeBtn->getRenderer()->setBackgroundColor(grey);
        buttonLayout->add(backBtn);
        buttonLayout->add(closeBtn);
        buttonLayout->addSpace(1);

    }
    else
    {
        getRenderer()->setBackgroundColor(sf::Color::Transparent);
        buttonLayout->addSpace(1);
        buttonLayout->add(closeBtn);
        buttonLayout->addSpace(1);
    }

   tabs->select("General");
}

void OptionsPanel::init(DebugDraw &debugDraw)
{
    devSettingsPanel->init(debugDraw);
}
/****************************************************************************//**
*   @brief  Destructor
********************************************************************************/
OptionsPanel::~OptionsPanel()
{
    //dtor
}
