#ifndef ASSETMANAGERMUSICPANEL_H
#define ASSETMANAGERMUSICPANEL_H

#include "Editor/PropertiesPanel.h"
#include <vector>
#include <boost/filesystem.hpp>
class AssetManagerMusicPanel:public PropertiesPanel
{
    public:
        AssetManagerMusicPanel(const int width, const int height);
        void save(const std::vector<boost::filesystem::path> &outputDirectory);
        virtual ~AssetManagerMusicPanel();

    protected:
        tgui::EditBox::Ptr pathBox;
};

#endif // ASSETMANAGERMUSICPANEL_H
