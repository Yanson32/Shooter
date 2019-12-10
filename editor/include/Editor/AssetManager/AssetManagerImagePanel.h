#ifndef ASSETMANAGERIMAGEPANEL_H
#define ASSETMANAGERIMAGEPANEL_H
#include <boost/filesystem.hpp>
#include "Editor/PropertiesPanel.h"
class AssetManagerImagePanel: public PropertiesPanel
{
    public:
        AssetManagerImagePanel(const int width, const int height);
        void save(const std::vector<boost::filesystem::path> &outputDirectory);
        virtual ~AssetManagerImagePanel();

    protected:

    private:
        tgui::EditBox::Ptr pathBox;
};

#endif // ASSETMANAGERIMAGEPANEL_H
