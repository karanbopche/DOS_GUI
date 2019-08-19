#include "canvas.h"

int Canvas::width;
int Canvas::height;

// helper define for index of canvas....
#define INDEX(row,col) (row)*Canvas::width+(col)

Canvas::Canvas()
{
	outputHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	inputHandler = GetStdHandle(STD_INPUT_HANDLE);
	COORD size;
	//go full screen....
	SetConsoleDisplayMode(outputHandler, CONSOLE_FULLSCREEN_MODE, &size);
	size = GetLargestConsoleWindowSize(outputHandler);
	Canvas::width = size.X;
	Canvas::height = size.Y;
	canvas = new CHAR_INFO[width*height];
	
	SetConsoleScreenBufferSize(outputHandler, size);
}

Canvas::~Canvas()
{
	delete[] canvas;
}

void Canvas::render(Entity& obj) {
	// if object outside of canvas the return...
	if (obj.x > Canvas::width || obj.y > Canvas::height)
		return;
	if (obj.x + obj.width < 0 || obj.y + obj.height < 0)
		return;

	for (int row = 0; row < obj.height; row++) {
		int y = row + obj.y;
		if (y < 0 || y>Canvas::height)
			continue;
		for (int col = 0; col < obj.width; col++) {
			int x = col + obj.x;
			if (x<0 || x> Canvas::width)
				continue;
			canvas[INDEX(y, x)] = obj.entity[row*obj.width + col];
		}
	}
}

void Canvas::update() {
	SMALL_RECT writeArea = { 0, 0, Canvas::width - 1, Canvas::height - 1 };
	COORD bufferSize = { Canvas::width, Canvas::height };
	WriteConsoleOutput(outputHandler, canvas, bufferSize, { 0, 0 }, &writeArea);
}

void Canvas::clear() {
	// clear the buffer..
	memset(canvas, 0, Canvas::width*Canvas::height*sizeof(Canvas::width));
	
	/*	int size = Canvas::height*Canvas::width;

	for (int i = 0; i < size; i++) {
		canvas[i].Char.AsciiChar = 0;
		canvas[i].Attributes = 0;
	}*/
}