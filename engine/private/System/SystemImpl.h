#include <SDL.h>
#include <SDL_opengl.h>
#include <Engine/Config.h>
#include <Engine\Core\Entity.h>

#include <unordered_map>

namespace Engine
{
	class Renderer;
	struct SCreationSettings;

	class ENGINE_API SystemImpl
	{
	public:
		void Init(SCreationSettings&& cs);
		void Start();

		EntityID NewEntity();
		bool EntityAddComponent(EntityID entityID, IComponent &component);

	protected:
		SDL_Window* m_window;
		SDL_GLContext m_context;
		Renderer* m_renderer;

		std::unordered_map<EntityID, Entity> m_entities;

		static EntityID nextEntityID;
	};
}