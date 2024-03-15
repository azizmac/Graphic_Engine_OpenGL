#include "VBO.h"
#include <iostream>

bbe::VBO::VBO(std::vector<Vertex>& vertices)
{
	_vertices = vertices;
	glGenBuffers(1, &_ID);
	glBindBuffer(GL_ARRAY_BUFFER, _ID);
	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), (void*)_vertices.data(), GL_STATIC_DRAW);
}

void bbe::VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, _ID);
}

void bbe::VBO::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void bbe::VBO::clear()
{
	glDeleteBuffers(1, &_ID);
}

const std::vector<bbe::Vertex>& bbe::VBO::getVertices()
{
	return _vertices;
}

