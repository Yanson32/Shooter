#include "Gui/SoundPanel.h"
#include "Event/Object.h"
#include "Event/Manager.h"
namespace Gui
{
    SoundPanel::SoundPanel(DebugDraw *debugDraw)
    {
        effectsLable = tgui::Label::create("Sound Effects");
        effectsLable->setPosition(sf::Vector2f(0, 100));
        layout2->add(effectsLable);

        effectsSlider = tgui::Slider::create();
        effectsSlider->setPosition(sf::Vector2f(100, 100));
        effectsSlider->connect("ValueChanged", [&](){
            auto value = effectsSlider->getValue();
            Event::Object event(Event::Object::Type::SLIDER_CHANGED);
            event.sliderChanged.id = Event::SliderChanged::EFFECTS_VOLUME;
            event.sliderChanged.value = value;
            Event::Manager::inst().push(event);
        });
        layout2->add(effectsSlider);

        musicLable = tgui::Label::create("Musuc Volume");
        musicLable->setPosition(sf::Vector2f(0, 150));
        layout3->add(musicLable);
        musicSlider = tgui::Slider::create();
        musicSlider->setPosition(sf::Vector2f(100, 150));
        musicSlider->connect("ValueChanged", [&](){
            auto value = musicSlider->getValue();
            Event::Object event(Event::Object::Type::SLIDER_CHANGED);
            event.sliderChanged.id = Event::SliderChanged::MUSIC_VOLUME;
            event.sliderChanged.value = value;
            Event::Manager::inst().push(event);
        });
        layout3->add(musicSlider);
        effectsSlider->setMaximum(255);
        musicSlider->setMaximum(255);

    }
    void SoundPanel::init()
    {
        tabs->select("Sound");
    }
    SoundPanel::~SoundPanel()
    {

    }
}
