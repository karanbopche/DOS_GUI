#include <iostream>
#include "canvas.h"
#include "Window.h"

using namespace std;

Canvas canvas;

int main() {
	Window myWindow("karan bopche", 80, 40);
	myWindow.move(10, 7);
	canvas.clear();
	canvas.render(myWindow);
	canvas.update();
	cin.get();
	return 0;
}
