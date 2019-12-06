#ifndef MAP_H
#define MAP_H

//#include "Settings.h"
#include <string>
#include "Layer.h"
#include <SFML/Graphics/Drawable.hpp>
#include <memory>
class Map: public sf::Drawable
{
    public:
        Map(const std::string &newSourceDir, const std::string newBuildDir);
        void init();
        void read();
        void write();
        void remove();
        void layerSelected(const std::string &name);
        bool layerExists(const std::string &name);
        std::string getSourceDir() const;
        std::string getBuildDir() const;
        void addLayer(Layer layer);
        bool removeLayer(const std::string &layer);
        std::shared_ptr<Layer> getLayer(const std::string &name);
        std::vector<std::string> getAllDir() const;
        virtual ~Map();
        std::string name;
        int width;
        int height;
        int ordering;
        int red = 100;
        int blue = 0;
        int green = 0;
        std::size_t getLayerCount() const;
        std::shared_ptr<Layer> operator [] (const std::size_t index);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        std::map<std::string, std::shared_ptr<Layer>> layers;
        std::string source_directory = "";
        std::string build_directory = "";

};

#endif // MAP_H
