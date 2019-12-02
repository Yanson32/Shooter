#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H
#include "Editor/ContentPane.h"

/****************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   11/16/19
*   @brief  This class defines a gui for player control settings.
********************************************************************************/
class ControlPanel: public ContentPane
{
    public:
        /****************************************************************************//**
        *   @brief Constructor
        ********************************************************************************/
        ControlPanel();


        /****************************************************************************//**
        *   @brief The init defines default values for the panel
        ********************************************************************************/
        void init();


        /****************************************************************************//**
        *   @brief Destructor
        ********************************************************************************/
        virtual ~ControlPanel();

    private:
        tgui::EditBox::Ptr upBox;
        tgui::EditBox::Ptr downBox;
        tgui::EditBox::Ptr leftBox;
        tgui::EditBox::Ptr rightBox;
        tgui::EditBox::Ptr jumpBox;
        tgui::EditBox::Ptr actionBox;
};

#endif // CONTROLPANEL_H
