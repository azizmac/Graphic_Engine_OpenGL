#ifndef _TRANSFORMABLE_H_
#define _TRANSFORMABLE_H_

#include <glm/ext.hpp>

namespace bbe
{

class Tranformable
{
public:
	Tranformable();

	virtual ~Tranformable();

	/// <summary>
	/// Установка позиции сущности
	/// </summary>
	/// <param name="position">Точка в пространстве в виде трехмерного вектора</param>
	void setPosition(const glm::vec3& position);
	/// <summary>
	/// Установка скейл-фактора
	/// </summary>
	/// <param name="scale">Вектор скейл фактора</param>
	void setScale(const glm::vec3& scale);

	/// <summary>
	/// Установка поворота сущности
	/// </summary>
	/// <param name="rotation">Угол поворота в градусах</param>
	void setRotation(float rotation);

	const glm::vec3& getPosition() const;
	const glm::vec3& getScale() const;
	float getRotation() const;

	void move(const glm::vec3& offset);
	void move(float xOffset, float yOffset, float zOffset);
	void rotate(float angleOffset);

	const glm::mat4& getTransformMatrix();


private:
	glm::mat4 _tranformMatrix; // Итоговая матрица 
	glm::vec3 _position; // Позиция сущности
	glm::vec3 _scale; // Вектор скейлинга сущности
	float _rotation; // Поворот сущности в градусах
	glm::vec3 _origin; // Точка, от которой будут происходить преобразования
};

}

#endif // !_TRANSFROMABLE_H_
