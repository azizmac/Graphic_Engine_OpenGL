#include "RenderSystem.h"



bbe::RenderSystem::RenderSystem(Camera* camera)
{
	_camera = camera;
}

void bbe::RenderSystem::update(std::vector<SceneObject*> objects)
{
	MeshComponent* mesh = nullptr;
	for (int i = 0; i < objects.size(); i++)
	{
		mesh = (MeshComponent*)objects[i]->getComponent("class bbe::MeshComponent");
	}

	if (mesh == nullptr)
	{
		return;
	}
	

	mesh->draw(*_camera);
}
