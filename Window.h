#pragma once
#include "Entity.h"

class Window : public Entity
{
public:
	Window(const char* WindowName=nullptr, int width=40, int height=20);
	~Window();

protected:
	void createWindowBox();

private:
	const char* windowTitle;
};

