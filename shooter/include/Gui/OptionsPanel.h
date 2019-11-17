#ifndef OPTIONSPANEL_H
#define OPTIONSPANEL_H
#include "Gui/PanelBase.h"
#include "Gui/id.h"


/****************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   11/16/19
*   @brief  This class is a base class for all aptions panels.
********************************************************************************/
class OptionsPanel: public PanelBase
{
    public:

        /****************************************************************************//**
        *   @brief The constructor
        *   @param  The id param is used to identify the gui panel.
        ********************************************************************************/
        OptionsPanel(const int newId = Gui::id::OPTIONS);

        /****************************************************************************//**
        *   @brief  Destructor
        ********************************************************************************/
        virtual ~OptionsPanel();

    protected:
        tgui::Tabs::Ptr tabs;
        tgui::Button::Ptr backBtn;
};

#endif // OPTIONSPANEL_H
