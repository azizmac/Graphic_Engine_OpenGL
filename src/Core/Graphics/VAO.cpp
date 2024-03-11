#include "VAO.h"

bbe::VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

bbe::VAO::~VAO()
{
	glDeleteVertexArrays(1, &ID);
}

const GLuint& bbe::VAO::getID() const
{
	return ID;
}

void bbe::VAO::setAttrib(VBO& vbo, GLuint layout, GLuint elemCount, GLenum type, GLsizeiptr stride, void* offset)
{
	vbo.bind();
	glVertexAttribPointer(layout, elemCount, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	vbo.unbind();
}

void bbe::VAO::bind()
{
	glBindVertexArray(ID);
}

void bbe::VAO::unbind()
{
	glBindVertexArray(0);
}

void bbe::VAO::clear()
{
	glDeleteVertexArrays(1, &ID);
}

