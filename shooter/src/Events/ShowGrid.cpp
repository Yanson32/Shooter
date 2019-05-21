#include "Events/ShowGrid.h"
#include "Events/Id.h"

ShowGrid::ShowGrid(const bool newGrid):
EventBase::EventBase(Events::Id::SHOW_GRID),
grid(newGrid)
{
    //ctor
}

ShowGrid::~ShowGrid()
{
    //dtor
}
