#ifndef STATEBASE_H
#define STATEBASE_H
#include <GameUtilities/Engin/GameState.h>
#include <GameUtilities/Event/EventHandler.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/TGUI.hpp>
#include <Events/SFEventHandler.h>
#include "Gui/GuiBase.h"
#include <memory>
#include <Box2D/Dynamics/b2World.h>
#include "DebugDraw.h"
#include <Editor/Map.h>
class StateBase:
public GU::Engin::GameState,
public GU::Evt::EventHandler,
public SFEventHandler
{
    public:
        StateBase(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap, const int &newId);
        virtual void handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event) override;
        virtual void handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event) override;
        const int id;
        virtual ~StateBase();
    protected:
        sf::RenderWindow &window;
       	tgui::Gui &gui;
        std::shared_ptr<GuiBase> panel;
        tgui::Label::Ptr title;
        b2World &world;
        DebugDraw &debugDraw;
        Map &map;
    private:

};

#endif // STATEBASE_H
