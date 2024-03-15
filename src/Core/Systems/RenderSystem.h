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

	void update(std::vector<SceneObject*> objects);
private:
	Camera* _camera;
};

}
#endif // !_RENDER_SYSTEM_H_
