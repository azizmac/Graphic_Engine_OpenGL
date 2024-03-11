#ifndef _VERTEX_ARRAY_OBJECT_H_
#define _VERTEX_ARRAY_OBJECT_H_

#include <glad/glad.h>
#include "VBO.h"

namespace bbe
{
class VAO 
{
public:
	VAO();
	~VAO();

	const GLuint& getID() const;

	void setAttrib(VBO& vbo, GLuint layout, GLuint elemCount, GLenum type, GLsizeiptr stride, void* offset);

	void bind();
	void unbind();

	void clear();
private:
	GLuint ID;
};
}

#endif