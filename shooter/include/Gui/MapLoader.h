#ifndef MAPLOADER_H
#define MAPLOADER_H
#include "Gui/GuiBase.h"

class MapLoader: public GuiBase
{
    public:
        MapLoader();
        void init(){}
        virtual ~MapLoader();

    protected:

    private:
        tgui::Button::Ptr loadButton;
        tgui::ComboBox::Ptr combo;
        tgui::Button::Ptr deleteButton;
};

#endif // MAPLOADER_H
