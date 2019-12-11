#ifndef MAPLOADER_H
#define MAPLOADER_H
#include "Gui/GuiBase.h"
#include "Editor/Map.h"
class MapLoader: public GuiBase
{
    public:
        MapLoader(Map &newMap);
        void init();
        virtual ~MapLoader();

    protected:

    private:
        tgui::Button::Ptr loadButton;
        tgui::ComboBox::Ptr combo;
        tgui::Button::Ptr deleteButton;
        Map &map;
};

#endif // MAPLOADER_H
