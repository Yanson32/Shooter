#include "Editor/Events/MapChanged.h"
#include "Editor/Events/id.h"

MapChanged::MapChanged():
GU::Evt::Event(EditorId::MAP_CHANGED)
{
    //ctor
}

MapChanged::~MapChanged()
{
    //dtor
}
