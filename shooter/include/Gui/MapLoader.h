#ifndef MAPLOADER_H
#define MAPLOADER_H
#include "Gui/PanelBase.h"

class MapLoader: public PanelBase
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
