#ifndef ASSETMANAGEREFFECTPANEL_H
#define ASSETMANAGEREFFECTPANEL_H
#include "Editor/PropertiesPanel.h"
#include <vector>
#include <boost/filesystem.hpp>
class AssetManagerEffectPanel:public PropertiesPanel
{
    public:
        AssetManagerEffectPanel(const int width, const int height);
        void save(const std::vector<boost::filesystem::path> &outputDirectory);
        virtual ~AssetManagerEffectPanel();

    protected:
        tgui::EditBox::Ptr pathBox;
    private:
};

#endif // ASSETMANAGEREFFECTPANEL_H
