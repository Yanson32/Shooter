#ifndef ASSETMANAGERTILESHEETPANEL_H
#define ASSETMANAGERTILESHEETPANEL_H

#include "Editor/PropertiesPanel.h"
#include <vector>
#include <boost/filesystem.hpp>

class AssetManagerTilesheetPanel:public PropertiesPanel
{
    public:
        AssetManagerTilesheetPanel(const int width, const int height);
        void save(const std::vector<boost::filesystem::path> &tilesheetDirectory);
        virtual ~AssetManagerTilesheetPanel();

    protected:
        tgui::EditBox::Ptr pathBox;
};

#endif // ASSETMANAGERTILESHEETPANEL_H
