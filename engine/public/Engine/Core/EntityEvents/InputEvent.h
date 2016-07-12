#pragma once

#include "Engine\Core\EntityEventTypes.h"

namespace Engine
{

class InputEvent : public EntityEvent
{
public:
	enum Action {
		NONE,
		KEY_DOWN,
		KEY_UP
	};

	Action m_action;
	int m_keyCode;

	InputEvent() : EntityEvent(INPUT_EVENT), m_action(Action::NONE), m_keyCode(0) {}
	InputEvent(Action action, int key_code) : EntityEvent(INPUT_EVENT), m_action(action), m_keyCode(key_code) {}
};

}