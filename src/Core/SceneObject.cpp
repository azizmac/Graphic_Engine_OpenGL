#include "SceneObject.h"
#include <iostream>
#include "Graphics/MeshComponent.h"


bbe::SceneObject::SceneObject() : Tranformable()
{

}

bbe::SceneObject::~SceneObject()
{
}

void bbe::SceneObject::update()
{
}

void bbe::SceneObject::draw()
{
}

void bbe::SceneObject::addComponent(Component* component)
{
	_components.push_back(component);
}

bbe::Component* bbe::SceneObject::getComponent(std::string componentType)
{
	for (auto component : _components)
	{
		if (typeid(*component).name() == componentType)
		{
			return component;
		}
	}

	return nullptr;
}

