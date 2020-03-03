#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <Editor/Map.h>
#include <Editor/Layers/Layer.h>
#include <memory>

TEST_CASE( "Map default constructor", "[map::Constructor]" )
{
    Map map;

    SECTION("Check the rgb initial values")
    {
        REQUIRE(map.red == 0);
        REQUIRE(map.blue == 0);
        REQUIRE(map.green == 0);
    }

    SECTION("Check map dimensions")
    {
        REQUIRE(map.width == 0);
        REQUIRE(map.height == 0);
    }
    REQUIRE(map.ordering == 0);
    REQUIRE(map.name == "");
    REQUIRE(map.getLayerCount() == 0);
}

TEST_CASE( "Map add layer method", "[Map::addLayer]" )
{
    //Setup
    Map map;
    std::shared_ptr<Layer> layer(new Layer);

    SECTION("Test the add layer method")
    {
        map.addLayer(layer);
        REQUIRE(map.getLayerCount() == 1);
    }
}

TEST_CASE("Map::addAssetDirectory")
{
    //Setup
    Map map;
    boost::filesystem::path path = boost::filesystem::current_path();
    boost::filesystem::path emptyPath = "";
    boost::filesystem::path invalidPath = "__?<>[]{}__";
    SECTION("Test adding a valid path")
    {
        REQUIRE(map.addAssetDirectory(path));
        REQUIRE(map.getAssetDirectory()[0] == path);
    }

    SECTION("Test adding an invalid path")
    {
       REQUIRE(!map.addAssetDirectory(invalidPath));
    }

    SECTION("Test adding an empty path")
    {
        REQUIRE(!map.addAssetDirectory(emptyPath));
    }
    //Cleanup
    map.removeAssetDirectory(path);
}

TEST_CASE("Map::removeAssetDirectory")
{
    //Setup;
    Map map;
    boost::filesystem::path path = boost::filesystem::current_path();
    REQUIRE(map.getAssetDirectory().size() == 0);


    SECTION("Removing a directory when no directories were previously added should result in an exception")
    {
        REQUIRE(!map.removeAssetDirectory("/False/Directory"));
    }
    SECTION("Test the removeAssetDirectory method")
    {
        map.addAssetDirectory(path);
        REQUIRE(map.getAssetDirectory().size() == 1);
        map.removeAssetDirectory(path);
        REQUIRE(map.getAssetDirectory().size() == 0);
    }
}

TEST_CASE("Map::getAssetDirectory")
{
    Map map;
    boost::filesystem::path path = boost::filesystem::current_path();
    REQUIRE(map.addAssetDirectory(path));

    SECTION("Make sure we can get our directories")
    {
        REQUIRE(map.getAssetDirectory()[0] == path);
    }
}

TEST_CASE("Map::addLayer")
{
    std::shared_ptr<Layer> layer(new Layer());
    Map map;
    REQUIRE(map.getLayerCount() == 0);

    SECTION("Add layer test")
    {
        REQUIRE(map.addLayer(layer));
        REQUIRE(map.getLayerCount() == 1);
    }
    SECTION("Add layer failure test")
    {
        REQUIRE(map.addLayer(layer));
        REQUIRE(map.getLayerCount() == 1);
        REQUIRE(!map.addLayer(layer));
        REQUIRE(map.getLayerCount() == 1);
    }
}


TEST_CASE("Map::layerExists")
{
    std::shared_ptr<Layer> layer(new Layer());
    layer->name = "Test";
    Map map;

    SECTION("Test layerExists success")
    {
        REQUIRE(map.addLayer(layer));
        REQUIRE(map.layerExists(layer->name));
    }

    SECTION("Test layerExists failure")
    {
        REQUIRE(!map.layerExists(layer->name));
    }
}

TEST_CASE("Map::removeLayer")
{
    std::shared_ptr<Layer> layer(new Layer());
    layer->name = "Test";
    Map map;
    REQUIRE(map.addLayer(layer));

    SECTION("Remove layer success")
    {
        REQUIRE(map.removeLayer(layer->name));
    }

    SECTION("Remove layer failure")
    {
        REQUIRE(!map.removeLayer("name"));
    }


}
TEST_CASE("Map::getLayer")
{
    std::shared_ptr<Layer> layer(new Layer());
    layer->name = "Test";
    Map map;
    REQUIRE(map.addLayer(layer));

    SECTION("get layer method success")
    {
        REQUIRE(map.getLayer(layer->name) == layer);
    }

    SECTION("Gey layer method failure")
    {
        REQUIRE_THROWS(map.getLayer("layer") != layer);
    }
}
