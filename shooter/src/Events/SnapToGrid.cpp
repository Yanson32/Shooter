#include "Events/SnapToGrid.h"

SnapToGrid::SnapToGrid(const bool newSnap):
EventBase(Events::Id::SNAP_TO_GRID),
snap(newSnap)
{
    //ctor
}

SnapToGrid::~SnapToGrid()
{
    //dtor
}
