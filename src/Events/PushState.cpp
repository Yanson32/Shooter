#include "Events/PushState.h"
#include "Events/Id.h"

PushState::PushState(): EventBase::EventBase(Events::Id::PUSH_STATE)
{
    //ctor
}

PushState::~PushState()
{
    //dtor
}
