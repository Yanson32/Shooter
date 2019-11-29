#ifndef OPTIONSPANEL_H
#define OPTIONSPANEL_H
#include "Gui/GuiBase.h"
#include "Gui/id.h"
#include "Gui/Options/ControlPanel.h"
#include "Gui/Options/DevSettingsPanel.h"
#include "Gui/Options/GeneralPanel.h"
#include "Gui/Options/MultiPlayerSettingsPanel.h"
#include "Gui/Options/SoundPanel.h"

/****************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   11/16/19
*   @brief  This class is a base class for all aptions panels.
********************************************************************************/
class OptionsPanel: public GuiBase
{
    public:

        /****************************************************************************//**
        *   @brief The constructor
        *   @param  The id param is used to identify the gui panel.
        ********************************************************************************/
        OptionsPanel(const bool greyStyle = false, const int newId = Gui::id::OPTIONS);

        /****************************************************************************//**
        *   @brief  Destructor
        ********************************************************************************/
        virtual ~OptionsPanel();

        tgui::Tabs::Ptr tabs;
        tgui::Button::Ptr backBtn;
        tgui::Button::Ptr closeBtn;
};

#endif // OPTIONSPANEL_H
