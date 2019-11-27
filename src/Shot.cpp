#pragma once
#include "Shot.h"
#include "Game.h"

Shot::Shot()
{
	Game::entities.push_back(this);

	//set color of rect
	rect.r = 255;
	rect.g = 100;
	rect.b = 100;

	//set position and size
	rect.xPos = Game::MainShip->rect.xPos;
	rect.yPos = Game::MainShip->rect.yPos;
	rect.width = shotWidth;
	rect.height = shotHeigth;

	//calculate direction of 
	std::pair<float, float> dir = Game::Normalize(Game::MainShip->rect.xSpeed, Game::MainShip->rect.ySpeed);

	//set speed
	rect.speed = shotSpeed;
	rect.xSpeed = dir.first;
	rect.ySpeed = dir.second;

	rect.tag = "Shot";
	rect.parentEntity = this;
}

Shot::~Shot()
{
}

//runs once per frame
void Shot::Update()
{
}

//gets called when this hits another entity/collider/rect
void Shot::OnCollisionEnter(Collider* coll)
{
	if (coll->tag == ("Asteroid"))
	{
		rect.r = 255;
		rect.g = 0;
		rect.b = 0;

		Game::reverseRemoveFromEntityVector(&Game::entities, this);
		Game::reverseRemoveFromEntityVector(&Game::entities, coll->rect->parentEntity);

		Game::reverseRemoveFromRectVector(&Game::recs, &rect);
		Game::reverseRemoveFromRectVector(&Game::recs, coll->rect);
	}
}
