#include "Events/PlaySound.h"
#include "Events/Id.h"

PlaySound::PlaySound(const sf::String &newId): EventBase(Events::Id::PLAY_SOUND), soundId(newId)
{
    //ctor
}

PlaySound::~PlaySound()
{
    //dtor
}
