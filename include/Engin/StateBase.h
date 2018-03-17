#ifndef STATEBASE_H
#define STATEBASE_H
#include <GameUtilities/Engin/GameState.h>
#include <SFML/Graphics/RenderWindow.hpp>

class StateBase: public GU::Engin::GameState
{
    public:
        StateBase();
        virtual ~StateBase();
    protected:
        sf::RenderWindow window;
    private:

};

#endif // STATEBASE_H
