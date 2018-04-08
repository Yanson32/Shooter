#ifndef STATEBASE_H
#define STATEBASE_H
#include <GameUtilities/Engin/GameState.h>
#include <GameUtilities/Event/EventHandler.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/TGUI.hpp>
#include <Events/SFEventHandler.h>

class StateBase:
public GU::Engin::GameState,
public GU::Evt::EventHandler,
public SFEventHandler
{
    public:
        StateBase();
        virtual void handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event) override;
        virtual void handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event) override;
        virtual ~StateBase();
    protected:
        static sf::RenderWindow window;
        static tgui::Gui gui;
    private:

};

#endif // STATEBASE_H
