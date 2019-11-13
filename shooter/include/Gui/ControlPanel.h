#ifndef GUI_CONTROLPANEL_H
#define GUI_CONTROLPANEL_H
#include "Gui/OptionsPanel.h"
class DebugDraw;
namespace Gui
{
    class ControlPanel: public Gui::OptionsPanel
    {
        public:
            ControlPanel(DebugDraw *debugDraw);
            void init();
            virtual ~ControlPanel();
        protected:
    };
}

#endif // GUI_CONTROLPANEL_H
