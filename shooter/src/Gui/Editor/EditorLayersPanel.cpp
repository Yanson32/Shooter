#include "Gui/Editor/EditorLayersPanel.h"
#include "Gui/id.h"
#include "Map.h"
#include "Layer.h"
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include "config.h"
#include "Functions.h"
EditorLayersPanel::EditorLayersPanel(const int width, const int height, Map &newMap):map(newMap)//:
//layersBox(new LayersListBox({0, 0}, {width, height / 2}, map))
{
    //ctor
    getRenderer()->setBackgroundColor(sf::Color::Transparent);

    listBox = tgui::ListBox::create();
    listBox->setSize(300, 200 - 40);
    //listBox->getRenderer()->setBackgroundColor(sf::Color::Transparent);
    listBox->setPosition(0, 0);
    this->add(listBox);
    listBox->connect("ItemSelected", [&](){
        sf::String text = listBox->getSelectedItem();

        if(!text.isEmpty())
        {
            if(!map.layerExists(text.toAnsiString()))
            {
                Layer layer;
                layer.name = text;
                map.addLayer(layer);
            }
            map.getLayer(text).read(map.name);
            properties->init(map.getLayer(text));
        }
    });


    controlsLayout = tgui::HorizontalLayout::create();
    controlsLayout->setSize("100%", 20);
    controlsLayout->setPosition(0, 200 - 40);
    this->add(controlsLayout);

    name = tgui::EditBox::create();
    controlsLayout->add(name);

    addButton = tgui::Button::create("Add");
    controlsLayout->add(addButton);
    addButton->connect("pressed", [&](){
        sf::String text = name->getText();

        std::vector<sf::String> items = listBox->getItems();
        items.push_back(""); //we dont want to allow the user to enter an empty string

        for(std::size_t i = 0; i < items.size(); ++i)
        {
            if(items[i] == text)
                return;
        }

        listBox->addItem(text);
        Layer layer;
        layer.name = text.toAnsiString();
        map.addLayer(layer);
        map.write();

    });


    removeButton = tgui::Button::create("Remove");
    controlsLayout->add(removeButton);
    removeButton->connect("pressed", [&](){
        std::string text = listBox->getSelectedItem();

        if(text == "")
            return;

        listBox->removeItem(text);
        if(map.layerExists(text))
            map.removeLayer(text);
    });


    properties.reset(new LayerPropertiesPanel(width, height));
    properties->setSize(width, height / 2 - 40);
    properties->setPosition(0, listBox->getSize().y + 40);
    this->add(properties);

    properties->zOrder->connect("TextChanged", [&](){

        std::string text = properties->name->getText().toAnsiString();
        map.getLayer(text).zOrder = toInt(properties->zOrder->getText());
        map.write();
    });

    properties->tileWidth->connect("TextChanged", [&](){
        std::string text = properties->name->getText().toAnsiString();
        map.getLayer(text).width = toInt(properties->tileWidth->getText());
        map.write();
    });

    properties->tileHeight->connect("TextChanged", [&](){
        std::string text = properties->name->getText().toAnsiString();
        map.getLayer(text).height = toInt(properties->tileHeight->getText());
        map.write();
    });

    properties->combo->connect("ItemSelected", [&](){
        std::string text = properties->name->getText().toAnsiString();
        map.getLayer(text).type = properties->combo->getSelectedItem().toAnsiString();
        map.write();
    });

    properties->visible->connect("checked", [&](){
        std::string text = properties->name->getText().toAnsiString();
        map.getLayer(text).visible = properties->visible->isChecked();
        map.write();
    });

    properties->visible->connect("unchecked", [&](){
        std::string text = properties->name->getText().toAnsiString();
        map.getLayer(text).visible = properties->visible->isChecked();
        map.write();
    });

    properties->grid->connect("checked", [&](){
        std::string text = properties->name->getText().toAnsiString();
        map.getLayer(text).grid = properties->grid->isChecked();
        map.write();
    });

    properties->grid->connect("unchecked", [&](){
        std::string text = properties->name->getText().toAnsiString();
        map.getLayer(text).grid = properties->grid->isChecked();
        map.write();
    });
}

void EditorLayersPanel::init()
{
        //Initialize list box
//    std::string directory = SOURCE_DIR;
//    directory += "/Assets/Layers/";
//    directory += map.name;
//    directory += "/";
//    std::cout << "directory " << directory << std::endl;
//    boost::filesystem::path path(directory);
//
//    if(boost::filesystem::is_directory(path)) {
//        for(auto& entry : boost::filesystem::directory_iterator(path))
//            listBox->addItem(entry.path().stem().string());
//    }

    for(std::size_t i = 0; i < map.getLayerCount(); ++i)
    {
        Layer &layer = map[i];
        std::cout << "layer name " << layer.name << std::endl;
        listBox->addItem(layer.name);
    }

    std::cout <<  "Layer Count " << map.getLayerCount() << std::endl;
}

EditorLayersPanel::~EditorLayersPanel()
{
    //dtor
}
