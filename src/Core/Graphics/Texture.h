#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include <glad/glad.h>
#include <string>
#include "../Shader.h"

namespace bbe
{

class Texture
{
public:
	Texture();
	~Texture();

	void load(std::string filename);
	void setTextureUniform(Shader* shader, std::string uniform, GLuint layout);


	void bind();
	void unbind();
private:
	GLuint _ID;
	int _width;
	int _height;
};
}

#endif