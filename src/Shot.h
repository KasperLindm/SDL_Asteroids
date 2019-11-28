#pragma once
#include "Entity.h"
#include "Rectangle.h"

class Shot : public Entity
{
public:
	Shot();
	virtual void OnCollisionEnter(Collider* coll);

private:
	Rectangle rect;
	float shotSpeed = 1.f;
	float shotWidth = 15.f;
	float shotHeigth = 15.f;
};
