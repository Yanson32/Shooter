#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <TGUI/TGUI.hpp>
#include "Editor/AssetManager/AssetManagerImagePanel.h"
#include "Editor/AssetManager/AssetManagerTilesheetPanel.h"
#include "Editor/AssetManager/AssetManagerMusicPanel.h"
#include "Editor/AssetManager/AssetManagerEffectPanel.h"
#include <vector>
#include "Editor/Map.h"
class AssetManager: public tgui::Panel
{
    public:
        AssetManager(Map &newMap);
        virtual ~AssetManager();

    protected:
        const int WIDTH = 400;
        const int LAYOUT_HEIGHT = 20;
        const int DIALOG_HEIGHT = 200;
        sf::Color backgroundColor = sf::Color(75, 75, 75);
        tgui::Tabs::Ptr tabs;
        tgui::HorizontalLayout::Ptr tabLayout;
        tgui::HorizontalLayout::Ptr buttonLayout;
        tgui::Button::Ptr closeButton;
        tgui::Button::Ptr saveButton;
        std::shared_ptr<AssetManagerImagePanel> imagePanel;
        std::shared_ptr<AssetManagerTilesheetPanel> tilesheetPanel;
        std::shared_ptr<AssetManagerMusicPanel> musicPanel;
        std::shared_ptr<AssetManagerEffectPanel> effectPanel;
        std::vector<boost::filesystem::path> imageDirectory;
        std::vector<boost::filesystem::path> tilesheetDirectory;
        std::vector<boost::filesystem::path> musicDirectory;
        std::vector<boost::filesystem::path> effectsDirectory;
        Map &map;
};

#endif // ASSETMANAGER_H
