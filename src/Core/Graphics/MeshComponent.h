#ifndef _MESH_H_
#define _MESH_H_
#include "EBO.h"
#include "VBO.h"
#include "VAO.h"
#include "../Shader.h"
#include "../Camera.h"
#include "../Component.h"
#include "Tranformable.h"

namespace bbe
{


class MeshComponent : public Component
{
public:
	MeshComponent(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, Tranformable* transform);

	void draw(Camera& camera);
private:
	Tranformable* _transform;

	std::vector<Vertex> _vertices;
	std::vector<GLuint> _indices;
	
	Shader* _shader;

	VAO _VAO;
	VBO* _VBO;
	EBO* _EBO;

};
}

#endif // !_MESH_H_
