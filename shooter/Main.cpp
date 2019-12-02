#include <SFML/Graphics.hpp>
#include "Engin/Game.h"
#include "States/IntroState.h"
#include "Events/EventManager.h"
#include <memory>
#include <TGUI/TGUI.hpp>
#include "Settings.h"
#include <iostream>
#include "Settings.h"
int main()
{
    //Set default theme
    tgui::Theme theme{"Assets/Theme/Black.txt"};
    tgui::Theme::setDefault(&theme);


	//Create our window
	sf::RenderWindow window(sf::VideoMode(Settings::screen.x, Settings::screen.y), "Shooter");
	tgui::Gui gui(window);


	//Setup our timestep
    sf::Clock timer;
    const sf::Time deltaTime = sf::seconds(Settings::timeStep);
    sf::Time accumulator = sf::seconds(0);


    //Create an instance of our game engin
	Game engin;

    std::cout << "time step " << Settings::timeStep << std::endl;
    std::cout << "sf time step " << deltaTime.asSeconds() << std::endl;
	//Initialize our engin with a state
	std::unique_ptr<IntroState> state(new IntroState(window, gui));
	engin.ChangeState(std::move(state));


	//Begin game loop
    while (engin.IsRunning())
   	{
        accumulator += timer.restart();

        //Handle events (input)
        engin.HandleEvents(deltaTime.asSeconds());
        while(accumulator.asSeconds() >= deltaTime.asSeconds())
        {
            //Update the bame
            engin.Update(deltaTime.asSeconds());
            accumulator -= deltaTime;
        }

        //Drae the game
        engin.Draw(deltaTime.asSeconds());
    }

    window.close();
    return 0;
}
