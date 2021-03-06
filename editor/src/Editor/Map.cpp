#include "Editor/Map.h"
#include <string>
#include <fstream>
#include <iostream>
//#include "config.h"
#include <boost/filesystem.hpp>
#include <cassert>

Map::Map()
{
    //ctor

}

void Map::read()
{
    std::cout << "Read " << std::endl;
    std::vector<boost::filesystem::path> dir = getAssetDirectory();

    if(dir.empty())
        throw std::runtime_error("Error: There must be at least one directory");

    boost::filesystem::path path = dir[0];
std::cout << "Map::read path " << path << std::endl;
    if(!boost::filesystem::exists(path))
        throw std::runtime_error("Error: Directory does not exist");


    path.append("Level/");

    if(!boost::filesystem::exists(path))
        throw std::runtime_error("Error: Directory does not exist");

    path.append(name);
    path.append("/");

    if(!boost::filesystem::exists(path))
        throw std::runtime_error("Error: Directory does not exist");

    std::string fileName = name + ".map";
    //path /= fileName;
    std::cout << "path " << path << std::endl;
    if(!boost::filesystem::exists((path.string() + fileName)))
        throw std::runtime_error("Error: file does not exist");


    boost::filesystem::ifstream sourceStream(path.string() + fileName);
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
    std::cout << "size " << size << std::endl;
    for(std::size_t i = 0; i < size; ++i)
    {
        std::cout << "Loop " << std::endl;
        std::string temp;
        sourceStream >> temp;
        if(layerExists(temp))
        {
            layers[temp]->read(dir[0], name);
        }
        else
        {
            std::cout << "Layer " << temp << " does not exist" << std::endl;
            std::shared_ptr<Layer> layer(new Layer());
            layer->name = temp;
            layer->read(dir[0], name);
            layers[temp] = layer;
        }
    }
    sourceStream.close();
}

void Map::write()
{
    std::vector<boost::filesystem::path> dir = getAssetDirectory();

    if(dir.empty())
        return;

    for(int i = 0; i < dir.size(); ++i)
    {
        boost::filesystem::path path = dir[i];
        if(!boost::filesystem::exists(path))
            boost::filesystem::create_directories(path);

        path += "Level/";

        if(!boost::filesystem::exists(path))
            boost::filesystem::create_directories(path);

        path += name;
        path += "/";


        if(!boost::filesystem::exists(path))
            boost::filesystem::create_directories(path);

        std::string fileName = name + ".map";

        boost::filesystem::ofstream steam(path.string() + fileName);

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
            steam << element.second->name << std::endl;
            element.second->write(dir, this->name);
        }
        steam.close();
    }
}

void Map::remove()
{
    layers.clear();
    for(std::size_t i = 0; i < getAssetDirectory().size(); ++i)
    {
        boost::filesystem::path path = getAssetDirectory()[i];
        path.append("Level/");
        path.append(name);
        path.append("/");
        boost::filesystem::remove_all(path);
    }
}


bool Map::addLayer(std::shared_ptr<Layer> layer)
{
    auto val = layers.insert(std::pair<std::string, std::shared_ptr<Layer>>(layer->name, layer));

    return val.second;
}

std::shared_ptr<Layer> Map::getLayer(const std::string &name)
{
    assert(!layerExists(name));

    if(layers.find(name) != layers.end())
        return layers.find(name)->second;

    throw std::runtime_error("Error: Layer does not exist");
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

std::shared_ptr<Layer> Map::operator [] (const std::size_t index)
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
    if(!layerExists(layer))
        return false;

    //Remove layer object
    layers.erase(layers.find(layer));

    //Remove layer file
    std::vector<boost::filesystem::path> dir = getAssetDirectory();
    for(int i = 0; i < dir.size(); ++i)
    {
        boost::filesystem::path path = dir[i];
        path.append("Level");
        path.append(name);
        path /= layer + ".lay";
        boost::filesystem::remove(path);
    }

    this->write();

    return true;
}

