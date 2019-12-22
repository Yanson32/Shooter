#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <Box2D/Dynamics/b2WorldCallbacks.h>
class ContactListener: public b2ContactListener
{
    public:
        ContactListener();
        virtual void BeginContact(b2Contact* contact);
        void BeginContact(b2Fixture *fixtureA, b2Fixture *fixtureB);
        virtual ~ContactListener();

    protected:

    private:
};

#endif // CONTACTLISTENER_H
