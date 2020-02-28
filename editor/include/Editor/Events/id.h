#ifndef EDITOR_ID_H_INCLUDED
#define EDITOR_ID_H_INCLUDED
#include <GameUtilities/Event/Id.h>

    namespace Button
    {
        enum id
        {
            ASSET = 10000,
            ASSET_DIALOG_CLOSE
        };
    }


enum EditorId
{
    MAP_CHANGED = GU::Evt::Id::HIGHEST + 1,
    HIGHEST
};

#endif // ID_H_INCLUDED
