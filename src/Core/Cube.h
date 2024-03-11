#ifndef _CUBE_H_
#define _CUBE_H_

#include "Shader.h"
#include "Graphics/Tranformable.h"
#include "Graphics/VAO.h"
#include "Graphics/EBO.h"

namespace bbe
{

class Cube : public Tranformable
{
public:
	Cube();
	~Cube();

    Shader* getShader();

	void draw();
private:

	VAO _VAO;
	VBO* _VBO;
    EBO* _EBO;


	Shader* _shader;
};

}

#endif // !_CUBE_H_
