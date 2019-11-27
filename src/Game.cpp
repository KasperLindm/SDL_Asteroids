/*
Övrigt :
	Dela upp asteroiden i x delar vid kollision
	Ge skeppet 3 liv
	Adda high score
	Serialisera high score

*/

#pragma once
#include "Game.h"
#include "SpaceShip.h"
#include "Asteroid.h"
#include "Rectangle.h"#include "Shot.h"
#include <SDL_keycode.h>
#include <ctime>
#include <cassert>
#include <iostream>

SpaceShip* spaceShip;
SpaceShip* Game::MainShip;

std::vector<Entity*> Game::entities;
std::vector<Rectangle*> Game::recs;

SDL_Renderer* Game::renderer;
const Uint8* Game::input = new Uint8;
float Game::time = 0.f;
bool Game::bGameOver = false;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init()
{
	//get new random seed
	srand(std::time(NULL));

	//init window and renderer
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
	Game::renderer = SDL_CreateRenderer(window, 1, 0);

	//start game and init objects
	StartGame();

	//execute update loop
	isRunning = true;
	while (isRunning)
	{
		HandleEvents();
		DeltaTime();
		Rectangle::CalculateCollisions();
		UpdateGame();

		//bGameOver is to be set within UpdateGame()
		if (bGameOver)
			RestartGame();

		//limit framerate to aproximitelly 180fps
		if (5 > Game::time)
		{
			SDL_Delay(5 - Game::time);
		}
	}
	Clean();
}

//calculates time from last frame
int Game::DeltaTime()
{
	LAST = NOW;
	NOW = SDL_GetPerformanceCounter();
	return Game::time = ((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
}

//close window cleanly
void Game::Clean()
{
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//Handle SDL events
void Game::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			isRunning = true;
	}
}

//runs once on startup
void Game::StartGame()
{
	//reset bGameOver
	bGameOver = false;

	//Asteroids
	for (int i = 0; i < asteroidAmount; i++)
	{
		new Asteroid();
	}

	//Spaceship
	spaceShip = new SpaceShip(100.f, 100.f, 20.f, 20.f);
	MainShip = spaceShip;
}

//runs once each frame
void Game::UpdateGame()
{
	//Draw background
	SDL_SetRenderDrawColor(Game::renderer, 15, 15, 15, 255);
	SDL_RenderClear(Game::renderer);

	//TODO: fix 2, loop through entities

	//update entities
	{
		for (int i = 0; i < Game::entities.size(); i++)
		{
			if (Game::entities[i] != nullptr)
				Game::entities[i]->Update();
		}
	}

	//update recs
	{
		for (int i = 0; i < Game::recs.size(); i++)
		{
			if (Game::recs[i] != nullptr)
				Game::recs[i]->Update();
		}
	}

	//SpaceShip
	if (spaceShip != nullptr)
		spaceShip->Update();

	//present graphics in renderer
	SDL_RenderPresent(Game::renderer);
}

void Game::RestartGame()
{
	SDL_SetRenderDrawColor(Game::renderer, 20, 20, 20, 255);
	SDL_RenderClear(Game::renderer);
	SDL_RenderPresent(Game::renderer);

	//TODO: render game over screen
	entities.clear();
	recs.clear();

	//reset all stuff
	StartGame();

	SDL_Delay(1500);
}
