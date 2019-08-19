#include "Window.h"

Window::Window(const char* windowName, int width, int height) : Entity(width, height)
{
	windowTitle = (windowName); //? windowName : "My Window";
	createWindowBox();
}

void Window::createWindowBox() {
	const char* title = windowTitle;
	//clear buffer first.....
	memset(entity, 0, sizeof(CHAR_INFO)*width*height);
	
	// draw title bar.....
	entity[1].Attributes = FOREGROUND_RED | BACKGROUND_BLUE;	// first column empty....
	entity[1].Char.AsciiChar = ' ';
	for (int i = 2; i < width; i++) {
		entity[i].Attributes = FOREGROUND_RED | BACKGROUND_BLUE;
		if (*title)
			entity[i].Char.AsciiChar = *title++;
		else
			entity[i].Char.AsciiChar = ' ';
	}
	int size = width * height;
	// left edge....
	for (int i = 0; i < size; i+=width) {
		entity[i].Attributes = FOREGROUND_RED;
		entity[i].Char.AsciiChar = '|';
	}
	// right edge....
	for (int i = width-1; i <size; i+=width) {
		entity[i].Attributes = FOREGROUND_RED;
		entity[i].Char.AsciiChar = '|';
	}
	// bottom edge.....
	for (int i = (height - 1)*width; i < size; i++) {
		entity[i].Attributes = FOREGROUND_RED;
		entity[i].Char.AsciiChar = '-';
	}
}


Window::~Window()
{

}
