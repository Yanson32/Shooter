#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H
#include <GameUtilities/Event/Manager.h>

class EventManager: public GU::Evt::Manager
{
    public:
        static EventManager& inst();
        virtual ~EventManager();
    private:
        EventManager();
        EventManager operator = (const EventManager eventManager) = delete;
        EventManager(const EventManager &EventManager) = delete;
};
#endif // EVENTMANAGER_H
