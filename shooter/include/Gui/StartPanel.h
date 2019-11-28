#ifndef STARTPANEL_H
#define STARTPANEL_H
#include "Gui/GuiBase.h"
#include "Gui/id.h"

class StartPanel: public GuiBase
{
    public:
        StartPanel();
        virtual ~StartPanel();

    protected:

    private:
        tgui::Button::Ptr newGame;
        tgui::Button::Ptr host;
        tgui::Button::Ptr load;
        tgui::Button::Ptr back;
};

#endif // STARTPANEL_H
