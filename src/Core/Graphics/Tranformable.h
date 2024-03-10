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
	/// ��������� ������� ��������
	/// </summary>
	/// <param name="position">����� � ������������ � ���� ����������� �������</param>
	void setPosition(const glm::vec3& position);
	/// <summary>
	/// ��������� �����-�������
	/// </summary>
	/// <param name="scale">������ ����� �������</param>
	void setScale(const glm::vec3& scale);

	/// <summary>
	/// ��������� �������� ��������
	/// </summary>
	/// <param name="rotation">���� �������� � ��������</param>
	void setRotation(float rotation);

	const glm::vec3& getPosition() const;
	const glm::vec3& getScale() const;
	float getRotation() const;

	void move(const glm::vec3& offset);
	void move(float xOffset, float yOffset, float zOffset);
	void rotate(float angleOffset);

	const glm::mat4& getTransformMatrix();


private:
	glm::mat4 _tranformMatrix; // �������� ������� 
	glm::vec3 _position; // ������� ��������
	glm::vec3 _scale; // ������ ��������� ��������
	float _rotation; // ������� �������� � ��������
	glm::vec3 _origin; // �����, �� ������� ����� ����������� ��������������
};

}

#endif // !_TRANSFROMABLE_H_
