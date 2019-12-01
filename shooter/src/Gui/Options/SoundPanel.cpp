#include "Gui/Options/SoundPanel.h"
#include "Settings.h"

/****************************************************************************//**
*   @brief  Constructor
********************************************************************************/
SoundPanel::SoundPanel()//:
//OptionsPanel(Gui::id::SOUND)
{
    //ctor
    sf::Color trackColor = sf::Color(75, 75, 75);
    sf::Color thumbColor = sf::Color(100, 100, 100);
    effectSlider = this->appendSlider("Effects");
    effectSlider->setValue(Settings::effectVolume);
    effectSlider->connect("ValueChanged", [&](){
        int volume = effectSlider->getValue();
        Settings::effectVolume = volume;
    });

    effectSlider->getRenderer()->setTrackColor(trackColor);
    effectSlider->getRenderer()->setThumbColor(thumbColor);
    musicSlider = this->appendSlider("Music");
    musicSlider->setValue(Settings::musicVolume);
    musicSlider->connect("ValueChanged", [&](){
        int volume = musicSlider->getValue();
        Settings::musicVolume = volume;
    });

    musicSlider->getRenderer()->setTrackColor(trackColor);
    musicSlider->getRenderer()->setThumbColor(thumbColor);

    std::vector<sf::String> music = {"Music 1", "Music 2", "Music 3"};
    currentMusic = this->appendComboBox("Current Music", music);
}


/****************************************************************************//**
*   @brief  Initialize all properties
********************************************************************************/
void SoundPanel::init()
{
//    sf::String text = tabs->getSelected();
//    if(text != "Sound")
//        tabs->select("Sound");
}


/****************************************************************************//**
*   @brief  Destructor
********************************************************************************/
SoundPanel::~SoundPanel()
{
    //dtor
}
