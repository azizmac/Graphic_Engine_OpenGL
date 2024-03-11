#include "Cube.h"
 
#include <glm/ext.hpp>

bbe::Cube::Cube() 
    : Tranformable()
{

    _shader = new Shader("shaders/vertexShader.vert", "shaders/fragmentShader.frag");
    
    

    _VAO.bind();
    
    _VBO = new VBO(std::vector<float>{
        -1.0, -1.0, 1.0,
        1.0, -1.0, 1.0,
        -1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
        -1.0, -1.0, -1.0,
        1.0, -1.0, -1.0,
        -1.0, 1.0, -1.0,
        1.0, 1.0, -1.0
    });

    _EBO = new EBO(std::vector<GLuint>{
        0, 1, 2, 1, 3, 2, // передн€€ грань
        1, 5, 3, 5, 7, 3, // права€ грань
        5, 4, 7, 4, 6, 7, // задн€€ грань
        4, 0, 6, 0, 2, 6, // лева€ грань
        4, 5, 0, 5, 1, 0, // нижн€€ грань
        2, 3, 6, 3, 7, 6  // верхн€€ грань
    });

    _VAO.setAttrib(*_VBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
    _VAO.unbind();
    _VBO->unbind();
    _EBO->unbind();


}

bbe::Cube::~Cube()
{
    delete _shader;
}

bbe::Shader* bbe::Cube::getShader()
{
    return _shader;
}

void bbe::Cube::draw()
{
    _shader->use();
    _shader->setMat4("model", getTransformMatrix());
    _VAO.bind();
    glDrawElements(GL_TRIANGLES, _EBO->getIndices().size(), GL_UNSIGNED_INT, 0);
}
