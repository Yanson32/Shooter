#include "Editor/EditorGeneralPanel.h" 
//#include "Gui/id.h"
//#include "Settings.h"
#include "Editor/Functions.h"
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
    this->red = properties->appendEditBox("Red", "");
    red->connect("TextChanged", [&](){
        std::string text = red->getText();

        if(!text.empty())
        {
            for(std::size_t i = 0; i < text.size(); ++i)
            {
                if(!isdigit(text[i]))
                    return;
            }

            map.red = toInt(text);
            map.write();
        }
    });
    this->blue = properties->appendEditBox("Blue", "");
    blue->connect("TextChanged", [&](){
        std::string text = blue->getText();

        if(!text.empty())
        {
            for(std::size_t i = 0; i < text.size(); ++i)
            {
                if(!isdigit(text[i]))
                    return;
            }

            map.blue = toInt(text);
            map.write();
        }
    });
    this->green = properties->appendEditBox("Green", "");
        green->connect("TextChanged", [&](){
        std::string text = green->getText();

        if(!text.empty())
        {
            for(std::size_t i = 0; i < text.size(); ++i)
            {
                if(!isdigit(text[i]))
                    return;
            }

            map.green = toInt(text);
            map.write();
        }
    });
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
    red->setText(toString(map.red));
    blue->setText(toString(map.blue));
    green->setText(toString(map.green));

}

bool EditorGeneralPanel::drawGrid() const
{
    return grid->isChecked();
}

EditorGeneralPanel::~EditorGeneralPanel()
{
    //dtor
}
