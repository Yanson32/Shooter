#include "Gui/Options/DevSettingsPanel.h"
#include "Gui/id.h"
#include "Settings.h"
#include "Editor/Functions.h"
#include <iostream>
#include <GameUtilities/Event/EventManager.h>
#include <GameUtilities/Event/Click.h>
#include "Gui/id.h"
#include <iostream>
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
//    shapeBox->connect("checked", [&](){
//        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_SHAPE);
//    });
//    shapeBox->connect("unchecked", [&](){
//        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_SHAPE);
//    });


    //Create checkbox for aabb bit
    aabb = this->appendCheckBox("AABB");



    //Create checkbox for joint bit
    joint = this->appendCheckBox("joint");



    //Create checkbox for center of mass bit
    centerOfMass = this->appendCheckBox("Center Of Mass");
//    centerOfMass->connect("checked", [&](){
//        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_CENTER_OF_MASS);
//    });
//    centerOfMass->connect("unchecked", [&](){
//        EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_CENTER_OF_MASS);
//    });


    //Create checkbox for pair bit
    pairBit = this->appendCheckBox("Pair");

}


/****************************************************************************//**
*   @brief  Initalize all properties.
********************************************************************************/
void DevSettingsPanel::init(DebugDraw &debugDraw)
{
    shapeBox->disconnectAll("checked");
    shapeBox->disconnectAll("unchecked");
    centerOfMass->disconnectAll("checked");
    centerOfMass->disconnectAll("unchecked");
    pairBit->disconnectAll("checked");
    pairBit->disconnectAll("unchecked");
    joint->disconnectAll("checked");
    joint->disconnectAll("unchecked");
    aabb->disconnectAll("checked");
    aabb->disconnectAll("unchecked");
    shapeBox->setChecked(debugDraw.IsBitSet(b2Draw::e_shapeBit));
    centerOfMass->setChecked(debugDraw.IsBitSet(b2Draw::e_centerOfMassBit));
    pairBit->setChecked(debugDraw.IsBitSet(b2Draw::e_pairBit));
    joint->setChecked(debugDraw.IsBitSet(b2Draw::e_jointBit));
    aabb->setChecked(debugDraw.IsBitSet(b2Draw::e_aabbBit));

    shapeBox->connect("checked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_SHAPE);
    });
    shapeBox->connect("unchecked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_SHAPE);
    });
    centerOfMass->connect("checked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_CENTER_OF_MASS);
    });
    centerOfMass->connect("unchecked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_CENTER_OF_MASS);
    });
    pairBit->connect("checked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_PAIR);
    });
    pairBit->connect("unchecked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_PAIR);
    });
    joint->connect("checked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_JOINT);
    });
    joint->connect("unchecked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_JOINT);
    });
    aabb->connect("checked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_AABB);
    });
    aabb->connect("unchecked", [&](){
        GU::Evt::EventManager::inst().Post<GU::Evt::Click>(Gui::id::B2_AABB);
    });
}


/****************************************************************************//**
*   @brief  Destructor.
********************************************************************************/
DevSettingsPanel::~DevSettingsPanel()
{
    //dtor
}
