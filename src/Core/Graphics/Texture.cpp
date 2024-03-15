#include "Texture.h"
#include <stb_image.h>

bbe::Texture::Texture()
{
	glGenTextures(1, &_ID);
}

bbe::Texture::~Texture()
{
}

void bbe::Texture::load(std::string filename)
{

	int channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filename.c_str(), &_width, &_height, &channels, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	if (channels == 4)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void bbe::Texture::setTextureUniform(Shader* shader, std::string uniform, GLuint layout)
{
	shader->use();
	shader->setInt(uniform, layout);
}

void bbe::Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, _ID);
}

void bbe::Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
