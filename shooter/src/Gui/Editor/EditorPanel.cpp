#include "Gui/Editor/EditorPanel.h"
#include "Settings.h"
EditorPanel::EditorPanel(Map &map)
{
    //ctor
    panel.reset(new MapCreatorPanel(map));
    this->add(panel);
    setSize({350, Settings::screen.y});
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

void EditorPanel::update()
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
//
        if(this->getPosition().x + this->getSize().x < collapseButton->getSize().x)
            this->setPosition(collapseButton->getSize().x - this->getSize().x, 0);
//        sf::Vector2f buttonPos = this->getPosition();
//        buttonPos.x += this->getSize().x;
//        collapseButton->setPosition(buttonPos);
}

void EditorPanel::onCollapsePressed()
{
    this->collapsed = !this->collapsed;
    collapseTimer.restart();
}

void EditorPanel::init()
{
    panel->init();
}

bool EditorPanel::drawGrid() const
{
    return panel->drawGrid();
}

EditorPanel::~EditorPanel()
{
    //dtor
}
