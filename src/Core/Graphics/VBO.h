#include <glad/glad.h>
#include <vector>
#include <glm/ext.hpp>
#ifndef _VERTEX_BUFFER_OBJECT_H_
#define _VERTEX_BUFFER_OBJECT_H_

namespace bbe
{

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 uvTexture;
};

class VBO 
{
public:
	VBO(std::vector<Vertex>& vertices);

	void bind();
	void unbind();

	void clear();

	const std::vector<Vertex>& getVertices();
private:
	GLuint _ID;
	std::vector<Vertex> _vertices;
};
}

#endif // !_VERTEX_BUFFER_OBJECT_H_