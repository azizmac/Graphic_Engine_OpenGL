#ifndef _ELEMENT_BUFFER_OBJECT
#define _ELEMENT_BUFFER_OBJECT
#include <glad/glad.h>
#include <vector>

namespace bbe
{
class EBO
{
public:
	EBO(std::vector<GLuint>& indices);

	void bind();
	void unbind();

	void clear();

	std::vector<GLuint> getIndices();
private:
	GLuint _ID;
	std::vector<GLuint> _indices;
};
}

#endif // !_ELEMENT_BUFFER_OBJECT
