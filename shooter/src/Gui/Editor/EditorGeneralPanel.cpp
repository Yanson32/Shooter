#include "Gui/Editor/EditorGeneralPanel.h"
#include "Gui/id.h"
#include "Settings.h"
#include "Functions.h"
EditorGeneralPanel::EditorGeneralPanel(const int newWidth, const int newHeight, Map &newMap):
map(newMap)
{
    //ctor
    getRenderer()->setBackgroundColor(sf::Color::Transparent);
    properties.reset(new PropertiesPanel(newWidth, newHeight));
    this->name = properties->appendEditBox("Name", "");
    this->width = properties->appendEditBox("Map Width", "");
    this->height = properties->appendEditBox("Map Height", "");
    this->ordering = properties->appendEditBox("Ordering", "");
    tileWidth = properties->appendEditBox("Tile Width", "");
    tileHeight = properties->appendEditBox("Tile Height", "");
    this->grid = properties->appendCheckBox("Grid");
    this->snap = properties->appendCheckBox("Snap To Grid");
    this->add(properties);
}

void EditorGeneralPanel::init()
{
    name->setText(map.name);
    width->setText(toString(map.width));
    height->setText(toString(map.height));
    ordering->setText(toString(map.ordering));
    tileWidth->setText(toString(map.tileWidth));
    tileHeight->setText(toString(map.tileHeight));

}

bool EditorGeneralPanel::drawGrid() const
{
    return grid->isChecked();
}

EditorGeneralPanel::~EditorGeneralPanel()
{
    //dtor
}
