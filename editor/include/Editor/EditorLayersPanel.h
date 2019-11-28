#ifndef EDITORLAYERSPANEL_H
#define EDITORLAYERSPANEL_H
#include "Editor/LayerPropertiesPanel.h"
#include <TGUI/TGUI.hpp>
#include "Editor/LayersListBox.h"
#include "Map.h"
class EditorLayersPanel: public tgui::Panel
{
    public:
        EditorLayersPanel(const int width, const int height, Map &newMap);
        void init();
        virtual ~EditorLayersPanel();

    protected:

    private:
        std::shared_ptr<LayerPropertiesPanel> properties;
        tgui::ComboBox::Ptr typeBox;
        tgui::ListBox::Ptr listBox;
        tgui::EditBox::Ptr name;
        tgui::Button::Ptr addButton;
        tgui::Button::Ptr removeButton;
        tgui::HorizontalLayout::Ptr controlsLayout;
        Map &map;
};

#endif // EDITORLAYERSPANEL_H
