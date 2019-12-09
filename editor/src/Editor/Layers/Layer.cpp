#include "Editor/Layers/Layer.h"
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

void Layer::read(boost::filesystem::path path, const std::string &map)
{
    path.append("Level");
    path.append(map);
    path /= map + ".lay";

    boost::filesystem::ifstream source(path);

    if(!source)
    {
        std::string msg("Unable to read layer ");
        msg += path.string();
        throw std::runtime_error(msg);
    }
    source >> name;
    source >> visible;
    source >> grid;
    source >> type;
    source >> width;
    source >> height;
    source >> zOrder;

    source.close();
}

void Layer::write(const std::vector<boost::filesystem::path> &directories, const std::string &map)
{
    for(std::size_t i = 0; i < directories.size(); ++i)
    {
        boost::filesystem::path path = directories[i];
        path.append("Level");
        path.append(map);
        path /= map;
        path /= ".lay";

        boost::filesystem::ofstream steam(path);

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
    //layerGrid.init(mapSize, {width, height});
}

Layer::~Layer()
{
    //dtor
}
