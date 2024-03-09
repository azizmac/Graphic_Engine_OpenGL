#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Cube.h"
#include "Camera.h"
#include <vector>

namespace bbe 
{

class Window
{
public:
	Window(GLuint width, GLuint height, std::string title);
	~Window();

	void initialize();

	void setHeight(GLuint height);
	void setWidth(GLuint width);

	bool isRunning();

	void handleUpdate(float deltaTime);
	void update(float deltaTime);
	void draw();

	void close();
private:

	std::vector<Cube*> cubes;
	float angle;

	Camera* camera;
	GLFWwindow* _window;
	GLuint _width;
	GLuint _height;

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void frameBufferResize_callback(GLFWwindow* window, int width, int height);

};
}

#endif // !_WINDOW_H_
