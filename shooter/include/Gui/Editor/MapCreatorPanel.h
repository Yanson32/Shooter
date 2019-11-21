#ifndef SHOOTER_MAPCREATORPANEL_H
#define SHOOTER_MAPCREATORPANEL_H

#include <TGUI/TGUI.hpp>
#include "Gui/PanelBase.h"
#include "Gui/Editor/EditorGeneralPanel.h"
#include "Gui/Editor/EditorLayersPanel.h"
#include "Gui/Editor/EditorObjectPanel.h"
#include "Map.h"

class MapCreatorPanel: public tgui::Panel
{
    public:
        MapCreatorPanel(Map &map);
        void init();
        bool drawGrid() const;
        virtual ~MapCreatorPanel();
    protected:
        const unsigned NUMBER_OF_TABS = 3;
        const unsigned TAB_DIMENTIONS = 50;
        const unsigned BORDER = 10;
        const unsigned PANEL_HEIGHT = 600;
        const unsigned PANEL_WIDTH = 300;
        const unsigned BUTTON_HEIGHT = 50;
        tgui::Button::Ptr generalTab;
        tgui::Button::Ptr layerTab;
        tgui::Button::Ptr objectTab;
        tgui::Button::Ptr saveButton;
        tgui::Button::Ptr backButton;
        tgui::Button::Ptr loadButton;
        tgui::CheckBox::Ptr showGridBox;
        tgui::CheckBox::Ptr snapToGrid;
        tgui::ListBox::Ptr layerListBox;
        tgui::EditBox::Ptr layerNameBox;
        tgui::ComboBox::Ptr comboBox;
        tgui::Button::Ptr addLayerButton;
        tgui::Tabs::Ptr tabs;
        tgui::HorizontalLayout::Ptr tabLayout;
        tgui::HorizontalLayout::Ptr buttonLayout;
        void onShowGrid();
        void onSavePressed();
        void onLoadPressed();
        void onDontShowGrid();
        void onSnapToGrid();
        void onDontSnapToGrid();
        void onAddLayer();
        std::shared_ptr<ContentPane> panel;
        std::shared_ptr<EditorGeneralPanel> generalPanel;
        std::shared_ptr<EditorLayersPanel> layersPanel;
        std::shared_ptr<EditorObjectPanel> objectPanel;

};

#endif // SHOOTER_MAPCREATORPANEL_H
