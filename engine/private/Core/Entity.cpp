#include "Engine\Core\Entity.h"

#include "Utilities.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::AddComponent(IComponent &component)
{
	components.push_back(&component);
}
