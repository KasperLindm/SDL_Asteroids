#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include "Rectangle.h"

struct SpaceShip;
class Entity;

struct Game
{
	int DeltaTime();

	void Init();

	void Clean();

	void HandleEvents();

	void StartGame();

	void UpdateGame();

	void RestartGame();

	//statics
	static void GameOver()
	{
		bGameOver = true;
	}

	static const Uint8* Input()
	{
		input = SDL_GetKeyboardState(NULL);
		return input;
	}

	//gets a random float between min and max
	static float RandomFloat(float min, float max)
	{
		return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
	}

	static std::pair<float, float> Normalize(float x, float y)
	{
		float length = (x * x) + (y * y);

		float xFloat = (x / sqrt(length));
		float yFloat = (y / sqrt(length));

		return std::pair<float, float>(xFloat, yFloat);
	}

	static void reverseRemoveFromEntityVector(std::vector<Entity*>* vector, Entity* ent)
	{
		for (int i = vector->size() - 1; i >= 0; i--)
		{
			if (vector->at(i) != ent)
				continue;

			auto it = vector->begin() + i;
			//vector->erase(it);
			delete* it;
			return;
		}
	}

	static void reverseRemoveFromRectVector(std::vector<Rectangle*>* vector, Rectangle* ent)
	{
		for (int i = vector->size() - 1; i >= 0; i--)
		{
			if (vector->at(i) != ent)
				continue;

			auto it = vector->begin() + i;
			//vector->erase(it);
			delete* it;
			return;
		}
	}

	static bool bGameOver;

	static SDL_Renderer* renderer;
	static const Uint8* input;
	static float time;

	//entities
	static std::vector<Entity*> entities;
	static std::vector<Rectangle*> recs;
	static SpaceShip* MainShip;

private:

	bool isRunning = false;

	//window
	SDL_Window* window = nullptr;
	int windowWidth = 640;
	int	windowHeight = 480;

	//time
	Uint64 NOW = 0, LAST = 0;

	//asteroids
	int asteroidAmount = 15;
};
