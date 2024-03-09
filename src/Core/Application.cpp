#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace bbe;

Application::Application()
{
	_currentFrameTime = 0.0f;
	_lastFrameTime = 0.0f;
}

bbe::Application::~Application()
{
	glfwTerminate();
}

void Application::initialize()
{
	if (!glfwInit())
	{
		std::cerr << "Error glfw initialization!" << std::endl;
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	_window = new Window(800, 600, "TestEngine");

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Error glad initialization!" << std::endl;
		return;
	}

	_window->initialize();

}

void Application::run()
{
	while (_window->isRunning())
	{
		_currentFrameTime = glfwGetTime();
		float deltaTime = _currentFrameTime - _lastFrameTime;
		_lastFrameTime = _currentFrameTime;
		handleUpdate(deltaTime);
		update(deltaTime);
		render();
	}
}

void bbe::Application::handleUpdate(float deltaTime)
{
	_window->handleUpdate(deltaTime);

}

void bbe::Application::update(float deltaTime)
{
	_window->update(deltaTime);
}

void bbe::Application::render()
{
	_window->draw();
}

