#include "Events/ChangeState.h"


ChangeState::ChangeState(const States::Id newState):
EventBase(Events::Id::CHANGE_STATE),
state(newState)
{
    //ctor
}

ChangeState::~ChangeState()
{
    //dtor
}
