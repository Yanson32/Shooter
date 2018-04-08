#ifndef SHOOTER_STATEBASE_H
#define SHOOTER_STATEBASE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/TGUI.hpp>

class StateBase
{
    public:
        StateBase();
        virtual ~StateBase();
    protected:
    private:
        static sf::RenderWindow window;                 ///The game's window
        static tgui::Gui gui;
};

#endif // SHOOTER_STATEBASE_H
