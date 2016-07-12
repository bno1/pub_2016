#include "System/SystemImpl.h"
#include <Engine/System/System.h>
#include <type_traits>

namespace Engine
{
System::System()
:	m_impl(new SystemImpl())
{
	
};


System::~System()
{

}
void System::Init(SCreationSettings&& cs)
{
	m_impl->Init(std::forward<SCreationSettings>(cs));
}
void System::Start()
{
	m_impl->Start();
}

EntityID System::NewEntity() {
	return m_impl->NewEntity();
}

bool System::EntityAddComponent(EntityID entityID, IComponent &component) {
	return m_impl->EntityAddComponent(entityID, component);
}
}