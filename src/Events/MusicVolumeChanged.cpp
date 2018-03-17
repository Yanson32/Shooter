#include "Events/MusicVolumeChanged.h"
#include "Events/Id.h"

MusicVolumeChanged::MusicVolumeChanged(): EventBase(Events::Id::MUSIC_VOLUME_CHANGED)
{
    //ctor
}

MusicVolumeChanged::~MusicVolumeChanged()
{
    //dtor
}
