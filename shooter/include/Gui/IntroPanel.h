#ifndef GUI_INTROPANEL_H
#define GUI_INTROPANEL_H
#include "Gui/GuiBase.h"


/****************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   11/16/19
*   @brief  This class displays the start screen with basic options for the user.
********************************************************************************/
class IntroPanel: public GuiBase
{
    public:

        /****************************************************************************//**
        *   @brief  Constructor.
        ********************************************************************************/
        IntroPanel();


        /****************************************************************************//**
        *   @brief  Destructor.
        ********************************************************************************/
        virtual ~IntroPanel();
    protected:
    private:
        tgui::Button::Ptr startBtn;
        tgui::Button::Ptr optionsBtn;
        tgui::Button::Ptr multiplayerButton;
};
#endif // GUI_INTROPANEL_H
