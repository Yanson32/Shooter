#ifndef WORLD_SELECT_H
#define WORLD_SELECT_H
#include "Gui/GuiBase.h"
#include <vector>
#include <string>

class WorldSelect: public GuiBase
{
    public:
        WorldSelect();
        virtual ~WorldSelect();

    protected:
        tgui::Button::Ptr backButton = nullptr;
    private:
	std::vector<std::string> defaultWorlds;
};

#endif // PLAYERINFO_H
