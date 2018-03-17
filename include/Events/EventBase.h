#ifndef EVENTBASE_H
#define EVENTBASE_H

#include <GameUtilities/Event/Event.h>


class EventBase : public Evt::Event
{
    public:
        EventBase();
        virtual ~EventBase();
    protected:
    private:
};

#endif // EVENTBASE_H
