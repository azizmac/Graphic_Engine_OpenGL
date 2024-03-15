#include "MeshComponent.h"

bbe::MeshComponent::MeshComponent(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, Tranformable* transform) : Component()
{
	_vertices = vertices;
	_indices = indices;
	_shader = new Shader("shaders/vertexShader.vert", "shaders/fragmentShader.frag");
	_transform = transform;

	_VAO.bind();

	_VBO = new VBO(vertices);
	_EBO = new EBO(indices);

	_VAO.setAttrib(*_VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	
	_VAO.unbind();
	_VBO->unbind();
	_EBO->unbind();
}

void bbe::MeshComponent::draw(Camera& camera)
{
	_shader->use();
	_shader->setMat4("projection", camera.getProjection(800, 600));
	_shader->setMat4("view", camera.getView());
	_shader->setMat4("model", _transform->getTransformMatrix());
	_VAO.bind();
	glDrawElements(GL_TRIANGLES, _EBO->getIndices().size(), GL_UNSIGNED_INT, 0);
}
