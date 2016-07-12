#include "Engine\Core\Entity.h"

#include "Utilities.h"

namespace Engine
{

Entity::Entity(EntityID entityID) : m_entityID(entityID) {}

Entity::~Entity() {
	// free up pointers
	for (auto ptr : m_components)
		delete ptr;

	m_components.clear();
}

void Entity::AddComponent(IComponent &component) {
	m_components.push_back(&component);
}

void Entity::PostEvent(const EntityEvent &event) {
	for (int i = 0; i < (int) m_components.size(); i++) {
		if ((m_components[i]->AcceptedEvents() & event.m_eventType) != 0) {
			switch (event.m_eventType) {
			case INPUT_EVENT:
				m_components[i]->ProcessInputEvent((const InputEvent&)event);
				break;

			default:
				RUNTIME_ASSERT(false);
				break;
			}
		}
	}
}

}