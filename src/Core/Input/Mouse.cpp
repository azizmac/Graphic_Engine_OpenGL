#include "Mouse.h"

float bbe::Mouse::x = 0;
float bbe::Mouse::y = 0;

glm::vec2 bbe::Mouse::getPosition()
{
	return glm::vec2(x, y);
}
