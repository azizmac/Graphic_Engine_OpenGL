#ifndef _SCENE_OBJECT_H_
#define _SCENE_OBJECT_H_
#include <vector>
#include "Component.h"
#include "Graphics/MeshComponent.h"
#include "Graphics/Tranformable.h"

namespace bbe
{
class SceneObject : public Tranformable
{
public:
	SceneObject();
	~SceneObject();

	void update();
	void draw(); 
	
	void addComponent(Component* component);
	Component* getComponent(std::string componentType);


private:
	std::vector<Component*> _components;
};
}

#endif // !_SCENE_OBJECT_H_
