#pragma once

#include "PhysicalComponent.h"
#include "EntityEvents\InputEvent.h"
#include "Engine\Config.h"

namespace Engine
{

class ENGINE_API MovablePhysicalComponent : public PhysicalComponent {
public:
	int m_speed;

	MovablePhysicalComponent(Vec2<int> pos, Vec2<int> size, int speed) : PhysicalComponent(pos, size), m_speed(speed) {
		EnableAcceptEvent(INPUT_EVENT);
	}

	/*
	 * Moves the PhysicalComponent when up/down/left/right arrows are pressed
	 */
	virtual void ProcessInputEvent(const InputEvent &event) override;
};

}