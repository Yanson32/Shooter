#include "Gui/Options/ControlPanel.h"
#include "Settings.h"
#include "Gui/id.h"
#include "Editor/Functions.h"


/****************************************************************************//**
*   @brief Constructor
********************************************************************************/
ControlPanel::ControlPanel():
OptionsPanel(Gui::id::CONTROLS)
{
    //ctor
    upBox = content->appendEditBox("Up", keyToString(Settings::up));
    upBox->connect("TextChanged", [&](){
        sf::String text = upBox->getText();
        Settings::up = stringToKey(text);
    });

    downBox = content->appendEditBox("Down", keyToString(Settings::down));
    downBox->connect("TextChanged", [&](){
        sf::String text = downBox->getText();
        Settings::down = stringToKey(text);
    });


    leftBox = content->appendEditBox("Left", keyToString(Settings::left));
    leftBox->connect("TextChanged", [&](){
        sf::String text = leftBox->getText();
        Settings::left = stringToKey(text);
    });


    rightBox = content->appendEditBox("Right", keyToString(Settings::right));
    rightBox->connect("TextChanged", [&](){
        sf::String text = rightBox->getText();
        Settings::right = stringToKey(text);
    });


    jumpBox = content->appendEditBox("Jump", keyToString(Settings::jump));
    jumpBox->connect("TextChanged", [&](){
        sf::String text = jumpBox->getText();
        Settings::jump = stringToKey(text);
    });


    actionBox = content->appendEditBox("Action", keyToString(Settings::action));
    actionBox->connect("TextChanged", [&](){
        sf::String text = actionBox->getText();
        Settings::action = stringToKey(text);
    });


}


/****************************************************************************//**
*   @brief The init defines default values for the panel
********************************************************************************/
void ControlPanel::init()
{
    sf::String text = tabs->getSelected();
    if(text != "Controls")
        tabs->select("Controls");
}


/****************************************************************************//**
*   @brief Destructor
********************************************************************************/
ControlPanel::~ControlPanel()
{
    //dtor
}
