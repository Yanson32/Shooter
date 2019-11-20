#ifndef EDITORLAYERSPANEL_H
#define EDITORLAYERSPANEL_H
#include "Gui/PropertiesPanel.h"
#include <TGUI/TGUI.hpp>
class EditorLayersPanel: public tgui::Panel
{
    public:
        EditorLayersPanel(const int width, const int height);
        virtual ~EditorLayersPanel();

    protected:

    private:
        std::shared_ptr<PropertiesPanel> properties;
};

#endif // EDITORLAYERSPANEL_H
