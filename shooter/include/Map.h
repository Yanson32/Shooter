#ifndef MAP_H
#define MAP_H

#include "Settings.h"
#include <string>
#include "Layer.h"
#include <SFML/Graphics/Drawable.hpp>

class Map: public sf::Drawable
{
    public:
        Map();
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
        Layer& getLayer(const std::string &name);
        std::vector<std::string> getAllDir() const;
        virtual ~Map();
        std::string name;
        int width;
        int height;
        int ordering;
        std::size_t getLayerCount() const;
        Layer& operator [] (const std::size_t index);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        std::map<std::string, Layer> layers;

};

#endif // MAP_H
