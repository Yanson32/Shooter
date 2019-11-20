#include "Gui/MapLoader.h"
#include "Events/EventManager.h"
#include <GameUtilities/Event/Click.h>
#include "Gui/id.h"
#include "Settings.h"
#include <boost/filesystem.hpp>
#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include <GameUtilities/Event/PushState.h>
#include "States/Id.h"

MapLoader::MapLoader()
{
    //ctor
    std::vector<sf::String> levels;
  boost::filesystem::path p = BUILD_DIR.toAnsiString() + "/Assets/Level/";
  boost::filesystem::directory_iterator it{p};
  while (it != boost::filesystem::directory_iterator{})
  {
    sf::String temp = it->path().stem().string();
    it++;
    levels.push_back(temp);
  }


    combo = content->appendComboBox("Load Level", levels);
    combo->setSelectedItem(Settings::currentMap);

    tgui::Button::Ptr backButton = tgui::Button::create("Back");
    backButton->connect("pressed", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::INTRO);
    });
    buttonLayout->add(backButton);
    tgui::Button::Ptr createButton = tgui::Button::create("Create");
    buttonLayout->add(createButton);
    createButton->connect("pressed", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::NEW_LEVEL);
    });
    loadButton = tgui::Button::create("Load");
    buttonLayout->add(loadButton);
    loadButton->connect("pressed", [&](){

        if(combo->getSelectedItem() != "")
        {
            Settings::map = combo->getSelectedItem();
            EventManager::inst().Post<GU::Evt::PushState>(States::Id::MAP_CREATION_STATE);
        }

    });

    deleteButton = tgui::Button::create("Delete");
    buttonLayout->add(deleteButton);
    deleteButton->connect("pressed", [&](){
        sf::String temp = combo->getSelectedItem();
        Map map;
        map.name = temp.toAnsiString();
        map.remove();
        combo->removeItem(temp);
    });
}

MapLoader::~MapLoader()
{
    //dtor
}
