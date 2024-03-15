#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

#include "../Camera.h"
#include "../SceneObject.h"

namespace bbe
{

class RenderSystem
{
public:
	RenderSystem(Camera* camera);
	~RenderSystem();


	void update(std::vector<SceneObject*> objects);
private:
	Texture* _texture;
	Shader* _shader;
	Camera* _camera;
};

}
#endif // !_RENDER_SYSTEM_H_
