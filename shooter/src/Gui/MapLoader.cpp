#include "Gui/MapLoader.h"
#include <GameUtilities/Event/EventManager.h>
#include <GameUtilities/Event/Click.h>
#include "Gui/id.h"
#include "Settings.h"
#include <boost/filesystem.hpp>
#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Editor/Map.h"
#include <GameUtilities/Event/PushState.h>
#include "States/Id.h"

MapLoader::MapLoader(Map &newMap):
map(newMap)
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
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::INTRO);
    });
    buttonLayout->add(backButton);
    tgui::Button::Ptr createButton = tgui::Button::create("Create");
    buttonLayout->add(createButton);
    createButton->connect("pressed", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::NEW_LEVEL);
    });
    loadButton = tgui::Button::create("Load");
    buttonLayout->add(loadButton);
    loadButton->connect("pressed", [&](){

        if(combo->getSelectedItem() != "")
        {
            Settings::map = combo->getSelectedItem();
            map.name = Settings::map;
            map.read();
            Settings::currentLevel = map.ordering;
            GU::Evt::EventManager::inst().Post<GU::Evt::PushState>(States::Id::MAP_CREATION_STATE);
        }

    });

    deleteButton = tgui::Button::create("Delete");
    buttonLayout->add(deleteButton);
    deleteButton->connect("pressed", [&](){
        sf::String temp = combo->getSelectedItem();

        if(temp.isEmpty())
            return;

//        Map map;
//        map.addAssetDirectory(boost::filesystem::path(BUILD_DIR + "/Assets/"));
//        map.addAssetDirectory(boost::filesystem::path(SOURCE_DIR + "/Assets/"));
//        map.name = temp.toAnsiString();
//        map.remove();
//
//        std::vector<boost::filesystem::path> dir = map.getAssetDirectory();
//        boost::filesystem::path dir1 = dir[0];
//        boost::filesystem::path dir2  = dir[1];
//
//        dir1.append("Level/");
//        dir1.append(temp.toAnsiString());
//        dir1.append("/");
//
//        dir2.append("Level/");
//        dir2.append(temp.toAnsiString());
//        dir2.append("/");
//
//        std::cout << "dir1 " << dir1 << boost::filesystem::exists(dir1) << std::endl;
//        if(!boost::filesystem::exists(dir1) && !boost::filesystem::exists(dir2))
//            combo->removeItem(temp);

    });
}

void MapLoader::init()
{
    combo->removeAllItems();

    boost::filesystem::path p = BUILD_DIR.toAnsiString() + "/Assets/Level/";
    boost::filesystem::directory_iterator it{p};
    while (it != boost::filesystem::directory_iterator{})
    {
        sf::String temp = it->path().stem().string();
        it++;
        combo->addItem(temp);
    }
}
MapLoader::~MapLoader()
{
    //dtor
}
