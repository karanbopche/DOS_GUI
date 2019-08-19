#pragma once
#include <windows.h>
#include <vector>

class Entity
{
public:
	Entity(int width, int height);
	~Entity();
	int getWidth();
	int getHeight();
	void move(int x, int y);
	bool bindChild(Entity* child);
	// for rendering the entity on cavas....
	friend class Canvas;
protected:
	CHAR_INFO *entity;
	std::vector<Entity*> childs;
	int width;
	int height;
	int x, y;
};

