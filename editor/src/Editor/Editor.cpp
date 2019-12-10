#include "Editor/Editor.h"
//#include "Settings.h"
#include <iostream>
#include "Editor/Events/id.h"
#include <GameUtilities/Event/Id.h>
#include <GameUtilities/Event/Click.h>
Editor::Editor(Map &newMap, tgui::Gui &newGui):
map(newMap),
gui(newGui),
assetManager(new AssetManager(map))
{
    //ctor

    panel.reset(new MapCreatorPanel(map));
    this->add(panel);
    setSize({350, 600});
    setPosition({0, 0});
    getRenderer()->setBackgroundColor(sf::Color::Transparent);
    collapseButton = tgui::Button::create("Collapse");
    //collapseButton->connect("pressed", &MapCreatorState::onCollapsePressed, this);
    collapseButton->setSize({50, 50});
    collapseButton->setPosition(300, 0);
    collapseButton->connect("pressed", [&](){
        this->collapsed = !this->collapsed;
        collapseTimer.restart();
    });
    this->add(collapseButton);
}

void Editor::update()
{
        sf::Vector2f panelPos = this->getPosition();
        auto time = collapseTimer.restart();
        auto difference = (time.asSeconds() * this->getSize().x * 2);


        if(this->collapsed)
        {
            panelPos.x -= difference;
            if(panelPos.x < (0 - this->getSize().x))
                panelPos.x = 0 - this->getSize().x;

            this->setPosition(panelPos);
        }
        else
        {
            panelPos.x += difference;
            if(panelPos.x > 0)
                panelPos.x = 0;

            this->setPosition(panelPos);
        }

        if(this->getPosition().x < -(this->getSize().x - collapseButton->getSize().x))
            this->setPosition({(-this->getSize().x + collapseButton->getSize().x), 0});

}

void Editor::onCollapsePressed()
{
    this->collapsed = !this->collapsed;
    collapseTimer.restart();
}

void Editor::init()
{
    panel->init();
}

bool Editor::drawGrid() const
{
    return panel->drawGrid();
}

void Editor::write() const
{
    map.write();
}
void Editor::read()
{
    map.read();
}

void Editor::remove()
{
    map.remove();
}

void Editor::handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event)
{
    switch(event->id)
    {
        case GU::Evt::Id::CLICK:
            std::shared_ptr<GU::Evt::Click> temp =  std::dynamic_pointer_cast<GU::Evt::Click>(event);
            switch(temp->buttonId)
            {
                case Button::ASSET_DIALOG_CLOSE:
                    gui.remove(assetManager);
                break;
                case Button::ASSET:
                    gui.add(assetManager);
                break;
            }

        break;
    }
}

Editor::~Editor()
{
    //dtor
}
