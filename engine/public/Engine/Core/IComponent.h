#pragma once

#include "ComponentType.h"
#include "EntityEventTypes.h"
#include "Engine\Config.h"

namespace Engine
{

class ENGINE_API IComponent
{
public:
	const ComponentType m_componentType;

	IComponent(ComponentType componentType) : m_componentType(componentType), m_acceptedEvents(0) {}
	virtual ~IComponent() {}

	// Returns the events that this component accepts (ORed flags)
	EntityEventType AcceptedEvents() const { return m_acceptedEvents; }

	virtual void ProcessInputEvent(const InputEvent &event) {}

protected:
	// The types of events that this component accepts.
	EntityEventType m_acceptedEvents;

	// Enable, disable or toggles the acceptance of one or more events
	void EnableAcceptEvent(EntityEventType type) { m_acceptedEvents |= type; }
	void DisableAcceptEvent(EntityEventType type) { m_acceptedEvents &= ~type; }
	void ToggleAcceptEvent(EntityEventType type) { m_acceptedEvents ^= type; }
};

}