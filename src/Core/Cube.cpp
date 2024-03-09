#include "Cube.h"

#include <glm/ext.hpp>

bbe::Cube::Cube()
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

    _position = glm::vec3(0.0f, 0.0f, 0.0f);
    _rotation = 0;
    _scale = glm::vec3(1.0f);

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

void bbe::Cube::setPosition(const glm::vec3& position)
{
    _position = position;
}

void bbe::Cube::setRotation(const float& rotation)
{
    _rotation = rotation;
}

void bbe::Cube::setScale(const glm::vec3& scale)
{
    _scale = scale;
}

const glm::vec3& bbe::Cube::getPosition() const
{
    return _position;
}

const float& bbe::Cube::getRotation() const
{
    return _rotation;
}

const glm::vec3& bbe::Cube::getScale() const
{
    return _scale;
}


const glm::mat4& bbe::Cube::getTransform() const
{
    return _transform;
}

void bbe::Cube::draw()
{
    _shader->use();
    _transform = glm::mat4(1.0f);
    _transform = glm::translate(_transform, _position);
    _transform = glm::rotate(_transform, glm::radians(_rotation), glm::vec3(1.0f, 0.3f, 0.5f));
    _transform = glm::scale(_transform, _scale);

    _shader->setMat4("model", _transform);
    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / 3);
}
