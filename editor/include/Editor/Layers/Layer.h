#ifndef LAYER_H
#define LAYER_H
#include <string>
#include "Editor/Tile.h"
#include <vector>
#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include "Editor/Grid.h"
#include <boost/filesystem.hpp>

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
        bool selected = false;
        std::vector<Tile> tiles;
        void init(const sf::Vector2f &mapSize);
        void read(boost::filesystem::path path, const std::string &map);
        void write(const std::vector<boost::filesystem::path> &directories, const std::string &map);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual ~Layer();
        Grid layerGrid;
        std::string source_directory;
        std::string build_directory;
};

#endif // LAYER_H
