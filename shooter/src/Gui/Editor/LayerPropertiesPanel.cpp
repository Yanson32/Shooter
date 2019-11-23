#include "Gui/Editor/LayerPropertiesPanel.h"
#include "Functions.h"
LayerPropertiesPanel::LayerPropertiesPanel(const int width, const int height):
PropertiesPanel(width, height)
{
    //ctor
    name = appendSection("Name");
    visible = appendCheckBox("Visible");
    grid = appendCheckBox("Grid");
    std::vector<sf::String> choices = {"Image", "Object"};
    combo = appendComboBox("Type", choices);
    tileWidth = appendEditBox("Tile Width", "");
    tileHeight = appendEditBox("Tile Height", "");
    zOrder = appendEditBox("Z-Order", "");


}

void LayerPropertiesPanel::init(const Layer &layer)
{
    name->setText(layer.name);
    visible->setChecked(layer.visible);
    grid->setChecked(layer.grid);
    combo->setSelectedItem(layer.type);
    tileWidth->setText(toString(layer.width));
    tileHeight->setText(toString(layer.height));
    zOrder->setText(toString(layer.zOrder));
}

LayerPropertiesPanel::~LayerPropertiesPanel()
{
    //dtor
}
