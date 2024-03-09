#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "Window.h"

namespace bbe
{

class Application 
{
public:
	Application();
	~Application();

	void initialize();

	void run();

	void handleUpdate(float deltaTime);
	void update(float deltaTime);
	void render();

private:
	bool _isRunning = false;
	
	Window* _window;
	
	float _lastFrameTime;
	float _currentFrameTime;
};

}

#endif // !_APPLICATION_H_
