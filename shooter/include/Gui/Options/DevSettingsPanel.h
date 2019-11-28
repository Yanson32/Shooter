#ifndef DEVSETTINGSPANEL_H
#define DEVSETTINGSPANEL_H
#include "Gui/Options/OptionsPanel.h"


/****************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   11/16/19
*   @brief  This class displays developer settings. These settings will only
*           be seen in debug mode.
********************************************************************************/
class DevSettingsPanel: public OptionsPanel
{
    public:
        /****************************************************************************//**
        *   @brief  Constructor.
        ********************************************************************************/
        DevSettingsPanel();

        /****************************************************************************//**
        *   @brief  Initalize all properties.
        ********************************************************************************/
        void init();

        /****************************************************************************//**
        *   @brief  Destructor.
        ********************************************************************************/
        virtual ~DevSettingsPanel();
    private:
        tgui::Label::Ptr velocityLabel;
        tgui::EditBox::Ptr velocityBox;
        tgui::EditBox::Ptr timeStepBox;
        tgui::EditBox::Ptr positionBox;
        tgui::CheckBox::Ptr shapeBox;
        tgui::CheckBox::Ptr centerOfMass;

};

#endif // DEVSETTINGSPANEL_H
