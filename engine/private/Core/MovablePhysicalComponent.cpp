#include "Engine\Core\MovablePhysicalComponent.h"
#include <SDL_keycode.h>

namespace Engine
{

void MovablePhysicalComponent::ProcessInputEvent(const InputEvent &event) {
	if (event.m_action == InputEvent::KEY_DOWN) {
		switch (event.m_keyCode) {
		case SDLK_UP:    pos.y -= m_speed; break;
		case SDLK_DOWN:  pos.y += m_speed; break;
		case SDLK_RIGHT: pos.x += m_speed; break;
		case SDLK_LEFT:  pos.x -= m_speed; break;
		default: break;
		}
	}
}

}