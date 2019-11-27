#pragma once
#include "SpaceShip.h"
#include "Shot.h"
#include "Game.h"
#include "Asteroid.h"

SpaceShip::SpaceShip(int x, int y, int w, int h)
{
	Game::entities.push_back(this);

	//Set color of rect
	rect.r = 200;
	rect.g = 200;
	rect.b = 200;

	//set position and size
	rect.xPos = x;
	rect.yPos = y;
	rect.width = w;
	rect.height = h;

	//set speed
	rect.drag = drag;
	rect.speed = speed;

	//rectangle to show front Direction
	dirRect.width = w / 2;
	dirRect.height = h / 2;

	dirRect.tag = "Ship";
	dirRect.parentEntity = this;

	rect.tag = "Ship";
	rect.parentEntity = this;
}

SpaceShip::~SpaceShip()
{
}

//runs once per frame
void SpaceShip::Update()
{
	//add speed when directional input is given
	if (Game::Input()[SDL_SCANCODE_UP]) {
		rect.ySpeed -= Game::time * speed;
	}
	if (Game::Input()[SDL_SCANCODE_DOWN]) {
		rect.ySpeed += Game::time * speed;
	}
	if (Game::Input()[SDL_SCANCODE_RIGHT]) {
		rect.xSpeed += Game::time * speed;
	}
	if (Game::Input()[SDL_SCANCODE_LEFT]) {
		rect.xSpeed -= Game::time * speed;
	}

	//Shoot if cooldown has been hit and space is pressed otherwise add time to counter
	if (Game::Input()[SDL_SCANCODE_SPACE] && shotTimeOut > shootCooldown) {
		Shoot();
		shotTimeOut = 0.f;
	}
	else
		shotTimeOut += Game::time;

	//Position dirRect in direction of ship movement
	//position + padding + direction for dirRect
	dirRect.xPos = rect.xPos +
		(rect.width / 2) - (dirRect.width / 2) +
		(rect.vel.first * rect.width);

	dirRect.yPos = rect.yPos +
		(rect.height / 2) - (dirRect.width / 2) +
		(rect.vel.second * rect.height);
}

//gets called when this hits another entity/collider/rect
void SpaceShip::OnCollisionEnter(Collider* otherColl)
{
	if (otherColl->tag == "Asteroid")
	{
		Game::GameOver();
	}
}

void SpaceShip::Shoot()
{
	//instantiate new show at location
	Shot* shot = new Shot();
}
