#include "Gui/Editor/EditorObjectPanel.h"
#include "Gui/id.h"
EditorObjectPanel::EditorObjectPanel(const int width, const int height):
PropertiesPanel(width, height)
{
    //ctor
    //setSize(300, 400);
    setPosition(0, 75);
    appendSection("Object");
}

EditorObjectPanel::~EditorObjectPanel()
{
    //dtor
}
