#include "Game.h"

#undef main

int main()
{
	//start game
	Game* game = new Game();
	game->Init();
	
	delete game;
	return 0;
}