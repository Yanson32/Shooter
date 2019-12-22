#include "Gui/NewLevelSettingsPanel.h"
#include <algorithm>
#include <string>
#include <GameUtilities/Event/EventManager.h>
#include <GameUtilities/Event/PushState.h>
#include <GameUtilities/Event/Click.h>
#include "States/Id.h"
#include "Gui/id.h"
#include "Editor/Map.h"
#include "Editor/Functions.h"
#include "Settings.h"
#include "config.h"
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
        newLevel->setText((newLevel->getText()));
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

                        map.addAssetDirectory(boost::filesystem::path(BUILD_DIR + "/Assets/"));
                        map.addAssetDirectory(boost::filesystem::path(SOURCE_DIR + "/Assets/"));

                        for(std::size_t i = 0; i < map.getAssetDirectory().size(); ++i)
                        {

                            boost::filesystem::path path = map.getAssetDirectory()[i];
                            boost::filesystem::create_directories(path);
                            path.append("Level/");
                            boost::filesystem::create_directories(path);
                            path.append(map.name);
                            path.append("/");
                            boost::filesystem::create_directories(path);

                        }




                        map.write();
                        Settings::map = map.name;
                        GU::Evt::EventManager::inst().Post<GU::Evt::PushState>(States::Id::MAP_CREATION_STATE);
                    }
                }
            }
        }
    });
    tgui::Button::Ptr backButton = tgui::Button::create("Back");
    backButton->connect("pressed", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::MAP_LOADER);
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
