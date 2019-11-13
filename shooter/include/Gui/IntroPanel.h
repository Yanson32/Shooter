#ifndef GUI_INTROPANEL_H
#define GUI_INTROPANEL_H
#include "Gui/PanelBase.h"

namespace Gui
{
    class IntroPanel: public Gui::PanelBase
    {
        public:
            IntroPanel();
            virtual ~IntroPanel();
        protected:
        private:
            tgui::Button::Ptr startBtn;
            tgui::Button::Ptr optionsBtn;
            tgui::Button::Ptr multiplayerButton;
    };
}
#endif // GUI_INTROPANEL_H
