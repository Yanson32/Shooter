#include "Editor/AssetManager/AssetManagerTilesheetPanel.h"
#include <iostream>
AssetManagerTilesheetPanel::AssetManagerTilesheetPanel(const int width, const int height):
PropertiesPanel(width, height)
{
    //ctor
    this->appendSpacer();
    pathBox = this->appendEditBox("Path", "");
    this->appendEditBox("Tile Width", "");
    this->appendEditBox("Tile Height", "");
    this->appendEditBox("Tags", "");

}
void AssetManagerTilesheetPanel::save(const std::vector<boost::filesystem::path> &tilesheetDirectory)
{
    if(tilesheetDirectory.empty())
        return;

    sf::String text = pathBox->getText();
    if(text.isEmpty())
        return;

    boost::filesystem::path source(text.toAnsiString());

    if(!boost::filesystem::exists(source))
        return;

    for(std::size_t i = 0; i < tilesheetDirectory.size(); ++i)
    if(!boost::filesystem::exists(tilesheetDirectory[i]))
        if(!boost::filesystem::create_directories(tilesheetDirectory[i]))
            return;


    //Create file
    for(std::size_t i = 0; i < tilesheetDirectory.size(); ++i)
    {

        boost::filesystem::path destination(tilesheetDirectory[i]);

        if(destination.string().back() == '/')
            destination += source.stem().string();
        else
            destination /= source.stem().string();

        destination += source.extension().string();

        boost::filesystem::copy_file(source, destination);

    }
}
AssetManagerTilesheetPanel::~AssetManagerTilesheetPanel()
{
    //dtor
}
