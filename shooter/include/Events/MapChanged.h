#ifndef MAPCHANGED_H
#define MAPCHANGED_H
#include <GameUtilities/Events/Event.h>

class MapChanged: public GU::Evt::Event
{
    public:
        MapChanged();
        virtual ~MapChanged();

    protected:

    private:
};

#endif // MAPCHANGED_H
