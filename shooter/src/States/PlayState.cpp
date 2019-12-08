#include "States/PlayState.h"
#include "Events/EventManager.h"
#include "config.h"
#include "Settings.h"
#include <GameUtilities/Event/Pop.h>
#include <Box2D/Collision/Shapes/b2ChainShape.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include "Functions.h"

PlayState::PlayState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, const int &newId):
StateBase(newWindow, newGui, newWorld, newDebugDraw, States::Id::PLAY_STATE),
map(SOURCE_DIR, BUILD_DIR)
{
    map.name = "Temp";
    map.read();

    //Create temp object
    b2BodyDef tempBodyDef;
    tempBodyDef.type = b2_dynamicBody;
    tempBodyDef.position = toMeters({50, 50});
    b2Body* tempBody = world.CreateBody(&tempBodyDef);

    b2PolygonShape polyShape;
    polyShape.SetAsBox(toMeters(40), toMeters(40));
    b2FixtureDef tempFixDef;
    tempFixDef.shape = &polyShape;

    tempBody->CreateFixture(&tempFixDef);

}
/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void PlayState::Init()
{
    //Create world boundries
    b2BodyDef worldBodyDef;
    b2Body* borderBody = world.CreateBody(&worldBodyDef);

    b2ChainShape chainShape;
    b2Vec2 vert[5];
    vert[0] = toMeters({0, 0});

    vert[1] = toMeters({map.width, 0});

    vert[2] = toMeters({map.width, map.height});

    vert[3] = toMeters({0, map.height});

    vert[4] = toMeters({0, 0});

    chainShape.CreateChain(vert, 5);
    b2FixtureDef fixDef;
    fixDef.shape = &chainShape;
    borderBody->CreateFixture(&fixDef);
}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void PlayState::Clean()
{
    for(b2Body *it = world.GetBodyList(); it != nullptr; it = it->GetNext())
    {
        world.DestroyBody(it);
    }
}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void PlayState::HandleEvents(GU::Engin::Engin& engin, const float &deltaTime)
{
    if(window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            handleSFEvent(engin, event);
            gui.handleEvent(event);
        }
    }

    //GameUtilities event loop
    GU::Evt::EventPtr evtPtr;
    while(EventManager::inst().Poll((evtPtr)))
    {
        handleGUEvent(engin, evtPtr);
    }
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void PlayState::Update(GU::Engin::Engin& engin, const float &deltaTime)
{

    if(!IsPaused())
    {
        world.Step(deltaTime, Settings::velocityIterations, Settings::positionIterations);
        debugDraw.update();
        world.DrawDebugData();
    }
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void PlayState::Draw(GU::Engin::Engin& engin, const float &deltaTime)
{
    window.clear(sf::Color(map.red, map.green, map.blue));
    window.draw(map);
    window.draw(debugDraw);
    gui.draw();
    window.display();
}

void PlayState::handleSFEvent(GU::Engin::Engin& engin, const sf::Event &event)
{
    StateBase::handleSFEvent(engin, event);

    switch(event.type)
    {
        case sf::Event::KeyPressed:
            switch(event.key.code)
            {
                case sf::Keyboard::Escape:
                    if(panel)
                        gui.remove(panel);

                    std::shared_ptr<OptionsPanel> temp(new OptionsPanel(true));
                    temp->init(debugDraw);
                    panel = temp;

                    if(temp)
                    {
                        temp->backBtn->connect("pressed", [&](){
                            EventManager::inst().Post<GU::Evt::Pop>();
                            gui.removeAllWidgets();
                        });

                        temp->closeBtn->connect("pressed", [&](){
                            gui.remove(panel);
                        });
                    }

                    gui.add(panel);
                break;
            }
        break;
    }
}

PlayState::~PlayState()
{
    //dtor
}
