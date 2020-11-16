#ifndef GUIBASE_H
#define GUIBASE_H

#include <TGUI/TGUI.hpp>
#include "Editor/ContentPane.h"
#include <memory>
class GuiBase: public tgui::Panel
{
    public:
        GuiBase(const int newId = -1);
        virtual ~GuiBase();
        const int id = -1;
    protected:
        tgui::HorizontalLayout::Ptr tabLayout;
        tgui::HorizontalLayout::Ptr buttonLayout;
        int buttonTextSize = 30;
        std::shared_ptr<ContentPane> content;
};

#endif // GUIBASE_H
