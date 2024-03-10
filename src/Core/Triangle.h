#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Shader.h"
#include "Graphics/Tranformable.h"
namespace bbe 
{

    class Triangle : public Tranformable{
    private:
        GLuint _VAO, _VBO;
        const GLfloat vertices[3][2] = {
            { 0.0f, 1.0f },
            { -1.0f, -1.0f },
            { 1.0f, -1.0f }
        };

        Shader* _shader;

    public:
        Triangle();
        ~Triangle();

        Shader* getShader();
        void draw();
    };


}
#endif // !_TRIANGLE_H_