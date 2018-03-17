#include "Events/Pop.h"
#include "Events/Id.h"
Pop::Pop(): EventBase::EventBase(Events::Id::POP_STATE)
{
    //ctor
}

Pop::~Pop()
{
    //dtor
}
