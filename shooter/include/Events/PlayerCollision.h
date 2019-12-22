#ifndef PLAYERCOLLISION_H
#define PLAYERCOLLISION_H
#include "Events/EventBase.h"
#include "ObjectType.h"
class PlayerCollision: public EventBase
{
    public:
        PlayerCollision(ObjectType newType);
        const ObjectType type;
        virtual ~PlayerCollision();

    protected:

    private:
};

#endif // PLAYERCOLLISION_H
