#pragma once

namespace Engine {

typedef int EntityEventType;

#define INPUT_EVENT 0x1

class EntityEvent {
public:
	const EntityEventType m_eventType;

	EntityEvent(EntityEventType type) : m_eventType(type) {}
};

class InputEvent;

}