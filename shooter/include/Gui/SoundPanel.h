#ifndef SOUND_PANEL_H
#define SOUND_PANEL_H
#include "Gui/OptionsPanel.h"


/****************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   11/16/20
*   @brief  This class is a base class for all aptions panels.
********************************************************************************/
class SoundPanel: public OptionsPanel
{
    public:
        /****************************************************************************//**
        *   @brief  Constructor
        ********************************************************************************/
        SoundPanel();


        /****************************************************************************//**
        *   @brief  Initialize all properties
        ********************************************************************************/
        void init();


        /****************************************************************************//**
        *   @brief  Destructor
        ********************************************************************************/
        virtual ~SoundPanel();
    private:
        tgui::Label::Ptr effectLabel;
        tgui::Slider::Ptr effectSlider;
        tgui::Label::Ptr musicLabel;
        tgui::Slider::Ptr musicSlider;
        tgui::ComboBox::Ptr currentMusic;
};

#endif // SOUND_H
