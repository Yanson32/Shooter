#include "Engin/StateBase.h"
#include <SFML/Window/VideoMode.hpp>

StateBase::StateBase(): window(sf::VideoMode({800, 600}), "Shooter")
{
    //ctor
}

StateBase::~StateBase()
{
    //dtor
}
