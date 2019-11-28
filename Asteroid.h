#pragma once
#include "SDL.h"
#include "Entity.h"
#include "Rectangle.h"

class Asteroid : public Entity
{
public:
	Asteroid();

private:
	Rectangle rect;

	float speed = 0.35f;
	float rectWidth = 30.f;
	float rectHeigth = 30.f;
};
