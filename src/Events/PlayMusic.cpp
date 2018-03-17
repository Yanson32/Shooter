#include "Events/PlayMusic.h"
#include "Events/Id.h"

PlayMusic::PlayMusic(const sf::String &musicFile): EventBase(Events::Id::PLAY_MUSIC), file(musicFile)
{
    //ctor
}

PlayMusic::~PlayMusic()
{
    //dtor
}
