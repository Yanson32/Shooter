#include "Gui/DevSettingsPanel.h"
#include "Gui/id.h"
#include "Settings.h"
#include "Functions.h"


/****************************************************************************//**
*   @brief  Constructor.
********************************************************************************/
DevSettingsPanel::DevSettingsPanel():
OptionsPanel(Gui::id::DEV)
{
    //ctor
    content->appendSection("Box2D");
    velocityBox = content->appendEditBox("Velocity Iteration", toString(Settings::velocityIterations));
    velocityBox->connect("TextChanged", [&](){
        Settings::velocityIterations = toFloat(velocityBox->getText());
    });
    timeStepBox = content->appendEditBox("Timestep", toString(Settings::timeStep));
    timeStepBox->connect("TextChanged", [&](){
        Settings::timeStep = toFloat(timeStepBox->getText());
    });
    positionBox = content->appendEditBox("Position Iterations", toString(Settings::positionIterations));
    positionBox->connect("TextChanged", [&](){
        Settings::positionIterations = toInt(positionBox->getText());
    });
    shapeBox = content->appendCheckBox("Shape");
    tgui::CheckBox::Ptr aabb = content->appendCheckBox("AABB");
    tgui::CheckBox::Ptr circleShape = content->appendCheckBox("Circle Shape");
    tgui::CheckBox::Ptr centerOfMass = content->appendCheckBox("Center Of Mass");

}


/****************************************************************************//**
*   @brief  Initalize all properties.
********************************************************************************/
void DevSettingsPanel::init()
{
    sf::String text = tabs->getSelected();
    if(text != "Dev")
        tabs->select("Dev");
}


/****************************************************************************//**
*   @brief  Destructor.
********************************************************************************/
DevSettingsPanel::~DevSettingsPanel()
{
    //dtor
}
