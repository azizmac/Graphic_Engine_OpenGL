#ifndef WINDOW_CAMERA_H_
#define WINDOW_CAMERA_H_

#include <glm/glm.hpp>

namespace bbe 
{

class Camera {
public:
	Camera(glm::vec3 position, float fov);

	glm::vec3 _front;
	glm::vec3 _up;
	glm::vec3 _right;
	glm::vec3 _direction;

	glm::vec3 _position;

	float _zoom;
	glm::mat4 _rotation;
	bool _perspective = true;
	bool _flipped = false;
	float _aspect = 0.0f;

	void rotate(float x, float y, float z);

	glm::mat4 getProjection(unsigned int windowWidth, unsigned int windowHeight);
	glm::mat4 getView(bool position = true);
	glm::mat4 getProjView(unsigned int windowWidth, unsigned int windowHeight, bool position = true);

	void setFov(float fov);
	float getFov() const;

private:
	void updateVectors();
	float fov;
};
}

#endif /* WINDOW_CAMERA_H_ */