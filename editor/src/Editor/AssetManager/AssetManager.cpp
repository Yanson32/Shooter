#include "Editor/AssetManager/AssetManager.h"
#include "Events/EventManager.h"
#include <GameUtilities/Event/Click.h>
#include "Editor/Events/id.h"

AssetManager::AssetManager(Map &newMap):
map(newMap),
imagePanel(new AssetManagerImagePanel(AssetManager::WIDTH, AssetManager::DIALOG_HEIGHT)),
tilesheetPanel(new AssetManagerTilesheetPanel(AssetManager::WIDTH, AssetManager::DIALOG_HEIGHT)),
musicPanel(new AssetManagerMusicPanel(AssetManager::WIDTH, AssetManager::DIALOG_HEIGHT)),
effectPanel(new AssetManagerEffectPanel(AssetManager::WIDTH, AssetManager::DIALOG_HEIGHT))
{
    //ctor
    effectsDirectory.push_back("/home/me/Desktop/Untitled Folder");
    effectsDirectory.push_back("/home/me/Desktop/Untitled Folder2");
    effectsDirectory.push_back("/home/me/Desktop/Untitled Folder3");

    imagePanel->getRenderer()->setBackgroundColor(AssetManager::backgroundColor);
    tilesheetPanel->getRenderer()->setBackgroundColor(AssetManager::backgroundColor);
    musicPanel->getRenderer()->setBackgroundColor(AssetManager::backgroundColor);
    effectPanel->getRenderer()->setBackgroundColor(AssetManager::backgroundColor);
    tabs = tgui::Tabs::create();

    tabLayout = tgui::HorizontalLayout::create();
    tabLayout->setSize(WIDTH, LAYOUT_HEIGHT);
    tabLayout->add(tabs);

    tabs->add("Image");
    tabs->add("TileSheet");
    tabs->add("Effect");
    tabs->add("Music");
    this->add(tabLayout);

    setSize(WIDTH, DIALOG_HEIGHT);

    buttonLayout = tgui::HorizontalLayout::create();
    buttonLayout->setPosition(0, DIALOG_HEIGHT - LAYOUT_HEIGHT);
    buttonLayout->setSize({WIDTH, LAYOUT_HEIGHT});


    closeButton = tgui::Button::create("Close");
    closeButton->connect("pressed", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Button::ASSET_DIALOG_CLOSE);
    });
    buttonLayout->add(closeButton);

    saveButton = tgui::Button::create("Save");
    saveButton->connect("pressed", [&](){
        sf::String text = tabs->getSelected();
        if(text == "Image")
        {
            imagePanel->save(map.getImageDirectory());
        }
        else if (text == "TileSheet")
        {
            tilesheetPanel->save(map.getTilesheetDirectory());
        }
        else if (text == "Music")
        {
            musicPanel->save(map.getMusicDirectory());
        }
        else if (text == "Effect")
        {
            effectPanel->save(map.getEffectsDirectory());
        }
    });
    buttonLayout->add(saveButton);

    this->add(buttonLayout);
    imagePanel->setPosition(0, LAYOUT_HEIGHT);
    imagePanel->setSize(WIDTH, DIALOG_HEIGHT - (2 * LAYOUT_HEIGHT));
    this->add(imagePanel);

    tilesheetPanel->setPosition(0, LAYOUT_HEIGHT);
    tilesheetPanel->setSize(WIDTH, DIALOG_HEIGHT - (2 * LAYOUT_HEIGHT));
    this->add(tilesheetPanel);

    musicPanel->setPosition(0, LAYOUT_HEIGHT);
    musicPanel->setSize(WIDTH, DIALOG_HEIGHT - (2 * LAYOUT_HEIGHT));
    this->add(musicPanel);

    effectPanel->setPosition(0, LAYOUT_HEIGHT);
    effectPanel->setSize(WIDTH, DIALOG_HEIGHT - (2 * LAYOUT_HEIGHT));
    this->add(effectPanel);

    tabs->connect("TabSelected", [&](){
        sf::String temp = tabs->getSelected();
        if(temp == "Image")
        {
            this->removeAllWidgets();
            this->add(tabLayout);
            this->add(imagePanel);
            this->add(buttonLayout);
        }
        else if(temp == "TileSheet")
        {
            this->removeAllWidgets();
            this->add(tabLayout);
            this->add(tilesheetPanel);
            this->add(buttonLayout);
        }
        else if(temp == "Music")
        {
            this->removeAllWidgets();
            this->add(tabLayout);
            this->add(musicPanel);
            this->add(buttonLayout);
        }
        else if(temp == "Effect")
        {
            this->removeAllWidgets();
            this->add(tabLayout);
            this->add(effectPanel);
            this->add(buttonLayout);
        }
    });

}

AssetManager::~AssetManager()
{
    //dtor
}
