#include "EBO.h"

bbe::EBO::EBO(std::vector<GLuint>& indicies)
{
	_indices = indicies;

	glGenBuffers(1, &_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), _indices.data(), GL_STATIC_DRAW);
}

void bbe::EBO::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ID);
}

void bbe::EBO::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void bbe::EBO::clear()
{
	glDeleteBuffers(1, &_ID);
}

std::vector<GLuint> bbe::EBO::getIndices()
{
	return _indices;
}


