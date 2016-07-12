
#undef main
#include <Engine/System/System.h>
#include <Engine\Core\RenderComponent.h>
#include <Engine\Core\MovablePhysicalComponent.h>

using namespace Engine;

int main(int argc, char **argv)
{
	auto system = new System();
	EntityID squareID;

	system->Init({ 1024, 768, "Test" });

	squareID = system->NewEntity();
	system->EntityAddComponent(squareID, *(new RenderComponent(Color<float>(1.0, 0, 0))));
	system->EntityAddComponent(squareID, *(new MovablePhysicalComponent(Vec2<int>(64, 64), Vec2<int>(64, 64), 3)));

	system->Start();
	return 0;
}