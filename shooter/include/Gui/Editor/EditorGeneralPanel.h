#ifndef EDITORGENERALPANEL_H
#define EDITORGENERALPANEL_H
#include "Gui/PropertiesPanel.h"
#include <TGUI/TGUI.hpp>
#include "Map.h"
class EditorGeneralPanel: public tgui::Panel
{
    public:
        EditorGeneralPanel(const int newWidth, const int newHeight, Map &newMap);
        void init();
        virtual ~EditorGeneralPanel();

        std::shared_ptr<PropertiesPanel> properties;
        tgui::EditBox::Ptr name;
        tgui::EditBox::Ptr width;
        tgui::EditBox::Ptr height;
        tgui::EditBox::Ptr ordering;
        tgui::CheckBox::Ptr grid;
        tgui::CheckBox::Ptr snap;
        tgui::EditBox::Ptr tileWidth;
        tgui::EditBox::Ptr tileHeight;
        Map &map;
};

#endif // EDITORGENERALPANEL_H
