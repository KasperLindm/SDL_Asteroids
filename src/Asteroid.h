#pragma once
#include "SDL.h"
#include "Rectangle.h"
#include "Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid();
	~Asteroid();

	void Update();

private:
	Rectangle rect;

	float speed = 0.35f;
	float rectWidth = 30.f;
	float rectHeigth = 30.f;
};
