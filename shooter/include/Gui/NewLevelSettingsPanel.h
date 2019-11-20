#ifndef NEWLEVELSETTINGSPANEL_H
#define NEWLEVELSETTINGSPANEL_H
#include "Gui/PanelBase.h"

class NewLevelSettingsPanel: public PanelBase
{
    public:
        NewLevelSettingsPanel();
        void init() {}
        virtual ~NewLevelSettingsPanel();

    protected:

    private:
        tgui::Button::Ptr okButton;
        tgui::EditBox::Ptr heightBox;
        tgui::EditBox::Ptr ordering;
        tgui::CheckBox::Ptr gameBox;
        tgui::EditBox::Ptr newLevel;
        tgui::EditBox::Ptr widthBox;
};

#endif // NEWLEVELSETTINGSPANEL_H