//std::vector<std::string> Map::getAllDir() const
//{
//    return {getSourceDir(), getBuildDir()};
//}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto it = layers.begin(); it != layers.end(); ++it)
        target.draw((*it->second));
}

void Map::layerSelected(const std::string &name)
{
    for(auto it = layers.begin(); it != layers.end(); ++it)
    {
        it->second->selected = false;
        if(it->first == name)
            it->second->selected = true;
    }
}

void Map::init()
{
    for(auto it = layers.begin(); it != layers.end(); ++it)
    {
        it->second->init({static_cast<float>(width),static_cast<float>(height)});
    }
}

bool Map::addAssetDirectory(const boost::filesystem::path &path)
{
    if(path.string().empty())
        return false;

    if(!boost::filesystem::is_directory(path))
        if(!boost::filesystem::create_directories(path))
            return false;

    assetDirectories.push_back(path);

    return true;
}

std::vector<boost::filesystem::path> Map::getAssetDirectory() const
{
    return assetDirectories;
}

std::vector<boost::filesystem::path> Map::getImageDirectory() const
{
    std::vector<boost::filesystem::path> directory;

    for(std::size_t i = 0; i < assetDirectories.size(); ++i)
    {
        boost::filesystem::path path = assetDirectories[i];

        path /= "Image";
        directory.push_back(path);
    }

    return directory;
}

std::vector<boost::filesystem::path> Map::getLevelDirectory() const
{
    std::vector<boost::filesystem::path> directory;

    for(std::size_t i = 0; i < assetDirectories.size(); ++i)
    {
        boost::filesystem::path path = assetDirectories[i];

        path /= "Level";
        directory.push_back(path);
    }

    return directory;
}
std::vector<boost::filesystem::path> Map::getThemeDirectory() const
{
    std::vector<boost::filesystem::path> directory;

    for(std::size_t i = 0; i < assetDirectories.size(); ++i)
    {
        boost::filesystem::path path = assetDirectories[i];

        path /= "Theme";
        directory.push_back(path);
    }

    return directory;
}
std::vector<boost::filesystem::path> Map::getEffectsDirectory() const
{
    std::vector<boost::filesystem::path> directory;

    for(std::size_t i = 0; i < assetDirectories.size(); ++i)
    {
        boost::filesystem::path path = assetDirectories[i];

        path /= "Effects";
        directory.push_back(path);
    }

    return directory;
}
std::vector<boost::filesystem::path> Map::getMusicDirectory() const
{
    std::vector<boost::filesystem::path> directory;

    for(std::size_t i = 0; i < assetDirectories.size(); ++i)
    {
        boost::filesystem::path path = assetDirectories[i];

        path /= "Music";
        directory.push_back(path);
    }

    return directory;
}

std::vector<boost::filesystem::path> Map::getTilesheetDirectory() const
{
    std::vector<boost::filesystem::path> directory;

    for(std::size_t i = 0; i < assetDirectories.size(); ++i)
    {
        boost::filesystem::path path = assetDirectories[i];

        path /= "Tilesheet";
        directory.push_back(path);
    }

    return directory;
}

bool Map::loadLayer(const unsigned newOrdering)
{
    boost::filesystem::directory_iterator end;

    boost::filesystem::directory_iterator it{getLevelDirectory()[0]};

    while (it != boost::filesystem::directory_iterator{})
    {
        this->name = it->path().stem().string();
        if(this->name != "")
        {
            read();
            if(this->ordering == newOrdering)
                return true;
        }
        ++it;
    }

    return false;
}

bool Map::removeAssetDirectory(const boost::filesystem::path &path)
{
    if(assetDirectories.size() == 0)
        return false;

    auto result = assetDirectories.erase(std::remove(assetDirectories.begin(), assetDirectories.end(), path), assetDirectories.end());

    return true;
}

Map::~Map()
{
    //dtor
    write();
}
