#include "MapCreatorPanel.h"
#include "Events/Events.h"
#include <iostream>
MapCreatorPanel::MapCreatorPanel()
{
    //ctor
    //setBackgroundColor(sf::Color::Blue);
    setSize({300, 600});
    setPosition({0, 0});

    generalTab = tgui::Button::create("General");
    generalTab->connect("pressed", &MapCreatorPanel::generateGeneralScheme, this);
    generalTab->setPosition({BORDER, BORDER});
    generalTab->setSize({TAB_DIMENTIONS, TAB_DIMENTIONS});

    layerTab = tgui::Button::create("Layer");
    layerTab->connect("pressed", &MapCreatorPanel::generateLayerScheme, this);
    layerTab->setPosition({BORDER, BORDER});
    layerTab->setSize({TAB_DIMENTIONS, TAB_DIMENTIONS});

    objectTab = tgui::Button::create("Object");
    objectTab->connect("pressed", &MapCreatorPanel::generateObjectScheme, this);
    objectTab->setPosition({BORDER, BORDER});
    objectTab->setSize({TAB_DIMENTIONS, TAB_DIMENTIONS});

    saveButton = tgui::Button::create("Save");
    saveButton->connect("pressed", &MapCreatorPanel::onSavePressed, this);
    saveButton->setPosition({BORDER, BORDER});
    saveButton->setSize({TAB_DIMENTIONS, TAB_DIMENTIONS});

    loadButton = tgui::Button::create("Load");
    loadButton->connect("pressed", &MapCreatorPanel::onLoadPressed, this);
    loadButton->setPosition({BORDER, BORDER});
    loadButton->setSize({TAB_DIMENTIONS, TAB_DIMENTIONS});

    showGridBox = tgui::CheckBox::create("Show Grid");
    showGridBox->connect("checked", &MapCreatorPanel::onShowGrid, this);
    showGridBox->connect("unchecked", &MapCreatorPanel::onDontShowGrid, this);
    showGridBox->setPosition({BORDER, BORDER * 2 + BUTTON_HEIGHT});

    snapToGrid = tgui::CheckBox::create("Snap to grid");
    snapToGrid->connect("checked", &MapCreatorPanel::onSnapToGrid, this);
    snapToGrid->connect("unchecked", &MapCreatorPanel::onDontSnapToGrid, this);
    snapToGrid->setPosition({BORDER, BORDER * 2 + (BUTTON_HEIGHT * 2)});

    layerListBox = tgui::ListBox::create();
    layerListBox->setPosition({BORDER, BORDER * 2 + BUTTON_HEIGHT});
    layerListBox->setSize({(PANEL_WIDTH - BORDER - BORDER), layerListBox->getSize().y});

    layerNameBox = tgui::EditBox::create();
    layerNameBox->setText("Name of layer");
    comboBox = tgui::ComboBox::create();
    comboBox->addItem("Image", "Image");
    comboBox->addItem("Object", "Object");
    comboBox->setSelectedItemById("Image");

    addLayerButton = tgui::Button::create("Add Layer");
    addLayerButton->connect("pressed", &MapCreatorPanel::onAddLayer, this);
    addLayerButton->setSize(PANEL_WIDTH / 2 - BORDER, addLayerButton->getSize().y);


    generateGeneralScheme();

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

void MapCreatorPanel::generateTab()
{
    tgui::HorizontalLayout::Ptr tabLayout = tgui::HorizontalLayout::create();
    tabLayout->setSize({TAB_DIMENTIONS * NUMBER_OF_TABS, TAB_DIMENTIONS});
    tabLayout->setPosition(BORDER, BORDER);
    add(tabLayout);


    tabLayout->add(generalTab);
    tabLayout->add(layerTab);
    tabLayout->add(objectTab);

}

void MapCreatorPanel::generateGeneralScheme()
{
    this->removeAllWidgets();
    generateTab();

    tgui::HorizontalLayout::Ptr controlsLayout = tgui::HorizontalLayout::create();
    controlsLayout->setSize({PANEL_WIDTH - (BORDER * 2), BUTTON_HEIGHT});
    controlsLayout->setPosition(BORDER, PANEL_HEIGHT - BUTTON_HEIGHT - BORDER);
    add(controlsLayout);

    controlsLayout->add(saveButton);
    controlsLayout->add(loadButton);

    this->add(showGridBox);
    this->add(snapToGrid);
}

void MapCreatorPanel::generateLayerScheme()
{
    this->removeAllWidgets();
    generateTab();

    this->add(layerListBox);

    const unsigned OFFSET = 2;
    tgui::HorizontalLayout::Ptr controlsLayout = tgui::HorizontalLayout::create();
    controlsLayout->setSize({PANEL_WIDTH - (BORDER * 2) + OFFSET * 2, BUTTON_HEIGHT / 2});
    controlsLayout->setPosition(BORDER - OFFSET, layerListBox->getPosition().y + layerListBox->getSize().y);

    add(controlsLayout);
    controlsLayout->add(layerNameBox);
    controlsLayout->add(comboBox);

    addLayerButton->setPosition(BORDER, controlsLayout->getPosition().y + controlsLayout->getSize().y);
    this->add(addLayerButton);
}

void MapCreatorPanel::generateObjectScheme()
{
    this->removeAllWidgets();
    generateTab();
}

MapCreatorPanel::~MapCreatorPanel()
{
    //dtor
}
