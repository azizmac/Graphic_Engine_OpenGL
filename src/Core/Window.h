#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include <vector>
#include "SceneObject.h"
#include "Systems/RenderSystem.h"
#include "Input/Mouse.h"

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

	// Тестовые штуки, подлежат удалению
	float angle;

	Camera* camera;
	GLFWwindow* _window;
	GLuint _width;
	GLuint _height;

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void frameBufferResize_callback(GLFWwindow* window, int width, int height);


	// TODO: Вынести эти переменные в другие классы
	float lastX = 0;
	float lastY = 0;

	float yaw = 0;
	float pitch = 0;

	SceneObject* object;

	RenderSystem* _renderSystem;
	std::vector<SceneObject*> sceneObjects;


};
}

#endif // !_WINDOW_H_
