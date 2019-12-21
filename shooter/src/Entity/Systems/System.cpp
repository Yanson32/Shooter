#include "Entity/Systems/System.h"


/************************************************************************//**
*   @brief  This method adds an entity to the list of entities associated
*           with this system.
*   @param  The id of the entity.
***************************************************************************/
void System::registerEntity(const int &entity)
{
    entities.insert(entity);
}
