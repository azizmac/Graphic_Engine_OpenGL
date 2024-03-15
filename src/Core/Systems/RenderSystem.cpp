#include "RenderSystem.h"



bbe::RenderSystem::RenderSystem(Camera* camera)
{
	_camera = camera;
	_shader = new Shader("shaders/vertexShader.vert", "shaders/fragmentShader.frag");
	_texture = new Texture();
	_texture->load("images/cat.jpg");
	_texture->setTextureUniform(_shader, "tex0", 0);
}

bbe::RenderSystem::~RenderSystem()
{
	delete _shader;
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
	

	mesh->draw(*_shader, *_camera, *_texture);
}
