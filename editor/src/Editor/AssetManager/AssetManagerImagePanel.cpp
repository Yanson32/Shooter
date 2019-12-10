#include "Editor/AssetManager/AssetManagerImagePanel.h"
#include <iostream>
#include <boost/filesystem.hpp>
AssetManagerImagePanel::AssetManagerImagePanel(const int width, const int height):
PropertiesPanel(width, height)
{
    //ctor
    //getRenderer()->setBackgroundColor(sf::Color::Green);
    this->appendSpacer();
    pathBox = this->appendEditBox("Path", "");
    this->appendEditBox("Tags", "");

}

void AssetManagerImagePanel::save(const std::vector<boost::filesystem::path> &outputDirectory)
{
    if(outputDirectory.empty())
        return;

    sf::String text = pathBox->getText();
    if(text.isEmpty())
        return;

    boost::filesystem::path source(text.toAnsiString());

    if(!boost::filesystem::exists(source))
        return;

    for(std::size_t i = 0; i < outputDirectory.size(); ++i)
    if(!boost::filesystem::exists(outputDirectory[i]))
        if(!boost::filesystem::create_directories(outputDirectory[i]))
            return;


    //Create file
    for(std::size_t i = 0; i < outputDirectory.size(); ++i)
    {

        boost::filesystem::path destination(outputDirectory[i]);

        if(destination.string().back() == '/')
            destination += source.stem().string();
        else
            destination /= source.stem().string();

        destination += source.extension().string();

        boost::filesystem::copy_file(source, destination);

    }

}

AssetManagerImagePanel::~AssetManagerImagePanel()
{
    //dtor
}
