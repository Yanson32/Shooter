#include "ContactListener.h"
#include <Box2D/Dynamics/Contacts/b2Contact.h>
#include "ObjectType.h"
#include <GameUtilities/Event/EventManager.h>
#include "Events/PlayerCollision.h"
ContactListener::ContactListener()
{
    //ctor
}


void ContactListener::BeginContact(b2Contact* contact)
{
    b2Fixture *fixtureA = contact->GetFixtureA();
    b2Fixture *fixtureB = contact->GetFixtureB();
    BeginContact(fixtureA, fixtureB);
    BeginContact(fixtureB, fixtureA);
}

void ContactListener::BeginContact(b2Fixture *fixtureA, b2Fixture *fixtureB)
{

    b2Body *body = fixtureA->GetBody();
    if(body->GetUserData() == nullptr)
        return;

    ObjectType *type = static_cast<ObjectType*>(body->GetUserData());

    if(*type == ObjectType::PLAYER)
    {
        if(fixtureB->GetBody()->GetUserData() != nullptr)
        {
            ObjectType tempType = *(static_cast<ObjectType*>(fixtureB->GetBody()->GetUserData()));
            GU::Evt::EventManager::inst().Post<PlayerCollision>(tempType);
        }

    }
}


ContactListener::~ContactListener()
{
    //dtor
}
