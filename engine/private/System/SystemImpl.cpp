#include <Engine/System/System.h>
#include <Engine/Rendering/OpenGLRenderer.h>
#include <Engine/Core/RenderComponent.h>
#include <Engine/Core/PhysicalComponent.h>
#include <Engine\Core\EntityEvents\InputEvent.h>
#include "System/SystemImpl.h"

namespace Engine
{

EntityID SystemImpl::nextEntityID = 1;

void SystemImpl::Init(SCreationSettings&& cs)
{
	SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);
	m_window = SDL_CreateWindow(cs.windowTitle, 100, 100, cs.windowWidth, cs.windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	m_context = SDL_GL_CreateContext(m_window);
	//if (cs.hideWindow)
	//	SDL_HideWindow(m_window);
	SDL_GL_SetSwapInterval(0);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	glClearColor(0.1f, 0.1f, 0.1f, 1.f);

	glEnable(GL_TEXTURE_2D);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_NORMALIZE);
	m_renderer = new Renderer();
	m_renderer->Init();
	m_renderer->OnResize(cs.windowWidth, cs.windowHeight);
}

void SystemImpl::Start()
{
	bool done = false;
	int speed = 3;
	while (!done) {
		m_renderer->BeginFrame();

		for (auto iter = m_entities.begin(); iter != m_entities.end(); ++iter) {
			RenderComponent *rc = iter->second.GetComponent<RenderComponent>();
			PhysicalComponent *pc = iter->second.GetComponent<PhysicalComponent>();

			if (rc != nullptr && pc != nullptr) {
				m_renderer->RenderSprite(Sprite(nullptr, 0, 0, pc->size.x, pc->size.y), pc->pos.x, pc->pos.y);
			}
		}
		
		/*Engine::Texture* tex = Engine::Texture::LoadTexture("../characters.tga");
		m_renderer->RenderSprite(Sprite(tex, 275,41, 275+16, 41+20), posX, posY);*/

		SDL_Event evt;
		while (SDL_PollEvent(&evt)) {
			InputEvent event;

			switch (evt.type)
			{
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				event.m_action = evt.type == SDL_KEYDOWN ? InputEvent::KEY_DOWN : InputEvent::KEY_UP;
				event.m_keyCode = evt.key.keysym.sym;

				// send input event to every entity
				for (auto iter = m_entities.begin(); iter != m_entities.end(); ++iter)
					iter->second.PostEvent(event);

				break;

			case SDL_WINDOWEVENT:
				switch (evt.window.event) {
				case SDL_WINDOWEVENT_RESIZED:
				{
					SDL_Window *window = SDL_GetWindowFromID(evt.window.windowID);
					int w, h;
					SDL_GetWindowSize(window, &w, &h);
					m_renderer->OnResize(w, h);
					break;
				}
				case SDL_WINDOWEVENT_CLOSE:
				{
					SDL_Window *window = SDL_GetWindowFromID(evt.window.windowID);
					if (window)
					{
						SDL_DestroyWindow(window);
					}
					break;
				}
				break;
				}
				break;
			}
		}
		m_renderer->EndFrame();
		SDL_GL_MakeCurrent(m_window, m_context);
		SDL_GL_SwapWindow(m_window);
	}
};

EntityID SystemImpl::NewEntity() {
	EntityID id = nextEntityID++;

	m_entities.emplace(id, Entity(id));

	return id;
}

bool SystemImpl::EntityAddComponent(EntityID entityID, IComponent &component) {
	auto iter = m_entities.find(entityID);

	if (iter == m_entities.end())
		return false;

	iter->second.AddComponent(component);
	return true;
}

}