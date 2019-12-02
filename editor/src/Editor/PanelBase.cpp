#include "Editor/PanelBase.h"
//#include "Settings.h"


/****************************************************************************//**
*   @brief  Constructor
*   @param  The id of the panel
********************************************************************************/
PanelBase::PanelBase(const int newId):
id(newId),
content(new ContentPane())
{
    //ctor
    spacer = tgui::Panel::create();
    //spacer->getRenderer()->setBackgroundColor(Settings::background);
    //this->setSize({Settings::screen.x / 2, Settings::screen.y / 2});
    //this->setPosition({Settings::screen.x / 4, Settings::screen.y / 4});
    this->getRenderer()->setBackgroundColor(sf::Color::Transparent);

    tabLayout = tgui::HorizontalLayout::create();
    tabLayout->setSize("100%", "10%");
    this->add(tabLayout);
    content->setSize("95%", "70%");
    content->setPosition("5%", "15%");
    this->add(content);
    buttonLayout = tgui::HorizontalLayout::create();
    buttonLayout->setSize("100%", "10%");
    buttonLayout->setPosition(0, "90%");
    this->add(buttonLayout);
}


/****************************************************************************//**
*   @brief  Destructor
********************************************************************************/
PanelBase::~PanelBase()
{
        //dtor
}

