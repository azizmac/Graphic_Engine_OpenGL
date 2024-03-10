#include "Cube.h"

#include <glm/ext.hpp>

bbe::Cube::Cube() 
    : Tranformable()
{

    _shader = new Shader("shaders/vertexShader.vert", "shaders/fragmentShader.frag");

    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);

    glBindVertexArray(_VAO);
  
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

bbe::Cube::~Cube()
{
    delete _shader;
    
    glDeleteVertexArrays(1, &_VAO);
    glDeleteBuffers(1, &_VBO);
}

bbe::Shader* bbe::Cube::getShader()
{
    return _shader;
}

void bbe::Cube::draw()
{
    _shader->use();
    _shader->setMat4("model", getTransformMatrix());
    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / 3);
}
