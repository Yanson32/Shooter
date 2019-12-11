#include "Gui/PlayerInfo.h"
#include "Events/EventManager.h"
#include <GameUtilities/Event/Click.h>
#include "Gui/id.h"
#include <iostream>
#include "Settings.h"
#include "States/Id.h"
#include <GameUtilities/Event/ChangeState.h>
#include <GameUtilities/Event/PushState.h>
PlayerInfo::PlayerInfo()
{
    //ctor
    name = content->appendEditBox("Name", "");
    name->connect("TextChanged", [&](){
        sf::String text = name->getText();
        if(text.isEmpty())
            return;

        for(std::size_t i = 0; i < text.toAnsiString().size(); ++i)
        {
            if(!isalpha(text.toAnsiString()[i]))
                return;

        }
    });
    name->setText(Settings::name);
    name->connect("TextChanged",[&](){
        sf::String text = name->getText();
        if(text.isEmpty())
            return;
    });
    std::vector<sf::String> choices;
    choices.push_back("Easy");
    choices.push_back("Medium");
    choices.push_back("Hard");
    difficultyBox = content->appendComboBox("Difficulty", choices);
    difficultyBox->setSelectedItem(Settings::difficulty);
    backButton = tgui::Button::create("Back");
    backButton->connect("pressed", [](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::INTRO);
    });
    okButton = tgui::Button::create("Ok");
    okButton->connect("pressed",[&](){
        sf::String text = name->getText();
        Settings::name = text;
        Settings::difficulty = difficultyBox->getSelectedItem().toAnsiString();

        EventManager::inst().Post<GU::Evt::PushState>(States::Id::PLAY_STATE);
    });

    buttonLayout->add(backButton);
    buttonLayout->add(okButton);
}

PlayerInfo::~PlayerInfo()
{
    //dtor
}
