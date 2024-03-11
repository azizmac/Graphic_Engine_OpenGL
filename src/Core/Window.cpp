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
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	

	glfwSetWindowUserPointer(_window, this);
	
	auto keyCallback = [](GLFWwindow* window, int key, int scancode, int action, int mods) 
	{
		auto tWindow = (Window*)glfwGetWindowUserPointer(window);
		tWindow->key_callback(window, key, scancode, action, mods);
	};

	glfwSetKeyCallback(_window, keyCallback);
	
	auto frameBufferResizeCallback = [](GLFWwindow* window, int width, int height) 
	{
		auto tWindow = (Window*)glfwGetWindowUserPointer(window);
		tWindow->frameBufferResize_callback(window, width, height);
	};
	glfwSetFramebufferSizeCallback(_window, frameBufferResizeCallback);

	auto mouseCallback = [](GLFWwindow* window, double xpos, double ypos)
	{
			auto tWindow = (Window*)glfwGetWindowUserPointer(window);
			tWindow->mouse_callback(window, xpos, ypos);
	};

	glfwSetCursorPosCallback(_window, mouseCallback);

	angle = 0;
	
	yaw = 0;
	pitch = 0;
	lastX = 0;
	lastY = 0;
}

bbe::Window::~Window()
{
	glfwDestroyWindow(_window);
}

void bbe::Window::initialize()
{
	glViewport(0, 0, _width, _height);

	for (int i = 0; i < 5; i++)
	{
		cubes.emplace_back(new Cube);

		float randX =  -1 + std::rand() % 2;
		float randY = -1 + std::rand() % 2;

		
		cubes[i]->setPosition(glm::vec3(randX + i * 2.0f, randY + i * 2.0f, -6.0f * i));

	}

	// Каркасное представление моделей
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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
	float cameraSpeed = 5.0f;
	if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		cameraSpeed *= 10;
	}
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
	angle += 1.0f * deltaTime * 100;
	for (int i = 0; i < 5; i++)
	{
		cubes[i]->setRotation(angle);
	}
}

void bbe::Window::draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for (int i = 0; i < 5; i++)
	{

		cubes[i]->getShader()->setMat4("projection", camera->getProjection(_width, _height));
		cubes[i]->getShader()->setMat4("view", camera->getView());

		cubes[i]->draw();
	}

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

void bbe::Window::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	const float sensitivity = 0.5f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;


	yaw += yoffset / _height;
	pitch -= xoffset / _height;


	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}
	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}

	camera->_rotation = glm::mat4(1.0f);
	camera->rotate(yaw, pitch, 0);
}

void bbe::Window::frameBufferResize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
