#ifndef EVENTS_ID_H_INCLUDED
#define EVENTS_ID_H_INCLUDED
#include <GameUtilities/Event/Id.h>
#include "Editor/Events/id.h"

namespace Events
{
    enum Id
    {
        CHANGE_STATE            = GU::Evt::Id::CHANGE_STATE,
        PUSH_STATE              = GU::Evt::Id::PUSH_STATE,
        POP_STATE               = GU::Evt::Id::POP_STATE,
        MUSIC_VOLUME_CHANGED    = GU::Evt::Id::MUSIC_VOLUME_CHANGED,
        PLAY_MUSIC              = GU::Evt::Id::PLAY_MUSIC,
        PLAY_SOUND              = GU::Evt::Id::PLAY_SOUND,
        SOUND_VOLUME_CHANGED    = GU::Evt::Id::SOUND_EFFECTS_VOLUME_CHANGED,
        CLICK                   = GU::Evt::Id::CLICK,
        MAP_CHANGED = EditorId::MAP_CHANGED,
        SHOW_GRID = EditorId::HIGHEST + 1,
        SNAP_TO_GRID,
        BASE,
        PLAYER_COLLISION
    };
}

#endif // ID_H_INCLUDED
