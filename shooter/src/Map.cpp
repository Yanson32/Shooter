#include "Map.h"
#include <string>
#include <fstream>
#include <iostream>
#include "config.h"
#include <boost/filesystem.hpp>
#include <cassert>
Map::Map()
{
    //ctor

}

void Map::read()
{
    std::string sourceDir = getSourceDir() + name + ".map";;
    std::ifstream sourceStream(sourceDir);
    if(!sourceStream)
        return;

    std::getline(sourceStream, name);
    sourceStream >> width;
    sourceStream >> height;
    sourceStream >> ordering;
    sourceStream >> red;
    sourceStream >> blue;
    sourceStream >> green;
    std::size_t size;
    sourceStream >> size;
    for(std::size_t i = 0; i < size; ++i)
    {
        std::string temp;
        sourceStream >> temp;

        if(layerExists(temp))
        {
            layers[temp].read(name);
            std::cout << "Layer exists " << std::endl;
        }
        else
        {
            Layer layer;
            layer.name = temp;
            layer.read(name);
            layers[temp] = layer;
        }
    }
    sourceStream.close();
}

void Map::write()
{
    std::vector<std::string> dir = getAllDir();

    for(int i = 0; i < dir.size(); ++i)
    {
        std::string file = dir[i] + name + ".map";
        std::cout << "file " << file << std::endl;
        std::ofstream steam(file);

        steam << name << std::endl;
        steam << width << std::endl;
        steam << height << std::endl;
        steam << ordering << std::endl;
        steam << red << std::endl;
        steam << blue << std::endl;
        steam << green << std::endl;

        steam << layers.size() << std::endl;
        for(auto &element : layers)
        {
            steam << element.first << std::endl;
            element.second.write(name);
        }
        steam.close();
    }
}

void Map::remove()
{
    boost::filesystem::path source(getSourceDir() + this->name + ".map");
    boost::filesystem::path build(getBuildDir() + this->name + ".map");
    boost::filesystem::remove(source);
    boost::filesystem::remove(build);
}

std::string Map::getSourceDir() const
{
    std::string temp = SOURCE_DIR + "/Assets/Level/" + name + "/";
    boost::filesystem::create_directory(temp);
    return temp;
}


std::string Map::getBuildDir() const
{
    std::string temp = BUILD_DIR + "/Assets/Level/" + name + "/";
    boost::filesystem::create_directory(temp);
    return temp;
}

void Map::addLayer(Layer layer)
{
    assert(!layerExists(layer.name));
    layers[layer.name] = layer;
}

Layer& Map::getLayer(const std::string &name)
{
    assert(layerExists(name));

    if(layers.find(name) != layers.end())
        return layers.find(name)->second;
}

bool Map::layerExists(const std::string &name)
{
    if(layers.find(name) == layers.end())
        return false;

    return true;
}

std::size_t Map::getLayerCount() const
{
    return layers.size();
}

Layer& Map::operator [] (const std::size_t index)
{
    assert(index < layers.size());
    assert(index >= 0);

    std::size_t count = 0;
    for(auto it = layers.begin(); layers.begin() != layers.end(); ++it)
    {
        if(count == index)
        {
            return it->second;
        }
        ++count;
    }

    throw std::runtime_error("Out of bounds");
}

bool Map::removeLayer(const std::string &layer)
{
    assert(layerExists(layer));
    layers.erase(layers.find(layer));
    std::vector<std::string> dir = getAllDir();

    for(int i = 0; i < dir.size(); ++i)
    {
        std::string file = dir[i] + layer + ".lay";
        boost::filesystem::path path(file);
        boost::filesystem::remove(path);
    }

    this->write();
}

std::vector<std::string> Map::getAllDir() const
{
    return {getSourceDir(), getBuildDir()};
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto it = layers.begin(); it != layers.end(); ++it)
        target.draw(it->second);
}

void Map::layerSelected(const std::string &name)
{
    for(auto it = layers.begin(); it != layers.end(); ++it)
    {
        it->second.selected = false;
        if(it->first == name)
            it->second.selected = true;
    }
}

void Map::init()
{
    for(auto it = layers.begin(); it != layers.end(); ++it)
    {
        it->second.init({width, height});
    }
}


Map::~Map()
{
    //dtor
    write();
}
