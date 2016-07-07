#pragma once

enum class ComponentType {
	PSHYSICAL_COMPONENT,
	RENDER_COMPONENT,
};

#define DECLARE_COMPONENT_TYPE(type) static const ComponentType componentType = type;