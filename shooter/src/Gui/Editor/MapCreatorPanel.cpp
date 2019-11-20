#include "Gui/Editor/MapCreatorPanel.h"
#include "Events/Events.h"
#include <iostream>
#include "States/Id.h"
#include <GameUtilities/Event/Click.h>
#include "Gui/id.h"
#include "Events/EventManager.h"
#include "Gui/id.h"
#include <GameUtilities/Event/Click.h>
#include "Settings.h"
#include "Functions.h"
MapCreatorPanel::MapCreatorPanel(Map &map)
{
    //ctor
    getRenderer()->setBackgroundColor(sf::Color::Transparent);
    setSize({300, Settings::screen.y});
    setPosition({0, 0});

    tabLayout = tgui::HorizontalLayout::create();
    tabLayout->setSize("100%", 50);
    tabs = tgui::Tabs::create();
    tabLayout->add(tabs);
    //tabs->setPosition({300, 100});
    tabs->add("General");
    tabs->add("Layers");
    tabs->add("Object");

    tabs->setTabVisible(0, true);

    buttonLayout = tgui::HorizontalLayout::create();
    buttonLayout->setSize(300, 50);
    buttonLayout->setPosition(0, Settings::screen.y - 50);
    this->add(buttonLayout);

    backButton = tgui::Button::create("Back");
    backButton->connect("pressed", [&](){
        EventManager::inst().Post<GU::Evt::Pop>();
    });
    buttonLayout->add(backButton);

    saveButton = tgui::Button::create("Save");
    saveButton->connect("pressed", [&](){
        map.name = generalPanel->name->getText();
        map.height = toInt(generalPanel->height->getText());
        map.width = toInt(generalPanel->width->getText());
        map.ordering = toInt(generalPanel->ordering->getText());
        map.tileWidth = toInt(generalPanel->tileWidth->getText());
        map.tileHeight = toInt(generalPanel->tileHeight->getText());
        map.write();
    });
    buttonLayout->add(saveButton);

    loadButton = tgui::Button::create("Load");
    buttonLayout->add(loadButton);

        this->add(buttonLayout);

    generalPanel.reset(new EditorGeneralPanel(300, Settings::screen.y - 150, map));
    generalPanel->setPosition(0, 75);

    //generalPanel->setSize(300, 400);
    //this->add(generalPanel);



    layersPanel.reset(new EditorLayersPanel(300, Settings::screen.y - 150));
    layersPanel->setPosition(0, 75);
    //layersPanel->setSize(300, 400);

    objectPanel.reset(new EditorObjectPanel(300, Settings::screen.y - 150));
    objectPanel->setPosition(0, 75);
    //objectPanel->setSize(300, 400);

        tabs->connect("TabSelected", [&](){
        sf::String text = tabs->getSelected();
        if(text == "General")
        {
            std::cout << "General tab" << std::endl;
            this->removeAllWidgets();
            this->add(tabLayout);
            this->add(generalPanel);
            this->add(buttonLayout);
        }
        else if(text == "Layers")
        {
            std::cout << "Layers tab" << std::endl;
            this->removeAllWidgets();
            this->add(tabLayout);
            this->add(layersPanel);
            this->add(buttonLayout);
        }
        else if(text == "Object")
        {
            this->removeAllWidgets();
            this->add(tabLayout);
            this->add(objectPanel);
            this->add(buttonLayout);
        }
    });

    tabs->select("General");
}

void MapCreatorPanel::onSavePressed()
{
    std::cout << "Saved Pressed" << std::endl;
}

void MapCreatorPanel::onLoadPressed()
{
    std::cout << "Load Pressed" << std::endl;
}

void MapCreatorPanel::onShowGrid()
{
    EventManager::inst().Post<ShowGrid>(true);
}

void MapCreatorPanel::onDontShowGrid()
{
    EventManager::inst().Post<ShowGrid>(false);
}

void MapCreatorPanel::onSnapToGrid()
{
    EventManager::inst().Post<SnapToGrid>(true);
}

void MapCreatorPanel::onDontSnapToGrid()
{
    EventManager::inst().Post<SnapToGrid>(false);
}

void MapCreatorPanel::onAddLayer()
{
    auto text = layerNameBox->getText();
    layerNameBox->setText("");
    layerListBox->addItem(text);
}

void MapCreatorPanel::init()
{
    generalPanel->init();
}

MapCreatorPanel::~MapCreatorPanel()
{
    //dtor
}
