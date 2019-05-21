#ifndef SHOOTER_SNAPTOGRID_H
#define SHOOTER_SNAPTOGRID_H
#include "Events/EventBase.h"

class SnapToGrid: public EventBase
{
    public:
        SnapToGrid(const bool newSnap = true);
        bool snap = true;
        virtual ~SnapToGrid();
    protected:
    private:
};

#endif // SHOOTER_SNAPTOGRID_H
