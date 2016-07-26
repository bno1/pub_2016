#pragma once

#include "IComponent.h"
#include "Engine\Primitives\Color.h"
#include "Engine\Config.h"
#include "../Rendering/Sprite.h"

namespace Engine
{

class ENGINE_API RenderComponent : public IComponent
{
public:
	DECLARE_COMPONENT_TYPE(ComponentType::RENDER_COMPONENT);
	Sprite sprite;


	RenderComponent(const Sprite &sprite) : IComponent(ComponentType::RENDER_COMPONENT), sprite(sprite) {}
	virtual ~RenderComponent() {}
};

}