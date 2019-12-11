#ifndef PLAYERINFO_H
#define PLAYERINFO_H
#include "Gui/GuiBase.h"

class PlayerInfo: public GuiBase
{
    public:
        PlayerInfo();
        virtual ~PlayerInfo();

    protected:
        tgui::Button::Ptr backButton = nullptr;
        tgui::Button::Ptr okButton = nullptr;
        tgui::EditBox::Ptr name;
        tgui::ComboBox::Ptr difficultyBox = nullptr;
    private:
};

#endif // PLAYERINFO_H
