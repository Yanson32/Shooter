#include "Entity/Components/Component.h"


/************************************************************************//**
*   @brief  Constructor.
*   @param  The type of component.
****************************************************************************/
Component::Component(const int &newType):
type(newType)
{
    //ctor
}


/************************************************************************//**
*   @brief  Destructor.
*   @param  The type of component.
****************************************************************************/
Component::~Component()
{
    //dtor
}
