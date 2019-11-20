#include "Gui/Editor/EditorLayersPanel.h"
#include "Gui/id.h"

EditorLayersPanel::EditorLayersPanel(const int width, const int height)
{
    //ctor
    getRenderer()->setBackgroundColor(sf::Color::Transparent);
    properties.reset(new PropertiesPanel(width, height));
    properties->appendSection("Layers");
    properties->appendEditBox("blah", "");
    this->add(properties);
}

EditorLayersPanel::~EditorLayersPanel()
{
    //dtor
}
