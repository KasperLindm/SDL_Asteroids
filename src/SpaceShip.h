#pragma once
#include "SDL.h"
#include "Entity.h"
#include "Rectangle.h"

struct SpaceShip : Entity
{
	SpaceShip(int x, int y, int w, int h);

	virtual void Update();

	virtual void OnCollisionEnter(Collider* otherColl);

	inline void Shoot();

	static SpaceShip* MainShip;
	Rectangle rect;

private:
	Rectangle dirRect;

	float drag = 0.01f;
	float speed = 2.f;

	float shootCooldown = 1.f;
	float shotTimeOut = 0.f;
};
