#pragma once
#include "SDL.h"
#include "Rectangle.h"
#include "Entity.h"

class SpaceShip : public Entity
{
public:
	SpaceShip(int x, int y, int w, int h);
	~SpaceShip();

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
