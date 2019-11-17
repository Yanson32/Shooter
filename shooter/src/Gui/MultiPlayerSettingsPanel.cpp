#include "Gui/MultiPlayerSettingsPanel.h"
#include "Gui/id.h"
#include <sstream>
#include "Settings.h"
#include "Functions.h"


/****************************************************************************//**
*   @brief  Constructor.
********************************************************************************/
MultiPlayerSettingsPanel::MultiPlayerSettingsPanel():
OptionsPanel(Gui::id::MULTIPLAYER)
{
    //ctor
    portLabel = tgui::Label::create("Port");
    portBox = content->appendEditBox("Port", toString(Settings::port));
    portBox->connect("TextChanged", [&](){
        sf::String text = portBox->getText();
        Settings::port = toInt(text);
    });
}


/****************************************************************************//**
*   @brief  Set values for all properties.
********************************************************************************/
void MultiPlayerSettingsPanel::init()
{
    sf::String text = tabs->getSelected();
    if(text != "Multiplayer")
        tabs->select("Multiplayer");
}


/****************************************************************************//**
*   @brief  Constructor.
********************************************************************************/
MultiPlayerSettingsPanel::~MultiPlayerSettingsPanel()
{
    //dtor
}
