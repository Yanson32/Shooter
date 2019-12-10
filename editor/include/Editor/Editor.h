#ifndef EDITOR_H
#define EDITOR_H
#include "Editor/MapCreatorPanel.h"
#include <memory>
#include "Map.h"
#include "GameUtilities/Event/EventHandler.h"
#include "Editor/AssetManager/AssetManager.h"

class Editor: public tgui::Panel, public GU::Evt::EventHandler
{
    public:
        Editor(Map &newMap, tgui::Gui &newGui);
        void init();
        void update();
        bool drawGrid() const;
        void write() const;
        void read();
        void remove();
        virtual void handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event);
        virtual ~Editor();

    protected:

    private:
        bool collapsed = false;
        tgui::Button::Ptr collapseButton;
        sf::Clock collapseTimer;
        std::shared_ptr<MapCreatorPanel> panel;
        void onCollapsePressed();
        Map &map;
        tgui::Gui &gui;
        std::shared_ptr<AssetManager> assetManager;
};

#endif
