#pragma once
#include <windows.h>
#include "Entity.h"

// renderer class will create an evironment for creating windows and boxes...
// full screen black backdrop....


class Canvas
{
public:
	Canvas();
	~Canvas();
	
	void clear();
	void update();
	void render(Entity&);
	static int width;
	static int height;
	HANDLE outputHandler;
	HANDLE inputHandler;
private:
	CHAR_INFO *canvas;
};
