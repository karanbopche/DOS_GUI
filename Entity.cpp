#include "Entity.h"


Entity::Entity(int width, int height)
{
	this->height = height;
	this->width = width;
	entity = (width*height) ? new CHAR_INFO[width*height] : nullptr;
}


Entity::~Entity()
{
	delete[] entity;
}

int Entity::getHeight() {
	return this->height;
}

int Entity::getWidth() {
	return this->width;
}

void Entity::move(int x, int y) {
	this->x = x;
	this->y = y;
}