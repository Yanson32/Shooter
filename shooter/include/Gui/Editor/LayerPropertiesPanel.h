#ifndef LAYERPROPERTIESPANEL_H
#define LAYERPROPERTIESPANEL_H
#include "Gui/PropertiesPanel.h"
#include "Layer.h"
class LayerPropertiesPanel: public PropertiesPanel
{
    public:
        LayerPropertiesPanel(const int width, const int height);
        void init(const Layer &layer);
        virtual ~LayerPropertiesPanel();
        tgui::Label::Ptr name;
        tgui::CheckBox::Ptr visible;
        tgui::CheckBox::Ptr grid;
        tgui::ComboBox::Ptr combo;
        tgui::EditBox::Ptr tileWidth;
        tgui::EditBox::Ptr tileHeight;
        tgui::EditBox::Ptr zOrder;
};

#endif // LAYERPROPERTIESPANEL_H
