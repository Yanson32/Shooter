#include "Editor/MapCreatorPanel.h"
//#include "Events/Events.h"
#include <iostream>
//#include "States/Id.h"
#include <GameUtilities/Event/Click.h>
//#include "Gui/id.h"
#include <GameUtilities/Event/EventManager.h>
#include <GameUtilities/Event/Click.h>
//#include "Settings.h"
#include "Editor/Functions.h"
#include "Editor/Events/id.h"

MapCreatorPanel::MapCreatorPanel(Map &map)
{
    const int HEIGHT = 450;
    const int WIDTH = 800;
    //ctor
    getRenderer()->setBackgroundColor(sf::Color::Black);
    setPosition({0, 0});
    setSize(300, 600);
    tabLayout = tgui::HorizontalLayout::create();
    tabLayout->setSize("100%", 50);

    tabs = tgui::Tabs::create();
    tabLayout->add(tabs);
    tabs->setPosition({0, 100});
    tabs->add("General");
    tabs->add("Layers");
    tabs->add("Object");

    tabs->setTabVisible(0, true);

    buttonLayout = tgui::HorizontalLayout::create();
    buttonLayout->setSize(300, 50);
    buttonLayout->setPosition(0, HEIGHT - 50);
    this->add(buttonLayout);

//    backButton = tgui::Button::create("Back");
//    backButton->connect("pressed", [&](){
//       // EventManager::inst().Post<GU::Evt::Pop>();
//    });
//    buttonLayout->add(backButton);

    saveButton = tgui::Button::create("Save");
    saveButton->connect("pressed", [&](){
        map.name = generalPanel->name->getText();
        map.height = toInt(generalPanel->height->getText());
        map.width = toInt(generalPanel->width->getText());
        map.ordering = toInt(generalPanel->ordering->getText());
        map.init();
        map.write();
    });
    buttonLayout->add(saveButton);

    loadButton = tgui::Button::create("Load");
    buttonLayout->add(loadButton);


    tgui::Button::Ptr assetButton = tgui::Button::create("Assets");
    assetButton->connect("pressed", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Button::ASSET);
    });
    buttonLayout->add(assetButton);
    this->add(buttonLayout);

    generalPanel.reset(new EditorGeneralPanel(300, HEIGHT - 150, map));
    generalPanel->setPosition(0, 75);



    layersPanel.reset(new EditorLayersPanel(300, HEIGHT - 150, map));
    layersPanel->setPosition(0, 75);

    objectPanel.reset(new EditorObjectPanel(300, HEIGHT - 150));
    objectPanel->setPosition(0, 75);

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
    //EventManager::inst().Post<ShowGrid>(true);
}

void MapCreatorPanel::onDontShowGrid()
{
   // EventManager::inst().Post<ShowGrid>(false);
}

void MapCreatorPanel::onSnapToGrid()
{
    //EventManager::inst().Post<SnapToGrid>(true);
}

void MapCreatorPanel::onDontSnapToGrid()
{
    //EventManager::inst().Post<SnapToGrid>(false);
}

void MapCreatorPanel::onAddLayer()
{
    auto text = layerNameBox->getText();
    layerNameBox->setText("");
    layerListBox->addItem(text);
}

void MapCreatorPanel::init()
{
    layersPanel->init();
    generalPanel->init();

}

bool MapCreatorPanel::drawGrid() const
{
    return generalPanel->drawGrid();
}
MapCreatorPanel::~MapCreatorPanel()
{
    //dtor
}
