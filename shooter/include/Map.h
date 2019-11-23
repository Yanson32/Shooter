#ifndef MAP_H
#define MAP_H

#include "Settings.h"
#include <string>
#include "Layer.h"

class Map
{
    public:
        Map();
        void read();
        void write();
        void remove();
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
        int tileWidth;
        int tileHeight;
        std::size_t getLayerCount() const;
        Layer& operator [] (const std::size_t index);
    private:
        std::map<std::string, Layer> layers;

};

#endif // MAP_H
