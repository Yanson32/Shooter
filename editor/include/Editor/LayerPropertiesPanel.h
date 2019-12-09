#ifndef LAYERPROPERTIESPANEL_H
#define LAYERPROPERTIESPANEL_H
#include "Editor/PropertiesPanel.h"
#include "Editor/Layers/Layer.h"
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
