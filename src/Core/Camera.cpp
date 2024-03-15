#include "Camera.h"
#include "Window.h"

#include <glm/ext.hpp>



bbe::Camera::Camera(glm::vec3 position, float fov) : fov(fov), _position(position), _zoom(1.0f), _rotation(1.0f) 
{
	updateVectors();
}

void bbe::Camera::updateVectors() 
{
	_front = glm::vec3(_rotation * glm::vec4(0, 0, -1, 1));
	_right = glm::vec3(_rotation * glm::vec4(1, 0, 0, 1));
	_up = glm::vec3(_rotation * glm::vec4(0, 1, 0, 1));
	_direction = glm::vec3(_rotation * glm::vec4(0, 0, -1, 1));
	_direction.y = 0;
	float len = length(_direction);
	if (len > 0.0f) 
	{
		_direction.x /= len;
		_direction.z /= len;
	}

}

void bbe::Camera::rotate(float x, float y, float z) 
{
	_rotation = glm::rotate(_rotation, z, glm::vec3(0, 0, 1));
	_rotation = glm::rotate(_rotation, y, glm::vec3(0, 1, 0));
	_rotation = glm::rotate(_rotation, x, glm::vec3(1, 0, 0));

	updateVectors();
}

glm::mat4 bbe::Camera::getProjection(unsigned int width, unsigned int height) 
{
	float aspect = this->_aspect;
	if (aspect == 0.0f) 
	{
		aspect = (float)width / (float)height;
	}
	if (_perspective)
	{
		return glm::perspective(fov * _zoom, aspect, 0.05f, 1500.0f);
	}
	else
	{
		if (_flipped)
		{
			return glm::ortho(0.0f, fov * aspect, fov, 0.0f);
		}
		else
		{
			return glm::ortho(0.0f, fov * aspect, 0.0f, fov);
		}
	}
}

glm::mat4 bbe::Camera::getView(bool pos) {
	glm::vec3 position = this->_position;
	if (!pos) 
	{
		position = glm::vec3(0.0f);
	}
	if (_perspective) 
	{
		return glm::lookAt(position, position + _front, _up);
	}
	else 
	{
		return glm::translate(glm::mat4(1.0f), position);
	}
}

glm::mat4 bbe::Camera::getProjView(unsigned int width, unsigned int height, bool pos) 
{
	return getProjection(width, height) * getView(pos);
}

void bbe::Camera::setFov(float fov) 
{
	this->fov = fov;
}

float bbe::Camera::getFov() const 
{
	return fov;
}