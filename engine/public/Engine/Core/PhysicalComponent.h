#pragma once

#include "IComponent.h"
#include "Engine\Primitives\Vec2.h"
#include "Engine\Config.h"

namespace Engine
{

class ENGINE_API PhysicalComponent : public IComponent
{
public:
	DECLARE_COMPONENT_TYPE(ComponentType::PSHYSICAL_COMPONENT);
	Vec2<int> pos, size;

	PhysicalComponent(Vec2<int> pos, Vec2<int> size) : IComponent(ComponentType::PSHYSICAL_COMPONENT), pos(pos), size(size) {}
	virtual ~PhysicalComponent() {}

	void Translate(Vec2<int> delta) { pos += delta; }
};

}