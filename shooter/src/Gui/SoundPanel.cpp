#include "Gui/SoundPanel.h"
#include "Settings.h"

/****************************************************************************//**
*   @brief  Constructor
********************************************************************************/
SoundPanel::SoundPanel():
OptionsPanel(Gui::id::SOUND)
{
    //ctor
    effectSlider = content->appendSlider("Effects");
    effectSlider->setValue(Settings::effectVolume);
    effectSlider->connect("ValueChanged", [&](){
        int volume = effectSlider->getValue();
        Settings::effectVolume = volume;
    });


    musicSlider = content->appendSlider("Music");
    musicSlider->setValue(Settings::musicVolume);
    musicSlider->connect("ValueChanged", [&](){
        int volume = musicSlider->getValue();
        Settings::musicVolume = volume;
    });

    std::vector<sf::String> music = {"Music 1", "Music 2", "Music 3"};
    currentMusic = content->appendComboBox("Current Music", music);
}


/****************************************************************************//**
*   @brief  Initialize all properties
********************************************************************************/
void SoundPanel::init()
{
    sf::String text = tabs->getSelected();
    if(text != "Sound")
        tabs->select("Sound");
}


/****************************************************************************//**
*   @brief  Destructor
********************************************************************************/
SoundPanel::~SoundPanel()
{
    //dtor
}
