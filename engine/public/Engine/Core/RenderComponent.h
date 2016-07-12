#pragma once

#include "IComponent.h"
#include "Engine\Primitives\Color.h"
#include "Engine\Config.h"

namespace Engine
{

class ENGINE_API RenderComponent : public IComponent
{
public:
	DECLARE_COMPONENT_TYPE(ComponentType::RENDER_COMPONENT);
	Color<float> color;

	RenderComponent(Color<float> color) : IComponent(ComponentType::RENDER_COMPONENT), color(color) {}
	virtual ~RenderComponent() {}
};

}