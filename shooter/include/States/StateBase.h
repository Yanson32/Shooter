#ifndef STATEBASE_H
#define STATEBASE_H
#include <GameUtilities/Engin/GameState.h>
#include <GameUtilities/Event/EventHandler.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <TGUI/TGUI.hpp>
#include <Events/SFEventHandler.h>
#include "Gui/GuiBase.h"
#include <memory>
class StateBase:
public GU::Engin::GameState,
public GU::Evt::EventHandler,
public SFEventHandler
{
    public:
        StateBase(sf::RenderWindow &newWindow, tgui::Gui &newGui, const int &newId);
        virtual void handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event) override;
        virtual void handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event) override;
        const int id;
        virtual ~StateBase();
    protected:
        sf::RenderWindow &window;
       	tgui::Gui &gui;
        std::shared_ptr<GuiBase> panel;
        tgui::Label::Ptr title;
    private:

};

#endif // STATEBASE_H
