#include "Gui/Options/DevSettingsPanel.h"
#include "Gui/id.h"
#include "Settings.h"
#include "Editor/Functions.h"


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
    timeStepBox = this->appendEditBox("Timestep", toString(Settings::timeStep));
    timeStepBox->connect("TextChanged", [&](){
        Settings::timeStep = toFloat(timeStepBox->getText());
    });
    positionBox = this->appendEditBox("Position Iterations", toString(Settings::positionIterations));
    positionBox->connect("TextChanged", [&](){
        Settings::positionIterations = toInt(positionBox->getText());
    });
    shapeBox = this->appendCheckBox("Shape");
    tgui::CheckBox::Ptr aabb = this->appendCheckBox("AABB");
    tgui::CheckBox::Ptr circleShape = this->appendCheckBox("Circle Shape");
    tgui::CheckBox::Ptr centerOfMass = this->appendCheckBox("Center Of Mass");

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
