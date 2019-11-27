#pragma once
#include <iostream>
struct Collider;

class Entity
{
public:
	Entity() {	};
	virtual void Update() { std::cout << "parent: update()" << std::endl; };
	virtual void OnCollisionEnter(Collider* otherColl) {};
};
