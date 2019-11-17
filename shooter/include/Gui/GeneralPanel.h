#ifndef GENERALPANEL_H
#define GENERALPANEL_H
#include "Gui/OptionsPanel.h"


/****************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   11/16/19
*   @brief  This class displays developer settings. These settings will only
*           be seen in debug mode.
********************************************************************************/
class GeneralPanel: public OptionsPanel
{
    public:

        /****************************************************************************//**
        *   @brief  Constructor.
        ********************************************************************************/
        GeneralPanel();


        /****************************************************************************//**
        *   @brief  Initialize all properties.
        ********************************************************************************/
        void init();


        /****************************************************************************//**
        *   @brief  Destructor.
        ********************************************************************************/
        virtual ~GeneralPanel();
    private:
        tgui::Label::Ptr nameLabel;
        tgui::EditBox::Ptr nameEdit;
        tgui::Label::Ptr difficultyLabel;
        tgui::ComboBox::Ptr difficultyBox;
};

#endif // GENERALPANEL_H
