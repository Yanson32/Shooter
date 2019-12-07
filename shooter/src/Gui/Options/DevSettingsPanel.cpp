#include "Gui/Options/DevSettingsPanel.h"
#include "Gui/id.h"
#include "Settings.h"
#include "Editor/Functions.h"
#include <iostream>
#include "Events/EventManager.h"
#include <GameUtilities/Event/Click.h>
#include "Gui/id.h"
/****************************************************************************//**
*   @brief  Constructor.
********************************************************************************/
DevSettingsPanel::DevSettingsPanel()//:
//OptionsPanel(Gui::id::DEV)
{
    //ctor
    this->appendSection("Box2D");
    velocityBox = this->appendEditBox("Velocity Iteration", toString(Settings::velocityIterations));
    velocityBox->connect("TextChanged", [&](){
        Settings::velocityIterations = toFloat(velocityBox->getText());
    });
    timeStepBox = this->appendEditBox("Timestep (milliseconds)", toString(Settings::timeStep  * 1000));
    timeStepBox->connect("TextChanged", [&](){
        Settings::timeStep = toFloat(timeStepBox->getText()) / 1000.0f;
    });
    positionBox = this->appendEditBox("Position Iterations", toString(Settings::positionIterations));
    positionBox->connect("TextChanged", [&](){
        Settings::positionIterations = toInt(positionBox->getText());
    });


    //Create checkbox for shape bit
    shapeBox = this->appendCheckBox("Shape");
    shapeBox->connect("checked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_SHAPE);
    });
    shapeBox->connect("unchecked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_SHAPE);
    });


    //Create checkbox for aabb bit
    aabb = this->appendCheckBox("AABB");
    aabb->connect("checked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_AABB);
    });
    aabb->connect("unchecked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_AABB);
    });


    //Create checkbox for joint bit
    joint = this->appendCheckBox("joint");
    joint->connect("checked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_JOINT);
    });
    joint->connect("unchecked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_JOINT);
    });


    //Create checkbox for center of mass bit
    centerOfMass = this->appendCheckBox("Center Of Mass");
    centerOfMass->connect("checked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_CENTER_OF_MASS);
    });
    centerOfMass->connect("unchecked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_CENTER_OF_MASS);
    });


    //Create checkbox for pair bit
    pairBit = this->appendCheckBox("Pair");
    pairBit->connect("checked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_PAIR);
    });
    pairBit->connect("unchecked", [&](){
        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_PAIR);
    });
}


/****************************************************************************//**
*   @brief  Initalize all properties.
********************************************************************************/
void DevSettingsPanel::init()
{
//    sf::String text = tabs->getSelected();
//    if(text != "Dev")
//        tabs->select("Dev");
}


/****************************************************************************//**
*   @brief  Destructor.
********************************************************************************/
DevSettingsPanel::~DevSettingsPanel()
{
    //dtor
}
