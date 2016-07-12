#pragma once

#include <vector>

#include "IComponent.h"

namespace Engine
{

typedef unsigned EntityID;

class Entity
{
public:
	Entity(EntityID entityID);
	virtual ~Entity();

	/*
	 * Adds a component to the entity.
	 * The entity takes ownership of the component's pointer.
	 */
	void AddComponent(IComponent &component);

	template<class T>
	T *GetComponent() {
		for (auto ptr : m_components) {
			if (ptr->m_componentType == T::componentType)
				return static_cast<T*>(ptr);
		}

		return nullptr;
	}

	template<class T>
	const T *GetComponent() const {
		for (auto ptr : m_components) {
			if (ptr->componentType == T::componentType)
				return static_cast<const T*>(ptr);
		}

		return nullptr;
	}

	EntityID GetEntityID() const { return m_entityID; }

	/*
	 * Searches for all the components that can process
	 * the event and calls the appropiate method.
	 */
	void PostEvent(const EntityEvent &event);

protected:
	std::vector<IComponent*> m_components;
	EntityID m_entityID;

};

}
