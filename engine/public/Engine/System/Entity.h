#pragma once

#include <vector>

#include "IComponent.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void AddComponent(IComponent &component);

	template<class T>
	T *GetComponent() {
		for (auto ptr : components) {
			if (ptr->componentType == T::componentType)
				return ptr;
		}

		return nullptr;
	}

protected:
	std::vector<IComponent*> components;

};

