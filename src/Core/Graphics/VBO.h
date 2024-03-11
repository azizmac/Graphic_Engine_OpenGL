#include <glad/glad.h>
#include <vector>
#ifndef _VERTEX_BUFFER_OBJECT_H_
#define _VERTEX_BUFFER_OBJECT_H_

namespace bbe
{
class VBO 
{
public:
	VBO(std::vector<float> vertices);
	VBO(float vertices[108]);

	void bind();
	void unbind();

	void clear();

	std::vector<float> getVertices();
private:
	GLuint _ID;
	std::vector<float> _vertices;
};
}

#endif // !_VERTEX_BUFFER_OBJECT_H_

