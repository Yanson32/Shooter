#include "Gui/NewLevelSettingsPanel.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "Events/EventManager.h"
#include <GameUtilities/Event/PushState.h>
#include <GameUtilities/Event/Click.h>
#include "States/Id.h"
#include "Gui/id.h"
#include "Map.h"
#include "Functions.h"

sf::String normalizeDigit(sf::String text);
sf::String normalizeChar(sf::String text);
NewLevelSettingsPanel::NewLevelSettingsPanel()
{
    //ctor
    newLevel = content->appendEditBox("Name", "");
    widthBox = content->appendEditBox("Level Width", "");
    heightBox = content->appendEditBox("Level Height", "");
    ordering = content->appendEditBox("Order", "");
    gameBox = content->appendCheckBox("Base");

    okButton = tgui::Button::create("Ok");
    okButton->connect("pressed", [&](){
        newLevel->setText(normalizeChar(newLevel->getText()));
        widthBox->setText(normalizeDigit(widthBox->getText()));
        heightBox->setText(normalizeDigit(heightBox->getText()));
        ordering->setText(normalizeDigit(ordering->getText()));
        //bool game = gameBox->getValue();
        if(!newLevel->getText().isEmpty())
        {
            if(!widthBox->getText().isEmpty())
            {
                if(!heightBox->getText().isEmpty())
                {
                    if(!ordering->getText().isEmpty())
                    {
                        Map map;
                        map.name = newLevel->getText().toAnsiString();
                        map.width = toInt(widthBox->getText());
                        map.height = toInt(heightBox->getText());
                        map.ordering = toInt(ordering->getText());
                        map.write();
                        Settings::map = map.name;
                        EventManager::inst().Post<GU::Evt::PushState>(States::Id::MAP_CREATION_STATE);
                    }
                }
            }
        }
    });
    tgui::Button::Ptr backButton = tgui::Button::create("Back");
    backButton->connect("pressed", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::MAP_LOADER);
    });
    buttonLayout->add(spacer);
    buttonLayout->add(okButton);
    buttonLayout->add(backButton);
}

NewLevelSettingsPanel::~NewLevelSettingsPanel()
{
    //dtor
}

sf::String normalizeDigit(sf::String text)
{
    std::string temp = text.toAnsiString();
    temp.erase(remove_if(temp.begin(), temp.end(), [](char c) { return !isdigit(c); } ), temp.end());
    return temp;
}

sf::String normalizeChar(sf::String text)
{
    std::string temp = text.toAnsiString();
    temp.erase(remove_if(temp.begin(), temp.end(), [](char c) { return !isalpha(c); } ), temp.end());
    return temp;
}
