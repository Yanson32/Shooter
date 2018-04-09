#ifndef SHOOTER_MAPCREATORPANEL_H
#define SHOOTER_MAPCREATORPANEL_H

#include <TGUI/TGUI.hpp>

class MapCreatorPanel: public tgui::Panel
{
    public:
        MapCreatorPanel();
        bool collapsed = false;
        virtual ~MapCreatorPanel();
    protected:
    private:
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
        tgui::Button::Ptr loadButton;
        tgui::CheckBox::Ptr showGridBox;
        tgui::CheckBox::Ptr snapToGrid;
        tgui::ListBox::Ptr layerListBox;
        tgui::EditBox::Ptr layerNameBox;
        tgui::ComboBox::Ptr comboBox;
        tgui::Button::Ptr addLayerButton;

        void onShowGrid();
        void onSavePressed();
        void onLoadPressed();
        void onDontShowGrid();
        void onSnapToGrid();
        void onDontSnapToGrid();
        void generateTab();
        void generateGeneralScheme();
        void generateLayerScheme();
        void generateObjectScheme();
        void onAddLayer();

};

#endif // SHOOTER_MAPCREATORPANEL_H
