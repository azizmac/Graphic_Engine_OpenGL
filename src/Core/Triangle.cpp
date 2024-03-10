#include "Triangle.h"

#include <glm/ext.hpp>


bbe::Triangle::Triangle()
	: Tranformable()
{
	_shader = new Shader("shaders/vertexShader.vert", "shaders/fragmentShader.frag");
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

    glGenBuffers(1, &_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);//3 * sizeof(float), (void*)0s

    glBindVertexArray(0);
}
bbe::Triangle::~Triangle()
{
    delete _shader;

    glDeleteBuffers(1, &_VBO);
    glDeleteVertexArrays(1, &_VAO);

}

bbe::Shader* bbe::Triangle::getShader()
{
    return _shader;
}

void bbe::Triangle::draw()
{

    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    _shader->use();
    _shader->setMat3("model", getTransformMatrix());
    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / 3);
}

