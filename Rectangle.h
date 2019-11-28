#pragma once
#include "SDL.h"
#include <utility>
#include <string>

struct Collider;
class Entity;

class Rectangle
{
public:
	Rectangle(Entity* parent = nullptr);

	void Update();

	static void CalculateCollisions();

	std::pair<float, float> vel;
	int width = 10, height = 10;
	float xSpeed = 0.f, ySpeed = 0.f;
	float xPos = 0.f, yPos = 0.f;
	float speed = 1.f;
	float drag = 0.f;

	std::string tag = "";

	int r = 200, g = 200, b = 200;

	Entity* parentEntity = nullptr;

private:
	SDL_Rect rectangle;
};

struct Collider
{
	std::string tag;
	Rectangle* rect;
	bool doesColl;
};