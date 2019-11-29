#include "Gui/Options/GeneralPanel.h"
#include "Settings.h"
#include "Events/EventManager.h"
#include "Gui/id.h"


/****************************************************************************//**
*   @brief  Constructor.
********************************************************************************/
GeneralPanel::GeneralPanel()//:
//OptionsPanel(Gui::id::GENERAL)
{
    //ctor
    nameEdit = this->appendEditBox("Name", Settings::name);
    nameEdit->connect("TextChanged", [&](){
        sf::String text = nameEdit->getText();
        Settings::name = text;
    });


    std::vector<sf::String> difficulty = {"Easy", "Normal", "Hard"};
    difficultyBox = this->appendComboBox("Difficulty", difficulty);
    difficultyBox->setSelectedItem(Settings::difficulty);
    difficultyBox->connect("ItemSelected", [&](){
        Settings::difficulty = difficultyBox->getSelectedItem();
    });
}


/****************************************************************************//**
*   @brief  Initialize all properties.
********************************************************************************/
void GeneralPanel::init()
{
//    sf::String text = tabs->getSelected();
//    if(text != "General")
//        tabs->select("General");
}


/****************************************************************************//**
*   @brief  Destructor.
********************************************************************************/
GeneralPanel::~GeneralPanel()
{
    //dtor
}
