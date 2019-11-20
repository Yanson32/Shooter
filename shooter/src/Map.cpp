#include "Map.h"
#include <string>
#include <fstream>
#include <iostream>
#include "config.h"
#include <boost/filesystem.hpp>
Map::Map()
{
    //ctor

}

void Map::read()
{
    std::string sourceDir = getSourceDir();
    std::ifstream sourceStream(sourceDir);
    if(!sourceStream)
        return;

    std::getline(sourceStream, name);
    sourceStream >> width;
    sourceStream >> height;
    sourceStream >> ordering;
    sourceStream >> tileWidth;
    sourceStream >> tileHeight;
    sourceStream.close();
}

void Map::write()
{
    std::string sourceDir = getSourceDir();
    std::string buildDir = getBuildDir();

    std::ofstream sourceStream(sourceDir);
    std::ofstream buildStream(buildDir);

    std::cout << sourceDir << std::endl;
//    if(!sourceStream || !buildStream)
//        return;

    sourceStream << name << std::endl;
    sourceStream << width << std::endl;
    sourceStream << height << std::endl;
    sourceStream << ordering << std::endl;
    sourceStream << tileWidth << std::endl;
    sourceStream << tileHeight << std::endl;
    sourceStream.close();

    buildStream << name << std::endl;
    buildStream << width << std::endl;
    buildStream << height << std::endl;
    buildStream << ordering << std::endl;
    buildStream << tileWidth << std::endl;
    buildStream << tileHeight << std::endl;
    buildStream.close();

}

void Map::remove()
{
    boost::filesystem::path source(getSourceDir());
    boost::filesystem::path build(getBuildDir());
    boost::filesystem::remove(source);
    boost::filesystem::remove(build);
}

std::string Map::getSourceDir()
{
    return SOURCE_DIR + "/Assets/Level/" + name + ".map";
}


std::string Map::getBuildDir()
{
    return BUILD_DIR + "/Assets/Level/" + name + ".map";
}


Map::~Map()
{
    //dtor
}
