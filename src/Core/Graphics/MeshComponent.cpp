#include "MeshComponent.h"

bbe::MeshComponent::MeshComponent(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, Tranformable* transform) : Component()
{
	_vertices = vertices;
	_indices = indices;
	_transform = transform;

	_VAO.bind();

	_VBO = new VBO(vertices);
	_EBO = new EBO(indices);

	_VAO.setAttrib(*_VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	_VAO.setAttrib(*_VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * (sizeof(float))) );
	_VAO.setAttrib(*_VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * (sizeof(float))));

	_VAO.unbind();
	_VBO->unbind();
	_EBO->unbind();
}

void bbe::MeshComponent::draw(Shader& shader, Camera& camera, Texture& texture)
{
	shader.use();
	texture.bind();
	shader.setMat4("projection", camera.getProjection(800, 600));
	shader.setMat4("view", camera.getView());
	shader.setMat4("model", _transform->getTransformMatrix());
	_VAO.bind();
	glDrawElements(GL_TRIANGLES, _EBO->getIndices().size(), GL_UNSIGNED_INT, 0);
}
