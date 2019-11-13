#include <SFML/Graphics.hpp>
#include "Engin/Game.h"
#include "States/IntroState.h"
#include "Events/EventManager.h"
#include <memory>
#include <TGUI/TGUI.hpp>
#include "Settings.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(Settings::screen.x, Settings::screen.y), "Shooter");

	tgui::Gui gui(window);

    sf::Clock timer;
    const sf::Time deltaTime = sf::seconds(1.0f / 60.0f);
    sf::Time accumulator = sf::seconds(0);

	Game engin;

	std::unique_ptr<IntroState> state(new IntroState(window, gui));
	engin.ChangeState(std::move(state));

	//EventManager::inst().Post<PlayMusic>("../Resources/Music/Electro_Zombies.ogg");
	//EventManager::inst().Post<MusicVolumeChanged>();
	//EventManager::inst().Post<SoundVolumeChanged>();


    while (engin.IsRunning())
   	{
        accumulator += timer.restart();
        engin.HandleEvents(deltaTime.asSeconds());
        while(accumulator.asSeconds() >= deltaTime.asSeconds())
        {
            engin.Update(deltaTime.asSeconds());
            accumulator -= deltaTime;
        }
        engin.Draw(deltaTime.asSeconds());
    }


    return 0;
}
