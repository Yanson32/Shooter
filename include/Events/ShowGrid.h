#ifndef EVENT_SHOWGRID_H
#define EVENT_SHOWGRID_H

#include <Events/EventBase.h>


class ShowGrid : public EventBase
{
    public:
        ShowGrid(const bool newGrid);
        bool grid = true;
        virtual ~ShowGrid();
    protected:
    private:
};

#endif // EVENT_SHOWGRID_H
