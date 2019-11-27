#include "Game.h"

#undef main

int main()
{
	//start game
	Game* game = new Game();
	game->Init();
	
	return 0;
}