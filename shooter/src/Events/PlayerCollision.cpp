#include "Events/PlayerCollision.h"

PlayerCollision::PlayerCollision(ObjectType newType):
EventBase(Events::Id::PLAYER_COLLISION),
type(newType)
{
    //ctor
}

PlayerCollision::~PlayerCollision()
{
    //dtor
}
