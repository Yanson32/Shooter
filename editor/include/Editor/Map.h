#ifndef MAP_H
#define MAP_H

//#include "Settings.h"
#include <string>
#include "Editor/Layers/Layer.h"
#include <SFML/Graphics/Drawable.hpp>
#include <memory>
#include <vector>
#include <boost/filesystem.hpp>
#include "editor_export.h"
class EDITOR_EXPORT Map: public sf::Drawable
{
    public:
        std::string name;
        int width;
        int height;
        int ordering;
        int red = 0;
        int blue = 0;
        int green = 0;

        Map();
        bool addAssetDirectory(const boost::filesystem::path &path);
        std::vector<boost::filesystem::path> getAssetDirectory() const;
        bool removeAssetDirectory(const boost::filesystem::path &path);
        void init();
        void read();
        void write();
        void remove();
        bool loadLayer(const unsigned newOrdering);
        void layerSelected(const std::string &name);
        bool layerExists(const std::string &name);
        bool addLayer(std::shared_ptr<Layer> layer);
        bool removeLayer(const std::string &layer);
        std::shared_ptr<Layer> getLayer(const std::string &name);
        std::vector<std::string> getAllDir() const;
        std::size_t getLayerCount() const;
        std::shared_ptr<Layer> operator [] (const std::size_t index);
        std::vector<boost::filesystem::path> getImageDirectory() const;
        std::vector<boost::filesystem::path> getLevelDirectory() const;
        std::vector<boost::filesystem::path> getThemeDirectory() const;
        std::vector<boost::filesystem::path> getEffectsDirectory() const;
        std::vector<boost::filesystem::path> getMusicDirectory() const;
        std::vector<boost::filesystem::path> getTilesheetDirectory() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual ~Map();
    private:
        std::map<std::string, std::shared_ptr<Layer>> layers;
        std::vector<boost::filesystem::path> assetDirectories;

};

#endif // MAP_H
