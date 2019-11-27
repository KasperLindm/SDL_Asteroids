#pragma once
#include "SDL.h"
#include "Entity.h"
#include <utility>
#include <string>

struct Collider;

struct Rectangle
{
public:
	Rectangle(Entity* parent = nullptr);
	~Rectangle();

	void Update();

	static void CalculateCollisions();

	std::pair<float, float> vel;
	float width = 10.f, height = 10.f;
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
public:
	Collider() {};
	std::string tag;
	Rectangle* rect;
	bool doesColl;
};