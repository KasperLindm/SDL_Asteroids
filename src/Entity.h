#pragma once
#include <iostream>
struct Collider;

class Entity
{
public:
	Entity() {	};
	virtual ~Entity() { 
		printf("Dude");
	};

	virtual void Update() {  };
	virtual void OnCollisionEnter(Collider* otherColl) {};
};
