#ifndef EDITOR_H
#define EDITOR_H
#include "Editor/MapCreatorPanel.h"
#include <memory>
#include "Map.h"
class Editor: public tgui::Panel
{
    public:
        Editor(Map &newMap);
        void init();
        void update();
        bool drawGrid() const;
        void write() const;
        void read();
        void remove();
        virtual ~Editor();

    protected:

    private:
        bool collapsed = false;
        tgui::Button::Ptr collapseButton;
        sf::Clock collapseTimer;
        std::shared_ptr<MapCreatorPanel> panel;
        void onCollapsePressed();
        Map &map;
};

#endif
