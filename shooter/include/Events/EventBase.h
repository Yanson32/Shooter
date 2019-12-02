#ifndef EVENTBASE_H
#define EVENTBASE_H

#include <GameUtilities/Event/Event.h>
#include "Events/Id.h"

class EventBase : public GU::Evt::Event
{
    public:
        EventBase(const int newId = Events::Id::BASE);
        virtual ~EventBase();
    protected:
    private:
};

#endif // EVENTBASE_H
