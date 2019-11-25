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
        bool drawGrid() const;
        virtual ~EditorGeneralPanel();

        std::shared_ptr<PropertiesPanel> properties;
        tgui::EditBox::Ptr name;
        tgui::EditBox::Ptr width;
        tgui::EditBox::Ptr height;
        tgui::EditBox::Ptr ordering;
        tgui::EditBox::Ptr red;
        tgui::EditBox::Ptr blue;
        tgui::EditBox::Ptr green;
        tgui::CheckBox::Ptr grid;
        tgui::CheckBox::Ptr snap;
        Map &map;
};

#endif // EDITORGENERALPANEL_H
