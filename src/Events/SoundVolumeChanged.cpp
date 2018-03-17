#include "Events/SoundVolumeChanged.h"
#include "Events/Id.h"

SoundVolumeChanged::SoundVolumeChanged():EventBase(Events::Id::SOUND_VOLUME_CHANGED)
{
    //ctor
}

SoundVolumeChanged::~SoundVolumeChanged()
{
    //dtor
}
