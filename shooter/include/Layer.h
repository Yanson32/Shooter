#ifndef LAYER_H
#define LAYER_H
#include <string>
#include "Tile.h"
#include <vector>
#include <string>
#include <SFML/Graphics/Drawable.hpp>
class Layer: public sf::Drawable
{
    public:
        Layer();
        std::string name;
        bool visible;
        bool grid;
        std::string type;
        int width;
        int height;
        int zOrder;
        std::vector<Tile> tiles;
        void read(const std::string &map);
        void write(const std::string &map);
        std::string getSourceDir(const std::string &map) const;
        std::string getBuildDir(const std::string &map) const;
        std::vector<std::string> getAllPaths(const std::string &map) const;
        std::string getFullPath(const std::string dir, const std::string &map) const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual ~Layer();
};

#endif // LAYER_H
