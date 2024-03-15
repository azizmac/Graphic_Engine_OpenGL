#ifndef _CUBE_MESH_H_
#define _CUBE_MESH_H_
#include <vector>
#include "../VBO.h"

namespace bbe
{
class CubeMesh
{
public:
	static std::vector<Vertex> vertices;
	static std::vector<GLuint> indices;
};
}

#endif