#ifndef GUI_CUSTOMPANEL_H
#define GUI_CUSTOMPANEL_H
#include <TGUI/TGUI.hpp>
#include "Editor/ContentPane.h"
#include <memory>


/****************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   11/16/20
*   @brief  This class is a base class for all options panels.
********************************************************************************/
class PanelBase: public tgui::Panel
{
    public:
        /****************************************************************************//**
        *   @brief  Constructor
        *   @param  The id of the panel
        ********************************************************************************/
        PanelBase(const int newId = -1);


        /****************************************************************************//**
        *   @brief  Destructor
        ********************************************************************************/
        virtual ~PanelBase();
        const int id = -1;
    protected:
        tgui::Panel::Ptr spacer;
        tgui::HorizontalLayout::Ptr tabLayout;
        tgui::HorizontalLayout::Ptr buttonLayout;
        int buttonTextSize = 30;
        std::shared_ptr<ContentPane> content;
};

#endif // GUI_CUSTOMPANEL_H
