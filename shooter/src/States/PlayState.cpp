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
#include <iostream>
#include "Entity/Components/PhysicsComponent.h"
#include "Entity/Components/SpriteComponent.h"
#include "Entity/Systems/DrawingSystem.h"

PlayState::PlayState(sf::RenderWindow &newWindow, tgui::Gui &newGui, b2World &newWorld, DebugDraw &newDebugDraw, Map &newMap, const int &newId):
StateBase(newWindow, newGui, newWorld, newDebugDraw, newMap, States::Id::PLAY_STATE)
{

    if(map.loadLayer(Settings::currentLevel))
        std::cout << "level loaded" << std::endl;

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

    ecs.addEntity(1);

    std::shared_ptr<PhysicsComponent> pComp(new PhysicsComponent());
    pComp->body = tempBody;
    ecs.addComponent(1, pComp);


    if (!texture.loadFromFile("Assets/Image/moon_overlay.png"))
    {
        // error...
        std::cout << "Unable to load texture" << std::endl;
    }

    std::shared_ptr<SpriteComponent> sComp(new SpriteComponent());
    sComp->sprite.setTexture(texture);
    //sComp->sprite.setSize(40, 40);
    sComp->sprite.setScale(0.2, 0.2);
    sComp->sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sComp->sprite.setPosition(toPixles(tempBody->GetPosition()));
    ecs.addComponent(1, sComp);

    std::shared_ptr<DrawingSystem> dSystem(new DrawingSystem());
    dSystem->registerEntity(1);
    ecs.addSystem(dSystem);
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
        ecs.update(engin, deltaTime);
    }
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void PlayState::Draw(GU::Engin::Engin& engin, const float &deltaTime)
{
    window.clear(sf::Color(map.red, map.green, map.blue));
    window.draw(map);
    window.draw(ecs);
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
