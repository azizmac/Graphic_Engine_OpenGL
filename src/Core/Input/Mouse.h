#ifndef _MOUSE_H_
#define _MOUSE_H_
#include <glm/glm.hpp>

namespace bbe
{
class Mouse
{
public:
	static glm::vec2 getPosition();

	friend class Window;
private:
	static float x;
	static float y;

};
}

#endif