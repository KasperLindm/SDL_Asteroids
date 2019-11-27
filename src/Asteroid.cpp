#pragma once
#include "Asteroid.h"
#include "Game.h"
#include <iostream>

Asteroid::Asteroid()
{
	Game::entities.push_back(this);

	//set colors of rectangle
	rect.r = 10;
	rect.g = 250;
	rect.b = 250;

	//init random position and velocity
	rect.xPos = Game::RandomFloat(0.f, 640.f);
	rect.yPos = Game::RandomFloat(0.f, 480.f);
	rect.width = rectWidth;
	rect.height = rectHeigth;

	rect.speed = speed;
	rect.xSpeed = Game::RandomFloat(-speed, speed);
	rect.ySpeed = Game::RandomFloat(-speed, speed);

	rect.tag = "Asteroid";
	rect.parentEntity = this;
}

Asteroid::~Asteroid()
{
}

//runs once per frame
void Asteroid::Update()
{
}
