#include "Tranformable.h"

bbe::Tranformable::Tranformable()
{
	_tranformMatrix = glm::mat4(1.0f);
	_position = glm::vec3(1.0f);
	_rotation = 0;
	_scale = glm::vec3(1.0f);
	_origin = glm::vec3(0.0f, 0.0f, 0.0f);
}

bbe::Tranformable::~Tranformable()
{
}

void bbe::Tranformable::setPosition(const glm::vec3& position)
{
	_position = position;
}

void bbe::Tranformable::setScale(const glm::vec3& scale)
{
	_scale = scale;
}

void bbe::Tranformable::setRotation(float rotation)
{
	_rotation = rotation;
}

const glm::vec3& bbe::Tranformable::getPosition() const
{
	return _position;
}

const glm::vec3& bbe::Tranformable::getScale() const
{
	return _scale;
}

float bbe::Tranformable::getRotation() const
{
	return _rotation;
}

void bbe::Tranformable::move(const glm::vec3& offset)
{
	_position += offset;
}

void bbe::Tranformable::move(float xOffset, float yOffset, float zOffset)
{
	_position += glm::vec3(xOffset, yOffset, zOffset);
}

void bbe::Tranformable::rotate(float angleOffset)
{
	_rotation += angleOffset;
}

const glm::mat4& bbe::Tranformable::getTransformMatrix() 
{
	_tranformMatrix = glm::mat4(1.0f);
	_tranformMatrix = glm::translate(_tranformMatrix, _position);
	_tranformMatrix = glm::rotate(_tranformMatrix, glm::radians(_rotation), glm::vec3(0.0f, 1.0f, 0.0f));
	_tranformMatrix = glm::translate(_tranformMatrix, _origin);
	_tranformMatrix = glm::scale(_tranformMatrix, _scale);
	
	return _tranformMatrix;
}


