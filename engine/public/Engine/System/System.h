#pragma once
#include <memory>
#include <Engine/Config.h>
#include <Engine\Core\Entity.h>
#include "CreationSettigns.h"
namespace Engine
{

class SystemImpl;
class ENGINE_API System
{
public:
	System();
	~System();

	void Init(SCreationSettings&& cs);
	void Start();

	/*
	 * Creates a new empty entry and returns it's ID.
	 */
	EntityID NewEntity();

	/*
	 * Will call Entity::AddComponent.
	 * The entity takes ownership of the component's pointer.
	 * Returns false if the EntityID is invalid.
	 */
	bool EntityAddComponent(EntityID entityID, IComponent &component);

protected:
	std::unique_ptr<SystemImpl> m_impl;
};

}