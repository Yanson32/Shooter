#include "Events/EventBase.h"
#include "Events/Id.h"
EventBase::EventBase(): Evt::Event(Events::Id::BASE)
{
    //ctor
}

EventBase::~EventBase()
{
    //dtor
}
