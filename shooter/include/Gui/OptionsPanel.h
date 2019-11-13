#ifndef OPTIONSPANEL_H
#define OPTIONSPANEL_H
#include "Gui/CustomPanel.h"
namespace Gui
{
	class OptionsPanel: public Gui::CustomPanel
	{
		public:
		    OptionsPanel();
		    virtual ~OptionsPanel();
		protected:

            tgui::Tabs::Ptr tabs;
            tgui::Button::Ptr backBtn;
	};
}
#endif // OPTIONSPANEL_H
