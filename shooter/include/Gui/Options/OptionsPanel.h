#ifndef OPTIONSPANEL_H
#define OPTIONSPANEL_H
#include "Gui/GuiBase.h"
#include "Gui/id.h"
#include "Gui/Options/ControlPanel.h"
#include "Gui/Options/DevSettingsPanel.h"
#include "Gui/Options/GeneralPanel.h"
#include "Gui/Options/MultiPlayerSettingsPanel.h"
#include "Gui/Options/SoundPanel.h"
#include "DebugDraw.h"

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

        void init(DebugDraw &debugDraw);
        /****************************************************************************//**
        *   @brief  Destructor
        ********************************************************************************/
        virtual ~OptionsPanel();

        tgui::Tabs::Ptr tabs;
        tgui::Button::Ptr backBtn;
        std::shared_ptr<DevSettingsPanel> devSettingsPanel = nullptr;
        std::shared_ptr<GeneralPanel> generalPanel = nullptr;
        std::shared_ptr<ControlPanel> controlPanel = nullptr;
        std::shared_ptr<SoundPanel> soundPanel = nullptr;
        std::shared_ptr<MultiPlayerSettingsPanel> multiPlayerSettingsPanel = nullptr;
        tgui::Button::Ptr closeBtn;
};

#endif // OPTIONSPANEL_H
