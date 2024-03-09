#include "Window.h"
#include <iostream>
#include <glm/ext.hpp>

bbe::Window::Window(GLuint width, GLuint height, std::string title)
{
	camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f), 45.0f);

	camera->_front = glm::vec3(0.0f, 0.0f, -1.0f);
	camera->_up = glm::vec3(0.0f, 1.0f, 0.0f);

	_width = width;
	_height = height;
	_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(_window);
	glfwSwapInterval(1);
	

	glfwSetWindowUserPointer(_window, this);
	
	auto keyCallback = [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		auto tWindow = (Window*)glfwGetWindowUserPointer(window);
		tWindow->key_callback(window, key, scancode, action, mods);
	};

	glfwSetKeyCallback(_window, keyCallback);
	
	auto frameBufferResizeCallback = [](GLFWwindow* window, int width, int height) {
		auto tWindow = (Window*)glfwGetWindowUserPointer(window);
		tWindow->frameBufferResize_callback(window, width, height);
	};

	glfwSetFramebufferSizeCallback(_window, frameBufferResizeCallback);

	
}

bbe::Window::~Window()
{
	delete cube;
	glfwDestroyWindow(_window);
}

void bbe::Window::initialize()
{
	glViewport(0, 0, _width, _height);
	cube = new Cube();
}

void bbe::Window::setHeight(GLuint height)
{
	_height = height;
	glfwSetWindowSize(_window, _width, _height);
}

void bbe::Window::setWidth(GLuint width)
{
	_width = width;
	glfwSetWindowSize(_window, _width, _height);
}

bool bbe::Window::isRunning()
{
	return !glfwWindowShouldClose(_window);
}

void bbe::Window::handleUpdate(float deltaTime)
{
	glfwPollEvents();
	float cameraSpeed = 0.5f;
	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera->_position += cameraSpeed * camera->_front * deltaTime;
	}
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera->_position -= cameraSpeed * camera->_front * deltaTime;
	}
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera->_position -= glm::normalize(glm::cross(camera->_front, camera->_up)) * cameraSpeed * deltaTime;
	}
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
	{
		camera->_position += glm::normalize(glm::cross(camera->_front, camera->_up)) * cameraSpeed * deltaTime;
	}
}

void bbe::Window::update(float deltaTime)
{
}

void bbe::Window::draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glm::mat4 model = glm::mat4(1.0f);
	cube->getShader()->setMat4("projection", camera->getProjection(_width, _height));
	cube->getShader()->setMat4("view", camera->getView());
	cube->getShader()->setMat4("model", model);

	cube->draw();

	glfwSwapBuffers(_window);

}

void bbe::Window::close()
{
	glfwSetWindowShouldClose(_window, GL_TRUE);
}

void bbe::Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		close();
	}
}

void bbe::Window::frameBufferResize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
