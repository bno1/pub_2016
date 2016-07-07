#pragma once

#include "IComponent.h"
#include "ComponentType.h"

class PhysicalComponent : IComponent
{
public:
	DECLARE_COMPONENT_TYPE(ComponentType::PSHYSICAL_COMPONENT);
	int posX, posY;

	PhysicalComponent(int posX = 0, int posY = 0);
	virtual ~PhysicalComponent();
};

