
#undef main
#include <Engine/System/System.h>
#include <Engine\Core\RenderComponent.h>
#include <Engine\Core\MovablePhysicalComponent.h>
#include <Engine\Rendering\Texture.h>
#include <Engine\Rendering\Sprite.h>

using namespace Engine;

int main(int argc, char **argv)
{
	auto system = new System();
	EntityID squareID;
	std::unique_ptr<Texture> tex(Texture::LoadTexture("../characters.tga"));

	system->Init({ 1024, 768, "Test" });

	squareID = system->NewEntity();
	system->EntityAddComponent(squareID, *(new RenderComponent(Sprite(tex.get(), 275, 41, 275 + 16, 41 + 20))));
	system->EntityAddComponent(squareID, *(new MovablePhysicalComponent(Vec2<int>(64, 64), Vec2<int>(64, 64), 3)));

	system->Start();
	
	return 0;
}