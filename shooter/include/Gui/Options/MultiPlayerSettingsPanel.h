#ifndef MULTIPLAYERSETTINGSPANEL_H
#define MULTIPLAYERSETTINGSPANEL_H
#include "Editor/ContentPane.h"

/****************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   11/16/19
*   @brief  This class displays settings for multiplayer mode.
********************************************************************************/
class MultiPlayerSettingsPanel: public ContentPane
{
    public:
        /****************************************************************************//**
        *   @brief  Constructor.
        ********************************************************************************/
        MultiPlayerSettingsPanel();


        /****************************************************************************//**
        *   @brief  Set values for all properties.
        ********************************************************************************/
        void init();


        /****************************************************************************//**
        *   @brief  Constructor.
        ********************************************************************************/
        virtual ~MultiPlayerSettingsPanel();
    private:
        tgui::Label::Ptr portLabel;
        tgui::EditBox::Ptr portBox;
};

#endif // MULTIPLAYERSETTINGSPANEL_H
