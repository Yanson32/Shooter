#include "Editor/Layer.h"
#include <fstream>
//#include "config.h"
#include <boost/filesystem.hpp>
#include <iostream>
Layer::Layer()
{
    //ctor
    name = "Name";
    visible = true;
    grid = false;
    type = "Image";
    width = 0;
    height = 0;
    zOrder = -1;
}

void Layer::read(const std::string &newBuildDir, const std::string &map)
{
    std::string layer = getFullPath(newBuildDir, map);
    std::ifstream source(layer);

    if(!source)
    {
        std::string msg("Unable to read layer ");
        msg += layer;
        throw std::runtime_error(msg);
    }
    source >> name;
    source >> visible;
    source >> grid;
    source >> type;
    source >> width;
    source >> height;
    source >> zOrder;
}

void Layer::write(const std::string &newBuildDir, const std::string &newSourceDir, const std::string &map)
{
    std::vector<std::string> dir = getAllPaths(newBuildDir, newSourceDir, map);
    for(std::size_t i = 0; i < dir.size(); ++i)
    {
        std::string temp = dir[i] + name + ".lay";
        std::cout << "Layer output " << temp << std::endl;
        std::ofstream steam(temp);

        steam << name << std::endl;
        steam << visible << std::endl;
        steam << grid << std::endl;
        steam << type << std::endl;
        steam << width << std::endl;
        steam << height << std::endl;
        steam << zOrder << std::endl;
        steam.close();
    }
}

std::string Layer::getFullPath(const std::string dir, const std::string &map) const
{
    std::string temp = dir;
//    temp += "Assets/Level/";
//    temp += map;
//    temp += "/";
    temp += name;
    temp += ".lay";

    return temp;
}

std::string Layer::getSourceDir(const std::string &map) const
{
    std::string temp =  source_directory + "/Assets/Level/" + map + "/";
    boost::filesystem::create_directory(temp);
    return temp;
}

std::string Layer::getBuildDir(const std::string &map) const
{
    std::string temp =  build_directory + "/Assets/Level/" + map + "/";
    boost::filesystem::create_directory(temp);
    return temp;
}

std::vector<std::string> Layer::getAllPaths(const std::string &newBuildDir, const std::string &newSourceDir, const std::string &map) const
{
    return {newSourceDir, newBuildDir};
}

void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto it = tiles.begin(); it != tiles.end(); ++it)
        target.draw(*it);

    if(grid && selected)
        target.draw(layerGrid);
}

void Layer::init(const sf::Vector2f &mapSize)
{
    if(mapSize.x <= 0 || mapSize.y <= 0)
        return;
    if(width <= 0 || height <=0)
        return;
    layerGrid.init(mapSize, {width, height});
}

Layer::~Layer()
{
    //dtor
}
