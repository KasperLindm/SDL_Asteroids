#include "Rectangle.h"
#include "Game.h"
#include "Entity.h"

Rectangle::Rectangle(Entity* parent)
{
	Game::recs.push_back(this);
	parentEntity = parent;

	//set position and size
	rectangle.x = xPos;
	rectangle.y = yPos;
	rectangle.h = height;
	rectangle.w = width;
}

//runs once per frame
void Rectangle::Update()
{
	//update size
	rectangle.h = height;
	rectangle.w = width;

	//friction/Drag
	xSpeed *= 1.f - drag;
	ySpeed *= 1.f - drag;

	//update position
	xPos += xSpeed * speed;
	yPos += ySpeed * speed;
	rectangle.x = xPos;
	rectangle.y = yPos;

	//calculate velocity
	vel = Game::Normalize(xSpeed, ySpeed);

	//render square
	SDL_SetRenderDrawColor(Game::renderer, r, g, b, 255);
	SDL_RenderFillRect(Game::renderer, &rectangle);
}

//TODO: fix 1, collision detection

//check if two rectangles collide and call OnCollisionEnter() respectively
void Rectangle::CalculateCollisions()
{
	//declare rectangles to compare
	Rectangle* it;
	Rectangle* jt;

	//loop through all possible collisions once
	for (int i = 0; i < Game::recs.size(); i++)
	{
		it = Game::recs[i];
		for (int j = 0; j < Game::recs.size(); j++)
		{
			jt = Game::recs[j];

			//continue if comparing with self , null or if there is a parent-entity missing 
			if (jt == it ||
				jt == nullptr ||
				it == nullptr ||
			it->parentEntity == nullptr ||
				jt->parentEntity == nullptr)
				continue;

			//if the rectangles overlap
			if ((it->xPos + it->width > jt->xPos) &&
				(it->xPos < jt->xPos + jt->width) &&
				(it->yPos + it->height > jt->yPos) &&
				(it->yPos < jt->yPos + jt->height))
			{
				//create first collider
				Collider coll{ it->tag,it, true };

				//create other collider
				Collider otherColl{ jt->tag,jt, true };

				jt->parentEntity->OnCollisionEnter(&coll);
				it->parentEntity->OnCollisionEnter(&otherColl);
			}
		}
	}
}
