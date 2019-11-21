#ifndef MAPCREATORBASEPANEL_H
#define MAPCREATORBASEPANEL_H
#include <TGUI/TGUI.hpp>
#include "Gui/Editor/MapCreatorPanel.h"
#include <memory>
#include "Map.h"
class EditorPanel: public tgui::Panel
{
    public:
        EditorPanel(Map &map);
        void init();
        void update();
        bool drawGrid() const;
        virtual ~EditorPanel();

    protected:

    private:
        bool collapsed = false;
        tgui::Button::Ptr collapseButton;
        sf::Clock collapseTimer;
        std::shared_ptr<MapCreatorPanel> panel;
        void onCollapsePressed();
};

#endif // MAPCREATORBASEPANEL_H
